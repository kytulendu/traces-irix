#include "psxutil.h"
#include "file.h"
#include <ctype.h>
#include <strings.h>

extern char str[128];
char tmpname[128];

volatile int _line = 0;
volatile char * _file = 0;

ListBase _dir_list = {0, 0}, * dir_list = & _dir_list;

typedef struct{
	void * next, * prev;
	char name[128];
	ListBase filelist;
}CD_Dir;

typedef struct{
	void * next, * prev;
	char name[16];
	ulong start;
	ulong bytesize;
}CD_File;

char * cd_pc_name(char * name)
{
	int i, slen;
	
	tmpname[0] = 0;
	tmpname[1] = 0;

	if (name) {	
		if (name[0] == '.') {
			if (name[1] == '/') name += 2;
		}
		
		if (is_cd == 0) {
			// strcpy(tmpname, "sim:");
			// strcat(tmpname, name);
			
			strcpy(tmpname, name);
		} else {
			if ((name[0] != '/') && (name[0] != '\\')) strcat(tmpname, "\\");
			strcat(tmpname, name);
			
			
			// forward slash moet backward slash worden
			// lowercase moet uppercase worden
	
				slen = strlen(tmpname);
				
				for (i = slen - 1; i >= 0; i--) {
					char c = tmpname[i];
					
					if (c == '/') tmpname[i] = '\\';
					else if (c >= 'a' && c <= 'z') tmpname[i] = c + 'A' - 'a';
				}
			
			// if its not a directory cat ;1 at the end
			
				if (tmpname[slen - 1] != '\\') strcat(tmpname, ";1");
		}
	}
	
	return(tmpname);
}


long my_open(char * name, ulong flag)
{
	long fd, i, error;
	CdlFILE _cdfile, *cdfile = &_cdfile;
	C_File * c_file;
	CD_File * cd_file = 0;
	CD_Dir * cd_dir;
	
	char * newname;
	int org_cd = is_cd;
	
LINE
		
	newname = cd_pc_name(name);

	if (is_cd == 0) {
		fd = PCopen(newname, 0, 0);
		return(fd);
		
		if (flag == O_RDONLY) return(PCopen(newname, 0, 0));
		if (flag == O_WRONLY) return(PCopen(newname, 1, 0));
		// must be O_RDWR
		return(PCopen(newname, 2, 0));
	}
	
	
	if (dir_list->first) {
		// is_cd = TRUE;
		
			// cd_pc_name(name);
			newname = strrchr(tmpname, '\\');
			if (newname) {
				newname[1] = 0;
				
				cd_dir = dir_list->first;
				while (cd_dir) {
					if (strcmp(cd_dir->name, tmpname) == 0) break;
					cd_dir = cd_dir->next;
				}
				
				if (cd_dir) {
					cd_pc_name(name);
					newname = strrchr(tmpname, '\\');
					newname++;
					
					cd_file = cd_dir->filelist.first;
					while(cd_file) {
						if (strcmp(cd_file->name, newname) == 0) break;
						cd_file = cd_file->next;
					}
					
				}
			}
			
			if (cd_file == 0) {
				sprintf(str, "Can't find file for %s\n", name);
				guru(str);
			}
			
		// is_cd = org_cd;
	}

	if (cd_file) {
		c_file = CLN(C_File);
		c_file->start = cd_file->start;
		c_file->bytesize = cd_file->bytesize;
		strcpy(c_file->name, cd_file->name);
	} else {
		// zet eventueel streaming stop
			c_file = active_c_file;
			if (c_file)	streaming_stop();
		
		// zoeken		
			error = (CdSearchFile(cdfile, newname) == 0);
		
		// streamen weer starten
			if (c_file) {
				urgent_c_file = c_file;
				streaming_start();
			}
		
		// verdere afhandeling
			if (error) {
				guru(newname);
				return(-1);
			}
			
			c_file = CLN(C_File);
			c_file->start = CdPosToInt(&cdfile->pos);
			c_file->bytesize = cdfile->size;
	}
	
	c_file->maxsector = c_file->lastsector = (c_file->bytesize - 1) >> 11;
	
	return((long) c_file);
}



long my_lseek(long fd, long pos, long flag)
{
	C_File * c_file;
	long oldseek;
LINE
	if (is_cd == 0) return(PClseek(fd, pos, flag));
	
	if (fd == -1) return (-1);
	
	c_file = (C_File *) fd;
	oldseek = c_file->byteseek;
	
	switch (flag){
		case SEEK_SET:
			c_file->byteseek = pos;
			break;
		case SEEK_CUR:
			c_file->byteseek += pos;
			break;
		case SEEK_END:
			c_file->byteseek = c_file->bytesize - pos;
			break;
	}
	
	if (c_file->byteseek < 0) c_file->byteseek = 0;
	if (c_file->byteseek >= c_file->bytesize) c_file->byteseek = c_file->bytesize;
	
	// return(oldseek);
	
	// niet compatible met silicon
	return(c_file->byteseek);
}



