
# C compiler
CC=cc

# Include directory
INCLUDES= -I. -I./include

# C compiler options
CFLAGS= -O2 -mips2 $(INCLUDES)
#CFLAGS = -O2 -mips2 -Xcpluscomm $(INCLUDES)

BINDIR=../bin-irix-mips2

# require libforms: Chroma render-gui
# not compile: movie saver shared
default all: anim anim5 animsplit anti anti2 cmap crop fft fromjstream \
frompict fs hex imconv morph newstiff oops outline over paint render renderd \
savedisk scale scrndump scsicmd scsicontrol stretch sound tocmap togif toiff \
tojstream totarga tracesd vector video warp wu yuvrgb zipexec zipfork zoom

.c.o:
	$(CC) $(CFLAGS) -c $<

util.o: util.c ./include/util.h
	$(CC) $(CFLAGS) -c -cckr util.c

storage.o: storage.c ./include/storage.h
	$(CC) $(CFLAGS) -c storage.c

##############################################################################
# anim: Flipbook animation player?
##############################################################################

anim: anim.o util.o gl_util.o
	$(CC) $(CFLAGS) anim.o util.o gl_util.o -lmovie -lgl -lX11 -ldmedia -lcl -lawareaudio -laudio -limbuf -lm -o $(BINDIR)/anim

##############################################################################
# anim5: ???
##############################################################################

anim5: anim5.o util.o
	$(CC) $(CFLAGS) anim5.o util.o -lgl -limbuf -lm -lmpc -o $(BINDIR)/anim5

##############################################################################
# animsplit: Split animation file
##############################################################################

animsplit: animsplit.o util.o
	$(CC) $(CFLAGS) animsplit.o util.o -lmovie -lgl -lX11 -ldmedia -lcl -lawareaudio -laudio -limbuf -lm -o $(BINDIR)/animsplit

##############################################################################
# anti: ???
##############################################################################

anti: anti.o util.o
	$(CC) $(CFLAGS) anti.o util.o -lgl -limbuf -lm -o $(BINDIR)/anti

##############################################################################
# anti2: ???
##############################################################################

anti2: anti2.o util.o
	$(CC) $(CFLAGS) anti2.o util.o -lgl -limbuf -lm -o $(BINDIR)/anti2

##############################################################################
# Chroma: Chroma keying program?
#
# required FORMS library
##############################################################################

Chroma: Chroma.o  Chroma_main.o
	$(CC) $(CFLAGS) Chroma.o Chroma_main.o util.o -lforms -lmovie -lgl -lX11 -ldmedia -lcl -lawareaudio -laudio -limbuf -lGL -lm -o $(BINDIR)/Chroma

Chroma_main.o:
	$(CC) $(CFLAGS) -c Chroma_main.c

##############################################################################
# cmap: ???
##############################################################################

cmap: cmap.o util.o
	$(CC) $(CFLAGS) cmap.o util.o -lgl -limbuf -lm -lmpc -o $(BINDIR)/cmap

##############################################################################
# crop: Image crop program
##############################################################################

crop: crop.o util.o
	$(CC) $(CFLAGS) crop.o util.o -limbuf -lm -o $(BINDIR)/crop

##############################################################################
# fft: ???
##############################################################################

fft: fft.o util.o
	$(CC) $(CFLAGS) -DX_H -D_XLIB_H_ fft.o util.o -limbuf -lgl -lX11 -lcomplib.sgimath -lm -o $(BINDIR)/fft

##############################################################################
# fromjstream: ???
##############################################################################

fromjstream: fromjstream.o util.o
	$(CC) $(CFLAGS) fromjstream.o util.o -lgl -lmpc -o $(BINDIR)/fromjstream

##############################################################################
# frompict: ???
##############################################################################

frompict: frompict.o util.o
	$(CC) $(CFLAGS) -DDEBUG frompict.o util.o -limbuf -lm -limage -o $(BINDIR)/frompict

##############################################################################
# fs: File select program
##############################################################################

fs: util.o gl_util.o storage.o ./traces/Button.o
	$(CC) $(CFLAGS) fs.c -D_XLIB_H_ util.o gl_util.o storage.o ./traces/Button.o -limbuf -lm -lfm -lgl -o $(BINDIR)/fs
