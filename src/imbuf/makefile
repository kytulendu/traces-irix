# Makefile for imbuf
#
# For SGI IRIX 5.3 with IDO
#

# C compiler
CC=cc

# Include directory
INCLUDES= -I. -I./jpeg-6b/ -I../include/

# C compiler options
CFLAGS= -O2 -mips2 $(INCLUDES)

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

default all: libimbuf.so

clean:
	$(RM) *.o
	$(RM) libimbuf.a
	$(RM) libimbuf.so

.c.o:
	$(CC) $(CFLAGS) -c $<

# note: must use tab as white space in all entry
libimbuf.a: $(OBJS)
	touch libimbuf.a
	$(RM) libimbuf.a
	cd jpeg-6b; make libjpeg.a
	cd ..
	$(AR) libimbuf.a $(OBJS) jpeg-6b/*.o

libimbuf.so: libimbuf.a
	$(LN) $(LDFLAGS) -soname libimbuf.so libimbuf.a -o libimbuf.so

# Comment this when first building libimbuf as convert_arrays.h is already generated.
#convert_arrays.h: make_convert
#	make_convert > convert_arrays.h
#make_convert: make_convert.c
#	cd .. ; make util.o; cd imbuf
#	$(CC) $(CFLAGS) make_convert.c ../util.o -limbuf -lm -o make_convert