long my_read(int fd, void * buf, long size)
{
	int start, end, sect, i, index;
	C_File * c_file;

LINE
	if (is_cd == 0) return(PCread(fd, buf, size));
	if (fd == -1) return (-1);

	c_file = (C_File *) fd;

	if (c_file->byteseek + size > c_file->bytesize) {
		size = c_file->bytesize - c_file->byteseek;
		guru("my_read: size to big");
	}

	if (size <= 0) {
		if (size == 0) return(0);
		guru("trying to read size < 0");
		return(-1);
	}

	// calc
		start = c_file->byteseek >> 11;
		end = (c_file->byteseek + size - 1) >> 11;

		if (end > c_file->maxsector) end = c_file->maxsector;

		if (end > c_file->lastsector) {
			guru("end > c_file->lastsector: adjusting");
			c_file->lastsector = end;
		}
		
		if (start < c_file->firstsector) {
			guru("start < c_file->firstsector: adjusting");
			c_file->firstsector = start;
		}
		
		sect = end - start + 1;

	if (cdcache == 0) {	
		CdlLOC	cdloc;
		char * tbuf;
		unsigned char mode = CdlModeSpeed;

		// seek
			CdIntToPos (c_file->start + (c_file->byteseek >> 11), &cdloc);
			CdControl(CdlSetloc, (u_char *) &cdloc, 0);

		// malloc
			tbuf = mallocN(sect << 11, "my_read");
			if (tbuf== 0) return (-1);

		// read
			if (CdRead(sect, (void *) tbuf, CdlModeSpeed) == 0) {
				guru("cdread"); size = -1;
			} else {
				// guru("read started");
				while ((sect = CdReadSync(1, 0)) > 0) {
					// sprintf(str, "CdReadSync %d\n", sect);
					// guru(str);
				}
				if (sect < 0) {
					guru("cdreadSync");
					size = -1;
				}
			}

		// memcpy
			if (size > 0) {
				memcpy(buf, tbuf + (c_file->byteseek & 2047), size);
				c_file->byteseek += size;
			}
			freeN(tbuf);

	} else {
		u_short c_full, c_free;
		int first, oldseek, len, index, remaining;
		uchar * from, * to;

		if (c_file->index == 0) {
			guru("Can't mix stream / non-stream files !");
			return(-1);
		}

		// free cache blocks before starting point

			for (i = 0; i < start; i++) {
				if (index = c_file->index[i]) {
					c_file->index[i] = 0;
					c_in_use[index] = 0; c_freed++;
				}
			}

			
		// look if data is cached

/*
	Als een file aan het eind al voor een groot gedeelte gecached
	is, en er wordt een plaatje aan het begin gelezen,  wordt er
	maar net genoeg ruimte voor dat ene plaatje vrijgemaakt. Daarna
	stopt de caching weer direct. Oplossing : grotere ruimte
	vrijmaken
*/

			do {
LINE
				sect = 0;

				for (i = end; i >= start; i--) {
					if (c_file->index[i] == 0) {
						sect++;
						first = i;
					}
				}

LINE
				if (sect) {
					// not all data is present...
					// is the cache full ?
					
					c_full = c_used - c_freed;
					c_free = 256 - c_full;
					
					if (c_free < sect) {
						// not eneough space to hold the data
						// solution: free from the end of this file
						for (i = c_file->maxsector; i > end ; i--) {
LINE
							if (index = c_file->index[i]) {
								c_file->index[i] = 0;
								c_in_use[index] = 0;
								c_freed++;
								c_free++;
								if (c_free >= sect) break;
							}
						}
						
						if (c_free < sect) {
							guru("Cache is full, what now ?");
							return(-1);
						}
					}
					
LINE
					if ((c_file->busy == FALSE) || (c_file->sectorseek < (first - 10)) || (c_file->sectorseek > (first + 1))) {
						c_file->sectorseek = first;
					}
					
					oldseek = c_file->sectorseek;
					
					if (c_file->busy == FALSE) urgent_c_file = c_file;
					
LINE
					// restart streaming if it was stopped
						streaming_start();
						
					// wait for things to happen
						while (c_file->busy == FALSE) {
							LINE
						}
						while (c_file->sectorseek == oldseek && c_file->busy == TRUE) {
							LINE
						}
				}
			} while (sect);
			
LINE
			// alle data is nu voorhanden
			
			to = buf;
			remaining = size;

			for (i = start; i <= end ; i++)
			{
				index = c_file->index[i];
				from = (uchar *) & cdcache[index].data;
				len = 2048;
				len -= c_file->byteseek & 0x7ff;
				from += c_file->byteseek & 0x7ff;
				if (len > remaining) len = remaining;
				memcpy(to, from, len);
				to += len;
				c_file->byteseek += len;
				remaining -= len;
			}
	}
LINE

	return (size);
}