#	#if (-x /usr/people/bin/fs) /bin/su - root -c "chown root /usr/people/bin/fs ; chmod +s /usr/people/bin/fs"

##############################################################################
# hex: hex dump a file
##############################################################################

hex: hex.o
	$(CC) $(CFLAGS) hex.o -o $(BINDIR)/hex

##############################################################################
# morph: ???
##############################################################################

morph: util.o morph.o gl_util.o
	$(CC) $(CFLAGS) morph.o gl_util.o util.o -limbuf -lgl -lm -float -o $(BINDIR)/morph

morphdebug: util.o gl_util.o
	$(CC) -g morph.c gl_util.o util.o -limbuf -lgl -lm -float -o $(BINDIR)/morph

morph.o: morph.c
	$(CC) $(CFLAGS) -c -float morph.c

##############################################################################
# movie: ???
#
# This program must be compile on IRIX 6.2 as it require mvCopyFramesAtTime,
# which is not exist on IRIX 5.3 libmovie.
##############################################################################

movie: movie.o util.o
	$(CC) $(CFLAGS) movie.o util.o -lmovie -lgl -lX11 -limbuf -ldmedia -lcl -lawareaudio -laudio -lm -o $(BINDIR)/movie
	ln -s movie $(BINDIR)/mvcrop
	ln -s movie $(BINDIR)/mvoptimize

##############################################################################
# newstiff: Stream TIFF related
##############################################################################

newstiff: newstiff.o
	$(CC) $(CFLAGS) newstiff.o -lstiff -lm -o $(BINDIR)/newstiff

##############################################################################
# oops: ???
##############################################################################

oops: oops.o util.o gl_util.o ./traces/Button.o
	$(CC) $(CFLAGS) oops.o util.o gl_util.o ./traces/Button.o -lfm -lgl -lm -o $(BINDIR)/oops

oops.o:
	$(CC) $(CFLAGS) -cckr -c oops.c

##############################################################################
# outline: ???
##############################################################################

outline: outline.o util.o
	$(CC) $(CFLAGS) outline.o util.o -limbuf -lm -o $(BINDIR)/outline

##############################################################################
# over: ???
##############################################################################

over: over.o util.o storage.o
	$(CC) $(CFLAGS) over.o util.o storage.o -limbuf -lgl -lm -o $(BINDIR)/over
	ln -s over $(BINDIR)/overjoeri

##############################################################################
# paint: Paint program
##############################################################################

paint: paint.o util.o
	$(CC) $(CFLAGS) paint.o util.o -lgl -lX11 -limbuf -lm -lc -o $(BINDIR)/paint

##############################################################################
# render: Render program
##############################################################################

render: render.o util.o network.o ./traces/Button.o
	$(CC) $(CFLAGS) render.o util.o network.o ./traces/Button.o -lm -lfm -lgl -o $(BINDIR)/render

##############################################################################
# render: Render program, GUI version
#
# required FORMS library
##############################################################################

render-gui: render-gui.o render-gui_cb.o render-gui_main.o renderd.o network.o util.o
	$(CC) $(CFLAGS) render-gui.o render-gui_cb.o render-gui_main.o renderd.o network.o util.o -lfam -lC -lforms -lX11 -lm -o $(BINDIR)/render-gui

##############################################################################
# renderd: render deamon
##############################################################################

renderd: renderd.o renderd_main.o util.o network.o
	$(CC) $(CFLAGS) renderd.o renderd_main.o util.o network.o -lfam -lC -o $(BINDIR)/renderd

##############################################################################
# savedisk: ???
##############################################################################

savedisk: savedisk.o util.o
	$(CC) $(CFLAGS) savedisk.o util.o -limbuf -o $(BINDIR)/savedisk

##############################################################################
# saver: ???
##############################################################################

saver: saver.o util.o
	$(CC) $(CFLAGS) saver.o util.o -limbuf -lgl -lX11 -lm -o $(BINDIR)/saver

##############################################################################
# scale: ???
##############################################################################

