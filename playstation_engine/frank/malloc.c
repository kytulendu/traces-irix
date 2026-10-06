#include <malloc.h>
#include "psxutil.h"

extern void *malloc2 (size_t);

void * malloc (size_t size) {
	static short first = TRUE;
	
	//if (first) guru("in malloc");
	first = FALSE;
	return (malloc2 (size));
}

void * calloc (size_t size1, size_t size2) {
	static short first = TRUE;
	
	//if (first) guru("in calloc");
	first = FALSE;
	return (calloc2 (size1, size2));
}

void * realloc (void * pnt, size_t size)
{
	static short first = TRUE;
	
	//if (first) guru("in realloc");
	first = FALSE;
	return(realloc2 (pnt, size));
}

void InitHeap (unsigned long * start, unsigned long size)
{
	static short first = TRUE;
	char string[128];
	extern int MallocSize;
	extern void * MallocStart;
	
		sprintf(string, "in InitHeap (0x%x %d kB)", start, (size + 512) >> 10);
		guru(string);

	MallocStart = start;
	MallocSize = size;
	InitHeap2(start, size);
}

void free (void * pnt)
{
	static short first = TRUE;
	
	//if (first) guru("in free");
	first = FALSE;
	free2(pnt);
}

