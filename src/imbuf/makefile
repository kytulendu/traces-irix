# Makefile for imbuf
#
# For SGI IRIX 5.3 with IDO

# C compiler
CC=cc

# Include directory
INCLUDES= -I. -I./jpeg-6b/ -I../include

# C compiler options
CFLAGS= -O -mips1 $(INCLUDES)

# library (.a) file creation command
AR= ar scru

# linker
LN= ld

# Link-time cc options
LDFLAGS= -shared -all

# To link any special libraries, add the necessary -l commands here.
LDLIBS= 

# file deletion command
RM= rm -f

OBJS= allocimbuf.o amiga.o anim.o antialias.o bitplanes.o cdi.o cmap.o \
cspace.o data.o delta.o dither.o divers.o filter.o ham.o hamx.o iff.o \
iris.o izoom.o jpeg.o makecmap.o mdec_decode.o readimage.o rectop.o \
rotate.o scaling.o targa.o tiff.o tim.o troep.o util.o writeimage.o

all: libimbuf.so

# note: must use tab as white space in entry below
libimbuf.a: $(OBJS)
	touch libimbuf.a
	$(RM) libimbuf.a
	cd jpeg-6b; make libjpeg.a
	cd ..
	$(AR) libimbuf.a $(OBJS) jpeg-6b/*.o

libimbuf.so: libimbuf.a
	$(LN) $(LDFLAGS) -soname libimbuf.so libimbuf.a -o libimbuf.so $(LDLIBS)

clean:
	$(RM) *.o
	$(RM) libimbuf.a

#install: all

#convert_arrays.h: make_convert
#	make_convert > convert_arrays.h
#make_convert: make_convert.c
#	cc make_convert.c ../util.o -limbuf -lm -o make_convert

allocimbuf.o: allocimbuf.c
amiga.o: amiga.c
anim.o: anim.c
antialias.o: antialias.c
bitplanes.o: bitplanes.c
cdi.o: cdi.c
cmap.o: cmap.c
cspace.o: cspace.c
data.o: data.c matrix.h
delta.o: delta.c
dither.o: dither.c
divers.o: divers.c
filter.o: filter.c
ham.o: ham.c
hamx.o: hamx.c convert_arrays.h
iff.o: iff.c
iris.o: iris.c
izoom.o: izoom.c
jpeg.o: jpeg.c
makecmap.o: makecmap.c
mdec_decode.o: mdec_decode.c xa_mpg.h
readimage.o: readimage.c
rectop.o: rectop.c
rotate.o: rotate.c
scaling.o: scaling.c
targa.o: targa.c
tiff.o: tiff.c
tim.o: tim.c
troep.o: troep.c
util.o: util.c
writeimage.o: writeimage.c
