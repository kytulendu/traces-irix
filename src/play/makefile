# C compiler
CC=cc

# Include directory
INCLUDES= -I. -I../include

# C compiler options
CFLAGS= -O2 -mips2 $(INCLUDES)

BINDIR=../../bin-irix-mips2

OBJECTS = play.o vlInit.o clInit.o alInit.o mvInit.o Xinit.o streamDecompress.o glxh2.o network.o util.o edl.o timecode.o play-gui.o play-gui_cb.o

LDLIBS= -lforms -lX11 -lmovie -lcl -ldmedia -lgl -laudio -lm -lvl -lgen

#play-gui play simplemovie
default all: play

.c.o:
	$(CC) $(CFLAGS) -c $<

play: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o play
	#/usr/people/bin/safemv -b play_new play
	# /bin/su - root -c "chown root /usr/people/frank/source/play/play ; chmod +s /usr/people/frank/source/play/play"

play-gui: play-gui.o play-gui_cb.o play-gui_main.o
	$(CC) $(CFLAGS) play-gui*.o -lforms -lX11 -lm -o play-gui

mix2: mix2.o glxh2.o
	$(CC) $(CFLAGS) mix2.o glxh2.o -lgutil -lsphere -lgl -lm -lX11 -o mix2

simplemovie: simplemovie.o glxhelper.o
	$(CC) $(CFLAGS) simplemovie.o glxhelper.o -lmovie -ldmedia -laudio -lX11 -o simplemovie