scale: scale.o util.o
	$(CC) $(CFLAGS) scale.o util.o -limbuf -lgl -lX11 -lm -o $(BINDIR)/scale

##############################################################################
# scrndump: ???
##############################################################################

scrndump: scrndump.o util.o
	$(CC) $(CFLAGS) scrndump.o util.o -limbuf -lgl -lX11 -lm -o $(BINDIR)/scrndump

##############################################################################
# scsicmd: ???
##############################################################################

scsicmd: scsicmd.o
	$(CC) $(CFLAGS) scsicmd.o -lds -o $(BINDIR)/scsicmd

##############################################################################
# scsicontrol: ???
##############################################################################

scsicontrol: scsicontrol.o
	$(CC) $(CFLAGS) scsicontrol.o -lds -o $(BINDIR)/scsicontrol

##############################################################################
# shared: ???
#
# Required IRIX 6.2?
##############################################################################

shared: shared.o
	$(CC) $(CFLAGS) shared.o -o $(BINDIR)/shared

##############################################################################
# sound: ???
##############################################################################

sound: sound.o
	$(CC) $(CFLAGS) sound.o -lm -o $(BINDIR)/sound

##############################################################################
# stretch: ???
##############################################################################

stretch: stretch.o
	$(CC) $(CFLAGS) stretch.o util.o -float -limbuf -lgl -lX11 -lm -o $(BINDIR)/stretch

##############################################################################
# tocmap: ???
##############################################################################

tocmap: tocmap.o
	$(CC) $(CFLAGS) tocmap.o -limbuf -o $(BINDIR)/tocmap

##############################################################################
# togif: Convert an IRIS image to GIF image
##############################################################################

togif: util.o togif.o
	$(CC) $(CFLAGS) togif.o -lm -limbuf -o $(BINDIR)/togif

##############################################################################
# imconv: Image conversion program
##############################################################################

imconv: util.o imconv.o
	$(CC) $(CFLAGS) imconv.o util.o -limbuf -lgl -lm -o $(BINDIR)/imconv
	ln -s imconv $(BINDIR)/tga

imconv.o: toiff.c
	$(CC) $(CFLAGS) -c toiff.c -o imconv.o

##############################################################################
# toiff: Image conversion program
##############################################################################

toiff: util.o toiff.o
	$(CC) $(CFLAGS) -DSTRIP toiff.o util.o -limbuf -lm -o $(BINDIR)/toiff
	ln -s toiff $(BINDIR)/fromiff

toiff.o: toiff.c
	$(CC) $(CFLAGS) -DSTRIP -c toiff.c

##############################################################################
# tojstream: ???
##############################################################################

tojstream: tojstream.o util.o
	$(CC) $(CFLAGS) tojstream.o util.o -lgl -lmpc -o $(BINDIR)/tojstream

##############################################################################
# togif: Convert an IRIS image to targa image
##############################################################################

totarga: util.o totarga.o
	$(CC) $(CFLAGS) totarga.o util.o -lgl -limage -o $(BINDIR)/totarga

##############################################################################
# tracesd: Traces render deamon
##############################################################################

tracesd: tracesd.o util.o network.o
	$(CC) $(CFLAGS) tracesd.o util.o network.o -lfam -lC -o $(BINDIR)/renderd

##############################################################################
# video: Video capture program?
##############################################################################

video: video.o
	$(CC) $(CFLAGS) video.o -lvl -lgl -lX11 -ldmedia -limbuf -o $(BINDIR)/video

video.o:
	$(CC) $(CFLAGS) -c video.c

##############################################################################
# vector: ???
##############################################################################

vector: vector.o util.o
	$(CC) $(CFLAGS) vector.c util.o -lgl -limbuf -lm -o $(BINDIR)/vector

##############################################################################
# warp: ???
##############################################################################

warp: warp.o util.o
	$(CC) $(CFLAGS) warp.o util.o -limbuf -lm -o $(BINDIR)/warp

##############################################################################
# wu: ???
##############################################################################

wu: wu.o util.o gl_util.o ./traces/Button.o
	$(CC) $(CFLAGS) wu.o util.o gl_util.o ./traces/Button.o -limbuf -lfm -lgl -lm -float -o $(BINDIR)/wu

