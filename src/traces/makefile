# Makefile for traces
#
# SGI IRIX 5.3 with IDO
#

# C compiler
CC=cc

# Include directory
INCLUDES= -I. -I../include

# C compiler options
CFLAGS= -O2 -mips2 $(INCLUDES)
CFLAGS4000= -O2 -mips2 $(INCLUDES)
CFLAGSG= -g -mips2 $(INCLUDES)

# To link any special libraries, add the necessary -l commands here.
# NOTE: UNDER IRIX 5.2 THE -lfastm OPTION MAY ONLY BE IN A FEW PLACES, SEE LDLIBS2
LDLIBS= -lgl -lX11 -lfm -limbuf -lmpc -lmalloc -lm -limage -lmovie -ldmedia -lcl -lawareaudio -laudio

LDLIBSt= -lfm -lgl -lX11 -limbuf -lm -limage -lmpc -lmalloc

LDLIBS2 = -lmovie -lfm -lgl -lX11 -limbuf -lm -limage -ldmedia -lcl -lawareaudio -laudio -lc -lmalloc -lfastm
LDLIBS4000 = -lm -lfastm -lfm -lgl -limbuf -lc -lmalloc

OBJECT1 = add.o edit.o verdit.o view.o draw.o spline.o toets.o traces.o code.o toolbox.o anim.o files.o cyber.o iges.o
OBJECT2 = Button.o
OBJECT3 = fitcurves.o GGVecLib.o
OBJECT4 = arith.o noise.o
OBJECT5 = ray.o initrender.o zbuf.o render.o textu.o shadbuf.o effect.o
OBJECT6 = isect.o trabuts.o font.o nurb.o displist.o psfont.o exotic.o
OBJECT7 = calcika.o editika.o

BINDIR=../../bin-irix-mips2

default all: psfont.o traces

.c.o:
	$(CC) $(CFLAGS) -float -cckr -c $<

psfont.o:
	$(CC) $(CFLAGS) -float -c $<

traces: $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) ../imbuf/libimbuf.a
	cd .. ; make util.o; make storage.o; cd traces
#	$(CC) $(CFLAGS) $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) ../storage.o ../util.o $(LDLIBS2) -o $(BINDIR)/traces
	$(CC) $(CFLAGS) $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) ../storage.o ../util.o $(LDLIBS4000) -o $(BINDIR)/traces
#	if (-x /usr/people/trace/traces_new) safemv traces_new traces &
#	if (-x /usr/people/trace/traces) /bin/su - root -c "chown root /usr/people/trace/traces ; chmod +s /usr/people/trace/traces"

#traces4000: $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) ../imbuf/libimbuf.a
#	$(CC) $(CFLAGS4000) $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) ../storage.o ../util.o $(LDLIBS4000) -o $(BINDIR)/traces4000
#	if (-x /usr/people/trace/traces) /bin/su - root -c "chown root /usr/people/trace/traces4000 ; chmod +s /usr/people/trace/traces4000"

tracesg: $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) ../imbuf/libimbuf.a
	cd .. ; make util.o; make storage.o; cd traces
	$(CC) $(CFLAGSG) $(OBJECT1) $(OBJECT2) $(OBJECT3) $(OBJECT4) $(OBJECT5) $(OBJECT6) $(OBJECT7) ../storage.o ../util.o $(LDLIBS2) -o $(BINDIR)/tracesg

# this not able to link yet
#brender: $(OBJECT5) brender.o
#	$(CC) -O2 -Wo,"-loopunroll 0" brender.o $(OBJECT4) $(OBJECT5) ../storage.o ../util.o $(LDLIBS) -o brender

# this not able to link yet
#jit: jit.o code.o noise.o
#	$(CC) $(CFLAGS) noise.o code.o arith.o jit.o $(LDLIBS) -o jit

stringtoimage: stringtoimage.o
	$(CC) $(CFLAGS) stringtoimage.o -o stringtoimage

tracesversion: tracesversion.o
	$(CC) $(CFLAGS) tracesversion.o -o tracesversion
