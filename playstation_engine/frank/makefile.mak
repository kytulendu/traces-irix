CC = ccpsx -g -O2 -Xo$80010000


.c.obj:
	$(CC) -c $*.C


mdec:
	psymake mdec.cpe
	run mdec
	testmess

movie:
   psymake movie.cpe
   run movie
   testmess

test:
	$(CC) test.c -otest.cpe,test.sym
	
mdec.cpe: tuto3.c
	$(CC) tuto3.c -omdec.cpe,mdec.sym

movie.cpe: tuto4.obj moviet.obj psxutil.obj makefile.mak movie.lnk
	psylink /m /c /g @movie.lnk,movie.cpe,movie.sym

movie.exe: movie.cpe movie.h
	cpe2x /CE movie.cpe

tuto2: mdec_bs.obj
	$(CC) tuto6.c mdec_bs.obj  -otuto2.cpe,tuto6.sym 
	run tuto2