long my_close(long fd)
{
	C_File * c_file;

LINE
	if (is_cd == 0) {
		return(PCclose(fd));
	}
	
	if (fd == -1) return (-1);
	if (fd == 0) return (-1);
	
	c_file = (C_File *) fd;

	if (c_file->index) stream_remove(c_file);

	freeN(c_file);
	
	return(fd);
}

int cd_tonext(char *str)
{
	int len= 0;
	
	while(*str!=' ' && isgraph( *str ) ) {
		str++;
		len++;
		if(len>256) return(len);
	}
	
	while(*str==' ' || isgraph( *str )==0 ) {
		str[0]= 0;
		str++;
		len++;
		if(len>256) return(len);
	}
	
	return(len);
}

long cd_init()
{
	C_File * c_file;
	CdlFILE _cdfile, *cdfile = &_cdfile;
	int fd, size, len, slen, org_cd = is_cd;
	uchar * buf, * pnt;
	char * name;
	CD_Dir * cd_dir;
	CD_File * cd_file;
	
	// if (is_cd == 0) return(-1);
	
	if (dir_list->first) return (1);
	
	// open file.lst en anders auto.lst

		fd = open("file.lst", O_RDONLY);
		if (fd == -1) fd = open("auto.lst", O_RDONLY);
		if (fd == -1) {
			guru("no file.lst or auto.lst found");
			return(-1);
		}
	
		if (is_cd) {
			c_file = (C_File *) fd;
		} else {
			c_file = CLN(C_File);
			c_file->bytesize = lseek(fd, 0, SEEK_END);
			lseek(fd, 0, 0);
		}

	// lees file in en maak een index van alle files
	
		buf = mallocN(c_file->bytesize, "cd_init");
		if (buf) {
			size = c_file->bytesize;
			if (read(fd, buf, size) == size) {
				pnt = buf;
				
				is_cd = TRUE;

				cd_dir = CLN(CD_Dir);
				strcpy(cd_dir->name, cd_pc_name("/"));
				addtail(dir_list, cd_dir);
				
				while (size > 1) {
					len = cd_tonext(pnt);
					slen = strlen(pnt);
					if (slen) {
						if (pnt[slen - 1] == ':') {
							// newdir
								pnt[slen - 1] = '/';
								cd_dir = CLN(CD_Dir);
								name = cd_pc_name(pnt);
								strcpy(cd_dir->name, name);
								addtail(dir_list, cd_dir);
								sprintf(str, "newdir: %s\n", cd_dir->name);
								// guru(str);
						} else if (pnt[slen - 1] == '/') {
							// skipping directories
								sprintf(str, "skipping %s\n", pnt);
								// guru(str);
						} else {
							// regular file
								cd_file = CLN(CD_File);
								name = cd_pc_name(pnt);
								strcpy(cd_file->name, name + 1);
								addtail(&cd_dir->filelist, cd_file);
								sprintf(str, "  adding %s to %s\n", cd_file->name, cd_dir->name);
								// guru(str);
							// get data
								strcpy(tmpname, cd_dir->name);
								strcat(tmpname, cd_file->name);
								
								if (is_cd == org_cd) {
									if (CdSearchFile(cdfile, tmpname) == 0) {
										guru(tmpname);
									} else {
										cd_file->start = CdPosToInt(&cdfile->pos);
										cd_file->bytesize = cdfile->size;
									}
								}

						}
					}
					pnt += len;
					size -= len;
				}
				
				is_cd = org_cd;
				
			} else guru("Error reading auto.list / file.list");
			
			freeN(buf);
		}

		close(fd);
		if (is_cd == 0) freeN(c_file);

	return(0);
}


long cd_exit()
{
	ListBase * file_list;
	CD_Dir * cd_dir;
	CD_File * cd_file;
	
	
	// if (is_cd == 0) return(-1);
	
	while (cd_dir = dir_list->first) {
		remlink(dir_list, cd_dir);

		file_list = & cd_dir->filelist;
		while (cd_file = file_list->first) {
			remlink(file_list, cd_file);
			freeN(cd_file);
		}
		
		freeN(cd_dir);
	}
	
	return(0);
}