wu.o: wu.c
	$(CC) $(CFLAGS) -c -float wu.c

##############################################################################
# yuvrgb: ???
##############################################################################

yuvrgb: yuvrgb.o util.o gl_util.o ./traces/arith.o ./traces/Button.o
	$(CC) $(CFLAGS) yuvrgb.o util.o gl_util.o ./traces/arith.o ./traces/Button.o -lfm -lgl -lX11 -limbuf -lm -o $(BINDIR)/yuvrgb
	ln -s yuvrgb $(BINDIR)/rgbyuv
	ln -s yuvrgb $(BINDIR)/cpyalpha
	ln -s yuvrgb $(BINDIR)/col_to_alpha
	ln -s yuvrgb $(BINDIR)/mask
	ln -s yuvrgb $(BINDIR)/grabopt
	ln -s yuvrgb $(BINDIR)/2to3
	ln -s yuvrgb $(BINDIR)/scalecdi
	ln -s yuvrgb $(BINDIR)/deint
	ln -s yuvrgb $(BINDIR)/reint
	ln -s yuvrgb $(BINDIR)/nop
	ln -s yuvrgb $(BINDIR)/chromakey
	ln -s yuvrgb $(BINDIR)/temp
	ln -s yuvrgb $(BINDIR)/mrtotga
	ln -s yuvrgb $(BINDIR)/tompeg
	ln -s yuvrgb $(BINDIR)/frommpeg
	ln -s yuvrgb $(BINDIR)/abb
	ln -s yuvrgb $(BINDIR)/sub2
	ln -s yuvrgb $(BINDIR)/add2
	ln -s yuvrgb $(BINDIR)/lace
	ln -s yuvrgb $(BINDIR)/premul
	ln -s yuvrgb $(BINDIR)/demul
	ln -s yuvrgb $(BINDIR)/stripalpha
	ln -s yuvrgb $(BINDIR)/fieldsplit
	ln -s yuvrgb $(BINDIR)/fieldswap
	ln -s yuvrgb $(BINDIR)/fieldmerge
	ln -s yuvrgb $(BINDIR)/rmcrawl
	ln -s yuvrgb $(BINDIR)/rotcol
	ln -s yuvrgb $(BINDIR)/tojst
#	ln -s yuvrgb $(BINDIR)/fromjstream
	ln -s yuvrgb $(BINDIR)/medsys
	ln -s yuvrgb $(BINDIR)/dvd
	ln -s yuvrgb $(BINDIR)/gamma1
	ln -s yuvrgb $(BINDIR)/gamma2
	ln -s yuvrgb $(BINDIR)/graph

##############################################################################
# zipexec: ???
##############################################################################

zipexec: zipexec.o
	$(CC) $(CFLAGS) zipexec.o -lm -o $(BINDIR)/zipexec

##############################################################################
# zipfork: ???
##############################################################################

zipfork: zipfork.o
	$(CC) $(CFLAGS) zipfork.o -lm -o $(BINDIR)/zipfork

##############################################################################
# zoom: Display magnification program
##############################################################################

zoom: zoom.o
	$(CC) $(CFLAGS) zoom.o util.o -lgl -limbuf -lm -o $(BINDIR)/zoom
#	strip $(BINDIR)/zoom



##############################################################################

#anim24: anim24.o util.o /usr/lib/libimbuf.a
#	cc -O2 anim24.o util.o -lgl -lm -lmpc -limbuf -lm -lmpc -o anim24

#audiosplit: audiosplit.o
#	cc audiosplit.o -o audiosplit -laudiofile -lm

#cdd: cdd.c
#	cc -g -DDEBUG cdd.c -o cdd util.o -lgl -limbuf -lm

#chat: chat.o util.o
#	cc -g chat.o util.o -lgl -o chat

#cmapanim: imbuf.o util.o cmapanim.o iff.h util.h
#	cc -O2 cmapanim.o imbuf.o util.o  -lgl -float -o cmapanim

#compres: compres.o imbuf.o storage.o
#	cc -O2 compres.o imbuf.o util.o storage.o -o compres

