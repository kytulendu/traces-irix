#include "fbmm.h"
#include "../ton/psxutil.h"
#include "../ton/psxgraph.h"



struct FrameBufferAlloc fbA[MAXFBA];
int	   fbAcnt = -1;

int fb_free(int bf_ptr)
{
	if (fbA[bf_ptr].iu == FB_CLEAR){
		printf("Double free fp_ptr (%i %s)\n", bf_ptr, fbA[bf_ptr].name);
		return(-1);
	}
	fbA[bf_ptr].iu = FB_CLEAR;
					
	return(0);
}
int fb_free_all(short permission)
{
	int i;
	for (i=0; i<MAXFBA; i++){
		if ( (fbA[i].iu & permission) == permission ) fb_free(i);
	}
}

int fb_add(int orgx, int orgy, int sizx, int sizy, char *name)
{
	int i, c;
	
	if (fbAcnt == -1){
		/* FirstTime so Init */
		for (i=0; i<MAXFBA; i++){
			fbA[i].iu = FB_CLEAR;
		}
		fbAcnt = 0; 
	}
	c = i = fbAcnt;
	while (fbA[i].iu != FB_CLEAR) { 
		i++; 
		if (i == MAXFBA) i = 0;
		if (i == c) return(-1);
	}
	
	if (strlen(name) > 15) { name[14] = 0; }
	fbA[i].sx = orgx;
	fbA[i].sy = orgy;
	fbA[i].ex = orgx + sizx-1;
	fbA[i].ey = orgy + sizy-1;
	fbA[i].iu = FB_ADD;
	strcpy(fbA[i].name, name);
	fbAcnt = i;
	return(i);
}

int	does_it_fit(int sx, int sy,  int ex, int ey)
{
	int i, fsx, fsy, fex, fey, bits =0; 
	
	for (i=0; i<MAXFBA; i++){
		if (fbA[i].iu != FB_CLEAR){
			fsx = fbA[i].sx;
			fsy = fbA[i].sy;
			fex = fbA[i].ex;
			fey = fbA[i].ey;
		
			if ( (sx >=fsx) && (ex <=fex) && 
			     (sy >=fsy) && (ey <=fey) ) return(15);
			
			if ( (sx >=fsx) && (sx < fex) ){
				if ( (sy >=fsy) && (sy <=fey) ) return( 9);
				if ( (ey >=fsy) && (ey <=fey) ) return(12);
				if ( (sy < fsy) && (ey >=fey) ) return( 8);
			} 
			if ( (ex >=fsx) && (ex <=fex) ){
				if ( (sy >=fsy) && (sy <=fey) ) return( 3);
				if ( (ey >=fsy) && (ey <=fey) ) return( 6);
				if ( (sy < fsy) && (ey > fey) ) return( 2);
			}
			
			if ( (sx <fsx) && (ex >fex) ) {
				if ( (sy >=fsy) && (sy <=fey) ) return( 1);
				if ( (ey >=fsy) && (ey <=fey) ) return( 4);
			}
		}
	}
	return(0);
}

int fb_alloc(int *orgx, int *orgy, int sizx, int sizy, char *name)
{
	int i, c, bits;
	int xb, yb;
	int sx, sy, ex, ey;
	
	if (fbAcnt == -1){
		/* FirstTime so Init */
		for (i=0; i<MAXFBA; i++){
			fbA[i].iu = FB_CLEAR;
		}
		fbAcnt = 0;
	}
	c = i = fbAcnt; 
 
	
	if (sizy > 256) return(-3); 

    
	while (fbA[i].iu != FB_CLEAR) { 
		i++; 
		if (i == MAXFBA) i = 0;
		if (i == c) return(-2);
	}
	if (strlen(name) > 15) name[14] = 0;
	fbAcnt = i; 
	
	sizx = ((sizx + 63) / 64);
	sizx = sizx * 64;
	
	for (yb=256; yb>=0; yb-=256){
		for (xb=0;  xb<1024; xb+=64){	
			sx = xb;
			for (sy = yb + 256 - sizy; sy >= yb; sy--){ 
				
				bits = does_it_fit(sx, sy, sx+sizx-1, sy+sizy-1);
				
				if (bits == 0) { 
					*orgx = sx;
					*orgy = sy;
					fbA[i].sx = sx;
					fbA[i].sy = sy;
					fbA[i].ex = sx + sizx-1;
					fbA[i].ey = sy + sizy-1;
					fbA[i].iu = FB_ALLOC;
					strcpy(fbA[i].name, name);
					return(i);
				}
			}
		}
	}
	
	return(-1);
}

void dev_print_fba_block()
{
	int i;
	
	for (i=0; i<MAXFBA; i++){
		if (fbA[i].iu != FB_CLEAR){
			printf("block nr%3i %16s type:%i sx:%3i sy:%3i  ex:%3i ey:%3i \n", 
			i, fbA[i].name, fbA[i].iu , fbA[i].sx , fbA[i].sy , fbA[i].ex , fbA[i].ey);
		}
	}
}