#digitize: digitize.o Button.o gl_util.o vfrutil.o util.o network.o /usr/lib/libimbuf.a
#	cc -g digitize.o Button.o gl_util.o vfrutil.o util.o network.o -limbuf -lvfr -lfm -lgl -lm -lmpc -o digitize

#dirtape: dirtape.o storage.o
#	cc -O2 dirtape.o storage.o util.o -lgl -o dirtape

#displaytape.4.0.5: displaytape.o storage.o Button.o vfrutil.o gl_util.o util.o /usr/lib/libimbuf.a
#	cc -O2 displaytape.o storage.o Button.o vfrutil.o gl_util.o util.o -lfm -lsvideo -lXext -lgl -limbuf -lvfr -lfft -lm -lmpc -o displaytape

#displaytape: displaytape.o storage.o Button.o vfrutil.o gl_util.o util.o /usr/lib/libimbuf.a
#	cc -O2 displaytape.o storage.o Button.o vfrutil.o gl_util.o util.o -lfm -lgl -limbuf -lvfr -lm -lmpc -o displaytape

#dt: displaytape.o imbuf.o storage.o Button.o util.o
#	cc -O2 -s displaytape.o imbuf.o storage.o Button.o util.o -lgl -lvfr -lfm -lm -lmpc -o dt

#tapeloader: tapeloader.o util.o storage.o
#	cc -O2 tapeloader.o util.o storage.o -o tapeloader

#ed: util.o gl_util.o ed.o /usr/lib/libimbuf.a
#	cc -O2 ed.o util.o gl_util.o -lgl -limbuf -lm -o ed

#eddebug: util.o /usr/lib/libimbuf.a
#	cc -g ed.c util.o gl_util.o -lgl -limbuf -lm -o ed

#fitpoly: fitpoly.c
#	cc -g fitpoly.c -o fitpoly util.o  -lgl -limbuf -lm

#flick: flick.o util.o /usr/lib/libimbuf.a
#	cc -g flick.o util.o -limbuf -lm -lmpc -o flick

#fullscreen: fullscreen.c /usr/lib/libimbuf.a
#	cc -O2 -cckr fullscreen.c util.o -lgl -lm -limbuf -lfm -lc -lm -o fullscreen

#getdir: getdir.o storage.o storage.h
#	cc -g getdir.o storage.o -o getdir -lc getdir

#grab: grab.c util.o
#	cc -g grab.c util.o -lvfr -limbuf -lm -lmpc -o grab

#mapdef: mapdef.o
#	cc -g mapdef.o /usr/people/trace/mips1/util.o /usr/people/frank/source/gl_util.o -lgl -lm -omapdef

#mini: mini.o util.o storage.o /usr/lib/libimbuf.a
#	cc -O2 mini.o util.o storage.o -lgl -limbuf -lm -lmpc -o mini

#pyro: pyro.o arith.o
#	cc -O2 pyro.o util.o arith.o -lfm -lgl -limbuf -lm -lmpc -o pyro

#restoretape: restoretape.o storage.o util.o
#	cc -O2 restoretape.o storage.o util.o -o restoretape

#showiff: showiff.o imbuf.o iff.h
#	cc -O2 showiff.o imbuf.o util.o -lgl -o /usr/people/bin/showiff

#showvfr: showvfr.o
#	cc -O2 showvfr.o util.o -lgl -limbuf -lvfr -lm -lmpc -float -o showvfr

#slice: slice.o Button.o util.o gl_util.o /usr/lib/libimbuf.a
#	cc -O2 slice.o Button.o util.o gl_util.o -lfm -lgl -limbuf -lm -lmpc -o slice

#vpaste: vpaste.o util.o /usr/lib/libimbuf.a
#	cc -O2 vpaste.o util.o -lfm -lsvideo -lXext -lgl -limbuf -lvfr -lm -lmpc -o vpaste

#vfrpal: vfrpal.o
#	cc -O2 vfrpal.o util.o -lgl -limbuf -lvfr -lm -lmpc -float -o vfrpal

#vlan: vlan.o vfrutil.o util.o /usr/lib/libimbuf.a
#	cc -O2 vlan.o vfrutil.o util.o -lgl -limbuf -lvfr -lm -o vlan
