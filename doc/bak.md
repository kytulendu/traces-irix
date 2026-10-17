Most of the usenet news group FAQ's can be found at:
ftp rtfm.mit.edu /pub/uesnet

FTP:

* ftp.sgi.com:~ftp/sgi/xdbx/xdbx.tar
* texteditor:
Name of Archive:	        ftp.uu.net (137.39.1.9 or 192.48.96.9)
Directory For CRISP Binaries:	/vendor/vital
* Blizzard 2D module
ftp.netcom.com	in pub/natpix

Seyon
	ftp.twi.tudelft.nl
    Location: /pub/unix/X11
      DIRECTORY    drwxr-xr-x     512 bytes  12:25 20 May 1994  seyon

nedit
xanim
xmailtool

(0(s0p14h0s3b4102T
	= Letter Gothic Bold
(8U(s0p16.67h8.5v0s0b0T
	= Line Printer
Mounting /CDROM on 'xs' and 'iris'
exportfs -i /CDROM on the 'indigo' (after the disk has been mounted)
mount -t nfs indigo:/CDROM /CDROM on 'xs'

clonedisk

mkdir /clone
cd /clone
dump 0uf - / | restore xvf -

tar flags: tar oxvf filename

To copy entire directories:

cd fromdir; tar cf - . | (cd todir; tar xvf -)
cd fromdir; tar cf - . | rsh remote "(cd todir; tar xf -)"

You can also redirect stderr by using |& and >&.
Example: tar cv morkramia |& tee /data/listings/mork1

Backup:
Restoring the directory oudwerk/aa/*:
tar xv oudwerk/aa (oudwerk/aa/ <- does not work!!)

man directory
man stat
man scandir combines these!

'tput' moves the cursor / changes print color using escape codes
echo '\033P1.yFrank\033\\'
alias cwdcmd echo '"\033P1.y$cwd\033\\"'

Performing calculations in the console: expr

Escape codes: see chapter GA (at the beginning) of the 4Sight Programmer's Guide
'imon' provides signals when files change (doesn't work?)

Printer configuration is located in /usr/spool/lp/interface...

wsh -Z3 -Z4 -L/dev/grconc,/dev/grcons -r1000 -s24x80 -m60x80 -fScreen.12 -Z7
Opens an original console

'nice' = settaskpri
man screenspace (for Ton!)

Use 'qgetfd' to retrieve the file descriptor of a queue
See also 'select' for polling

What is an input subchannel? required for sending queue values
to a program (see qcontrol / qc_sendevent).

Located in /usr/sysgen/master.d is stty_ld; this is a module that resides
within the keyboard stream.



To be able to open 'par' in the 'displaytape' program:

su
chmod 770 displaytape
chmod +s displaytape
chown root displaytape


df = disk free


File definitions are located in /usr/lib/filetype

su
cd /usr/lib/filetype
make
(to recompile them)

You can find the default font in /usr/gfx

If you disassemble the 'gl' (graphics library), the PAL definition begins at line:
monitor.c: 274

#include	<sys/sgigsc.h>
sgigsc(216,*video);
'sgikopt' is used to change boot variables (diskless, monitor, etc.)
'nvram' is also part of this

		pal:										ntsc:
byte:	3	op 52(sp)	1		0		15		2
byte:	?	op 53(sp)	?	?	?		?
long:	780	op 56(sp)	1280	1280	1024	646
long:	575	op 60(sp)	1024	1024	768		485
long:	24	op 64(sp)	39		189		69		-6
long:	-9	op 68(sp)	18		6		7		-14

	setvideo:			a0 = address, a1 -> v1 = value

  [monitor.c: 228] 0x4064c0:	27bdffa8	addiu	sp,sp,-88
  [monitor.c: 234] 0x4064c4:	3c010080	lui	at,0x80
  [monitor.c: 228] 0x4064c8:	afbf0014	sw	ra,20(sp)
  [monitor.c: 234] 0x4064cc:	1481000a	bne	a0,at,0x4064f8	
  [monitor.c: 228] 0x4064d0:	00a01821	move	v1,a1
  [monitor.c: 238] 0x4064d4:	0c101824	jal	getmonitor
  [monitor.c: 238] 0x4064d8:	afa3005c	sw	v1,92(sp)
  [monitor.c: 238] 0x4064dc:	8fa3005c	lw	v1,92(sp)
  [monitor.c: 239] 0x4064e0:	00402021	move	a0,v0
  [monitor.c: 239] 0x4064e4:	27a60024	addiu	a2,sp,36
  [monitor.c: 239] 0x4064e8:	0c106be8	jal	gl_glv_to_der1
  [monitor.c: 239] 0x4064ec:	00602821	move	a1,v1
  [monitor.c: 241] 0x4064f0:	8fa30024	lw	v1,36(sp)
  [monitor.c: 240] 0x4064f4:	00002021	move	a0,zero
  [monitor.c: 244] 0x4064f8:	148000a7	bne	a0,zero,0x406798	!DE_R1 = 0
  [monitor.c: 244] 0x4064fc:	248bffff	addiu	t3,a0,-1
  [monitor.c: 247] 0x406500:	1000004b	b	0x406630
  [monitor.c: 246] 0x406504:	00002821	move	a1,zero
  [monitor.c: 250] 0x406508:	8f8e92f0	lw	t6,-27920(gp)
  [monitor.c: 250] 0x40650c:	00000000	nop
  [monitor.c: 250] 0x406510:	8dcf0020	lw	t7,32(t6)
  [monitor.c: 250] 0x406514:	00000000	nop
  [monitor.c: 250] 0x406518:	31f80200	andi	t8,t7,0x200
  [monitor.c: 250] 0x40651c:	1300000d	beq	t8,zero,0x406554
  [monitor.c: 250] 0x406520:	00000000	nop
  [monitor.c: 250] 0x406524:	93a50035	lbu	a1,53(sp)
  [monitor.c: 251] 0x406528:	2419000f	li	t9,15
  [monitor.c: 251] 0x40652c:	a3b90034	sb	t9,52(sp)
  [monitor.c: 252] 0x406530:	24080400	li	t0,1024
  [monitor.c: 252] 0x406534:	afa80038	sw	t0,56(sp)
  [monitor.c: 253] 0x406538:	24090300	li	t1,768
  [monitor.c: 254] 0x40653c:	240a0045	li	t2,69
  [monitor.c: 255] 0x406540:	240b0007	li	t3,7
  [monitor.c: 253] 0x406544:	afa9003c	sw	t1,60(sp)
  [monitor.c: 254] 0x406548:	afaa0040	sw	t2,64(sp)
  [monitor.c: 256] 0x40654c:	10000062	b	0x4066d8
  [monitor.c: 255] 0x406550:	afab0044	sw	t3,68(sp)
  [monitor.c: 257] 0x406554:	a3a00034	sb	zero,52(sp)
  [monitor.c: 256] 0x406558:	93a50035	lbu	a1,53(sp)
  [monitor.c: 258] 0x40655c:	240c0500	li	t4,1280
  [monitor.c: 258] 0x406560:	afac0038	sw	t4,56(sp)
  [monitor.c: 259] 0x406564:	240d0400	li	t5,1024
  [monitor.c: 260] 0x406568:	240e00bd	li	t6,189
  [monitor.c: 261] 0x40656c:	240f0006	li	t7,6
  [monitor.c: 259] 0x406570:	afad003c	sw	t5,60(sp)
  [monitor.c: 260] 0x406574:	afae0040	sw	t6,64(sp)
  [monitor.c: 263] 0x406578:	10000057	b	0x4066d8
  [monitor.c: 261] 0x40657c:	afaf0044	sw	t7,68(sp)
  [monitor.c: 266] 0x406580:	24180001	li	t8,1
  [monitor.c: 266] 0x406584:	a3b80034	sb	t8,52(sp)
  [monitor.c: 267] 0x406588:	24190500	li	t9,1280
  [monitor.c: 267] 0x40658c:	afb90038	sw	t9,56(sp)
  [monitor.c: 268] 0x406590:	24080400	li	t0,1024
  [monitor.c: 269] 0x406594:	24090027	li	t1,39
  [monitor.c: 270] 0x406598:	240a0012	li	t2,18
  [monitor.c: 268] 0x40659c:	afa8003c	sw	t0,60(sp)
  [monitor.c: 269] 0x4065a0:	afa90040	sw	t1,64(sp)
  [monitor.c: 271] 0x4065a4:	1000004c	b	0x4066d8
  [monitor.c: 270] 0x4065a8:	afaa0044	sw	t2,68(sp)
  [monitor.c: 274] 0x4065ac:	240b0003	li	t3,3			pal!
  [monitor.c: 274] 0x4065b0:	a3ab0034	sb	t3,52(sp)
  [monitor.c: 275] 0x4065b4:	240c030c	li	t4,780
  [monitor.c: 275] 0x4065b8:	afac0038	sw	t4,56(sp)
  [monitor.c: 276] 0x4065bc:	240d023f	li	t5,575
  [monitor.c: 277] 0x4065c0:	240e0018	li	t6,24
  [monitor.c: 278] 0x4065c4:	240ffff7	li	t7,-9
  [monitor.c: 276] 0x4065c8:	afad003c	sw	t5,60(sp)
  [monitor.c: 277] 0x4065cc:	afae0040	sw	t6,64(sp)
  [monitor.c: 279] 0x4065d0:	10000041	b	0x4066d8
  [monitor.c: 278] 0x4065d4:	afaf0044	sw	t7,68(sp)
  [monitor.c: 282] 0x4065d8:	24180002	li	t8,2
  [monitor.c: 282] 0x4065dc:	a3b80034	sb	t8,52(sp)
  [monitor.c: 283] 0x4065e0:	24190286	li	t9,646
  [monitor.c: 283] 0x4065e4:	afb90038	sw	t9,56(sp)
  [monitor.c: 284] 0x4065e8:	240801e5	li	t0,485
  [monitor.c: 285] 0x4065ec:	2409fffa	li	t1,-6
  [monitor.c: 286] 0x4065f0:	240afff2	li	t2,-14
  [monitor.c: 284] 0x4065f4:	afa8003c	sw	t0,60(sp)
  [monitor.c: 285] 0x4065f8:	afa90040	sw	t1,64(sp)
  [monitor.c: 287] 0x4065fc:	10000036	b	0x4066d8
  [monitor.c: 286] 0x406600:	afaa0044	sw	t2,68(sp)
  [monitor.c: 289] 0x406604:	240b0004	li	t3,4
  [monitor.c: 289] 0x406608:	a3ab0034	sb	t3,52(sp)
  [monitor.c: 290] 0x40660c:	240c0500	li	t4,1280
  [monitor.c: 290] 0x406610:	afac0038	sw	t4,56(sp)
  [monitor.c: 291] 0x406614:	240d0400	li	t5,1024
  [monitor.c: 292] 0x406618:	240e00bd	li	t6,189
  [monitor.c: 293] 0x40661c:	240f0007	li	t7,7
  [monitor.c: 291] 0x406620:	afad003c	sw	t5,60(sp)
  [monitor.c: 292] 0x406624:	afae0040	sw	t6,64(sp)
  [monitor.c: 294] 0x406628:	1000002b	b	0x4066d8
  [monitor.c: 293] 0x40662c:	afaf0044	sw	t7,68(sp)
  [monitor.c: 294] 0x406630:	240400a0	li	a0,160
  [monitor.c: 298] 0x406634:	306200f0	andi	v0,v1,0xf0
  [monitor.c: 298] 0x406638:	1044ffe7	beq	v0,a0,0x4065d8
  [monitor.c: 298] 0x40663c:	284100a1	slti	at,v0,161
  [monitor.c: 298] 0x406640:	10200017	beq	at,zero,0x4066a0
  [monitor.c: 298] 0x406644:	24010060	li	at,96
  [monitor.c: 298] 0x406648:	1041ffd8	beq	v0,at,0x4065ac
  [monitor.c: 298] 0x40664c:	28410061	slti	at,v0,97
  [monitor.c: 298] 0x406650:	1020000e	beq	at,zero,0x40668c
  [monitor.c: 298] 0x406654:	24010020	li	at,32
  [monitor.c: 298] 0x406658:	1041ffdf	beq	v0,at,0x4065d8
  [monitor.c: 298] 0x40665c:	28410021	slti	at,v0,33
  [monitor.c: 298] 0x406660:	10200005	beq	at,zero,0x406678
  [monitor.c: 298] 0x406664:	24010010	li	at,16
  [monitor.c: 298] 0x406668:	1041ffc6	beq	v0,at,0x406584
  [monitor.c: 298] 0x40666c:	24180001	li	t8,1
  [monitor.c: 298] 0x406670:	10000058	b	0x4067d4
  [monitor.c: 298] 0x406674:	8fbf0014	lw	ra,20(sp)
  [monitor.c: 298] 0x406678:	24010040	li	at,64
  [monitor.c: 298] 0x40667c:	1041ffa2	beq	v0,at,0x406508
  [monitor.c: 298] 0x406680:	a3a50035	sb	a1,53(sp)
  [monitor.c: 298] 0x406684:	10000053	b	0x4067d4
  [monitor.c: 298] 0x406688:	8fbf0014	lw	ra,20(sp)
  [monitor.c: 298] 0x40668c:	24010090	li	at,144
  [monitor.c: 298] 0x406690:	1041ffbc	beq	v0,at,0x406584
  [monitor.c: 298] 0x406694:	24180001	li	t8,1
  [monitor.c: 298] 0x406698:	1000004e	b	0x4067d4
  [monitor.c: 298] 0x40669c:	8fbf0014	lw	ra,20(sp)
  [monitor.c: 298] 0x4066a0:	240100d0	li	at,208
  [monitor.c: 298] 0x4066a4:	1041ffd7	beq	v0,at,0x406604
  [monitor.c: 298] 0x4066a8:	284100d1	slti	at,v0,209
  [monitor.c: 298] 0x4066ac:	10200005	beq	at,zero,0x4066c4
  [monitor.c: 298] 0x4066b0:	240100c0	li	at,192
  [monitor.c: 298] 0x4066b4:	1041ff94	beq	v0,at,0x406508
  [monitor.c: 298] 0x4066b8:	a3a50035	sb	a1,53(sp)
  [monitor.c: 298] 0x4066bc:	10000045	b	0x4067d4
  [monitor.c: 298] 0x4066c0:	8fbf0014	lw	ra,20(sp)
  [monitor.c: 298] 0x4066c4:	240100e0	li	at,224
  [monitor.c: 298] 0x4066c8:	1041ffb9	beq	v0,at,0x4065b0
  [monitor.c: 298] 0x4066cc:	240b0003	li	t3,3
  [monitor.c: 298] 0x4066d0:	10000040	b	0x4067d4
  [monitor.c: 298] 0x4066d4:	8fbf0014	lw	ra,20(sp)

  flags are (also) being converted here: v1 = value
  [monitor.c: 298] 0x4066d8:	30780002	andi	t8,v1,0x2	! sync on green
  [monitor.c: 298] 0x4066dc:	13000004	beq	t8,zero,0x4066f0
  [monitor.c: 298] 0x4066e0:	30790001	andi	t9,v1,0x1	! stereo optic
  [monitor.c: 298] 0x4066e4:	34a50001	ori	a1,a1,0x1
  [monitor.c: 298] 0x4066e8:	30a500ff	andi	a1,a1,0xff
  [monitor.c: 298] 0x4066ec:	30790001	andi	t9,v1,0x1
  [monitor.c: 298] 0x4066f0:	13200009	beq	t9,zero,0x406718
  [monitor.c: 298] 0x4066f4:	24010090	li	at,144
  [monitor.c: 299] 0x4066f8:	34a50004	ori	a1,a1,0x4
  [monitor.c: 299] 0x4066fc:	10000005	b	0x406714
  [monitor.c: 299] 0x406700:	30a500ff	andi	a1,a1,0xff
  [monitor.c: 300] 0x406704:	34a50008	ori	a1,a1,0x8
  [monitor.c: 300] 0x406708:	30a500ff	andi	a1,a1,0xff
  [monitor.c: 301] 0x40670c:	1000000b	b	0x40673c
  [monitor.c: 301] 0x406710:	a3a50035	sb	a1,53(sp)
  [monitor.c: 301] 0x406714:	24010090	li	at,144
									v0 = videomode
  [monitor.c: 302] 0x406718:	1041fffa	beq	v0,at,0x406704	at = 144 = 30 Hz Genlock
  [monitor.c: 304] 0x40671c:	00000000	nop
  [monitor.c: 302] 0x406720:	1044fff8	beq	v0,a0,0x406704  a0 = 160? = Genlock RS170
  [monitor.c: 309] 0x406724:	240100c0	li	at,192
  [monitor.c: 309] 0x406728:	1041fff6	beq	v0,at,0x406704	192 = genlock 60Hz
  [monitor.c: 310] 0x40672c:	240100e0	li	at,224
  [monitor.c: 310] 0x406730:	1041fff4	beq	v0,at,0x406704	= Genlock pal
  [monitor.c: 313] 0x406734:	00000000	nop
  [monitor.c: 313] 0x406738:	a3a50035	sb	a1,53(sp)	= geen genlock
  [monitor.c: 313] 0x40673c:	240400d8	li	a0,216
  [monitor.c: 313] 0x406740:	0c112fd0	jal	sgigsc
  [monitor.c: 313] 0x406744:	27a50034	addiu	a1,sp,52
  [monitor.c: 313] 0x406748:	2401ffff	li	at,-1
  [monitor.c: 313] 0x40674c:	14410021	bne	v0,at,0x4067d4
  [monitor.c: 313] 0x406750:	8fbf0014	lw	ra,20(sp)
  [monitor.c: 313] 0x406754:	3c041000	lui	a0,0x1000
  [monitor.c: 313] 0x406758:	0fe004ec	jal	perror
  [monitor.c: 313] 0x40675c:	24841e70	addiu	a0,a0,7792
  [monitor.c: 313] 0x406760:	1000001c	b	0x4067d4
  [monitor.c: 315] 0x406764:	8fbf0014	lw	ra,20(sp)
  [monitor.c: 315] 0x406768:	10000015	b	0x4067c0
  [monitor.c: 315] 0x40676c:	afa0004c	sw	zero,76(sp)
  [monitor.c: 315] 0x406770:	24080001	li	t0,1
  [monitor.c: 315] 0x406774:	10000012	b	0x4067c0
  [monitor.c: 315] 0x406778:	afa8004c	sw	t0,76(sp)
  [monitor.c: 316] 0x40677c:	24090003	li	t1,3
  [monitor.c: 316] 0x406780:	1000000f	b	0x4067c0
  [monitor.c: 316] 0x406784:	afa9004c	sw	t1,76(sp)
  [monitor.c: 318] 0x406788:	240a0002	li	t2,2
  [monitor.c: 318] 0x40678c:	1000000c	b	0x4067c0
  [monitor.c: 325] 0x406790:	afaa004c	sw	t2,76(sp)
  [monitor.c: 324] 0x406794:	248bffff	addiu	t3,a0,-1
  [monitor.c: 328] 0x406798:	2d610004	sltiu	at,t3,4
  [monitor.c: 329] 0x40679c:	1020000c	beq	at,zero,0x4067d0
  [monitor.c: 328] 0x4067a0:	00000000	nop
  [monitor.c: 332] 0x4067a4:	000b5880	sll	t3,t3,2
  [monitor.c: 333] 0x4067a8:	3c011000	lui	at,0x1000
  [monitor.c: 332] 0x4067ac:	002b0821	addu	at,at,t3
  [monitor.c: 336] 0x4067b0:	8c2b0210	lw	t3,528(at)
  [monitor.c: 337] 0x4067b4:	00000000	nop
  [monitor.c: 336] 0x4067b8:	01600008	jr	t3
  [monitor.c: 342] 0x4067bc:	00000000	nop
  [monitor.c: 342] 0x4067c0:	a3a30050	sb	v1,80(sp)
  [monitor.c: 342] 0x4067c4:	24040191	li	a0,401
  [monitor.c: 342] 0x4067c8:	0c112fd0	jal	sgigsc
  [monitor.c: 342] 0x4067cc:	27a5004c	addiu	a1,sp,76
  [monitor.c: 342] 0x4067d0:	8fbf0014	lw	ra,20(sp)
  [monitor.c: 342] 0x4067d4:	27bd0058	addiu	sp,sp,88
  [monitor.c: 342] 0x4067d8:	03e00008	jr	ra
  [monitor.c: 342] 0x4067dc:	00000000	nop


Sproc (prctl) are counterparts to fork, in which memory areas remain accessible to
both processes.


What reading the tapes has yielded, at any rate:
setsym: something related to symbolic debugging; see also symmon
lboot:
/usr/sysgen/boot
/usr/sysgen/boot/idbg.o
/usr/sysgen/master.d
/usr/sysgen/master.d/master.c
/usr/sysgen/master.d/edt.list
though I am not entirely certain about the latter items.


cc -g compiles code with additional debug symbols.


By using sproc instead of exec, memory blocks can be shared.

With regcmp and regex, strings containing * and ? can be compared.

Grep allows you to search for an ASCII string across a number of files.

Kermit: issue with cwd, specifically the routine cwd in ckcfns.c.

Process control information can be found in:
/usr/include/sys/fs/dbfcntl.h
/usr/include/sys/proc.h
/usr/include/sys/user.h
man syssgi
man ptrace (at the end)
man debug

In /usr/4Dgifts/.4sight, you will find various PostScript files for customizing windows, etc.



jpeg / JPEG

some benchmarks (kbytes):

				IFF		100		75		50		25

mediasolutions still		804		156		38		27		19
rabo.still			590		154		55


pcreate is a faster way to start a new program (?)

In <sys/systm.h>, you can find various information about the system.

mpin can be used to ensure that pages are not swapped out.

shmget / shmop can be used to exchange memory blocks:
	#include <sys/types.h>
	#include <sys/ipc.h>
	#include <sys/shm.h>
	shmid = shmget(IPC_PRIVATE,
	pointer = shmat(shmid,0,SHM_RDONLY); maps shared memory into your own memory space
	shmdt(pointer(?)); deletes the area

swap: getrusage provides information about timing and swapping.
syssgi() can be used to set swap-related variables (see also /usr/include/sys/tuneable).
sys/swap is related to sysmips; it can be used to add and delete swap files (?).



vfr_regs

58 Field status provides information on which field is active.
8 Clock controls the clock (PAL/NTSC, etc.).

size / nm provides information about the text and data formats of object files and
executables.

mkshlib can be used to create shared libraries.


prof/pixie:

compile program myprog
pixie myprog	/* creates myprog.pixie and myprog.Addrs */
setenv LD_LIBRARY_PATH . /* required since version 5.2? (ton) */
myprog.pixie	/* creates myprog.Counts */
prof -pixie myprog > ~/rt	/* provides an overview in ~/rt */


useful tags
tag 0x9034 paint
tag 0x9037 paint


genlocking YUV via Magni:
shift the Y component two pixels to the right, multiply by 248/256, and set the Magni to black-and-white mode.

use `readlink` to determine which file a symbolic link points to.
use `symlink` to create links across different file systems.

use `isSuper` to query the file type of a given file; for usage examples, see
/etc/transferDevice/quickmodel_file_IO


the `-P` option for `cc` allows you to direct the output of the preprocessor (`cpp`)
to a file (source.c -> source.i)

the `-G` switch for `cc` allows you to specify the maximum size a data segment
can have while still being addressable via the global pointer (GP).


Formatting hard disks:

Use `fx` to create partitions on `/dev/dsk/dks0....vh`.
Then, use `mkfs -i /dev/dsk/...` to initialize the partitions (do NOT include the `vh` suffix).
For additional partitions, device entries must also be created.

Spool / crontab / fsr:
The program is referenced in `/usr/spool/cron/crontabs/root`.

Standard `.cshrc`, `.login`, and `.profile` files can be found in `/etc/stdxxxx`.
The execution order for these files is:
`/etc/cshrc`
`~/.cshrc`
`~/.login`

The startup script is located in `/usr/lib/X11/xdm/Xsession`.

`pixmode(PM_STRIDE, 720);` works when linking with `lgl` & `X11`, but not when linking with `lgl_s`!

PAL resolution is definitely 780 × 575, according to `sys/gr1hw.h`.



Bugs for Silicon [Graphics systems]:

1. `pixmode(PM_STRIDE, x)` does not work with `gl_s` on Iris and Indigo systems,
though it does work in combination with `gl` and X11.
2. `pixmode(PM_STRIDE, x)` triggers a "GURU" (system crash/kernel panic) if `x` is too small.
3. On the Indigo, `pixmode(PM_TTOB, 1)` sometimes renders rectangles upside down
(specifically rectangles smaller than a certain size).
4. `pixmode(PM_TTOB, 1)` does not work at all on the Personal Iris.

New bugs for Silicon [Graphics systems]:

1. When placing large rectangles (720 × 576 × 16-bit), the frame counter is not always incremented. 
As a result, `swapbuffers` waits one frame longer than specified by the `swapinterval` setting.
2. On the Indigo, `pixmode(PM_TTOB, 1)` sometimes renders small rectangles upside down.
Example rectangle: (46, 315, 68, 346).

The `glresources` man page contains information regarding "menu overfirst."

Proposed design for inter-process communication:
A daemon will be implemented to handle all requests.
Various types of programs will be able to connect to it, send data, and retrieve data.

`fs` (file system/file service): Sends a destination directory and process ID so that, for example,
during a "copy" or "move" operation, the data is placed in the correct directory
and the overview/index is updated accordingly.

`paint`: A copy of the brush is stored. Foreground and background
colors can also be synchronized.

`traces`: Copying and pasting of objects?

Images lacking an alpha channel should be assigned a default alpha value of 255.
Color maps (cmap) should also default to 255.

Functions: deinterlace, interlace, add alpha. find -cnewer lastbackfile : all files newer than lastbackfile
find /usr/people/ -cnewer /usr/people/frank/source/anim.c -print

find: no directories (as these are copied along with their contents), no .o files
cd /usr/people
find . ! -type d ! -name '*.o' -cnewer /tmp/lastbackup ! -cnewer /tmp/newdate -print | tar caBf - - | (cd /backup/people ; tar xBf -)

showcase /data/irisdata/toolbox2.0/src/demos/VGX/shadows/Article.showcase

set init_vlan = `echo abcd` stores the exit status / return variable of a command into a
shell variable ($abcd) (PAY ATTENTION TO THE DIRECTION OF THE BACKTICKS!)

in sh, the syntax is: abc=`rt`

include files that may or may not have to do with swap buffers / gsync / lrectwrite
to have:


/usr/include/sys/rrm.h 
	gsync: ioctl(RRM_WAITFORRETRACE);
/usr/include/sys/IP12.h 
	/* 
	 * Vertical retrace status (INT2)
	 */
	#define VRSTAT_ADDR	VME_ISR_ADDR	/* VR status read from vme reg */
	#define VRSTAT_MASK	0x01		/* Vert retrace status: no interrupt */


The Xserver regularly fails with:

Xlib:  sequence lost (0x10000 > 0x3adf) in reply type 0x0!
GL: X request = 58.4, error code = 0
ERROR #93  Error in communication with window server: ERR_WMANIPC

Xlib:  sequence lost (0x10000 > 0xa092) in reply type 0x0!
GL: X request = 160.4, error code = 0
ERROR #93  Error in communication with window server: ERR_WMANIPC

Xlib:  sequence lost (0x10000 > 0x9093) in reply type 0x0!
GL: X request = 144.4, error code = 0
ERROR #93  Error in communication with window server: ERR_WMANIPC

#define HPC1COUNTER	0x1fb80194	/* Counter (24 bits) (ro) */


proces 12067 (traceso) requested stop [_libX_ftruncate, :0xcc0226c

*[_libX_ftruncate,0xcc0226c]	bne	a3,0xcc02290
 [_libX_ftruncate,0xcc02270]	nop
 
/usr/lib/X11/xdm/Xsession has been modified to conduct a test involving
the "swap people" setup.

VLAN control window:

Opens a window for interactive control of the VLAN and creates a
socket, allowing commands to be issued from the Indigo. It should
also be possible to display this window on the Indigo. Furthermore,
the system must support color bars, black, and "blacks from tape."
The program must be able to accept new connections while
simultaneously handling existing connections and processing `qread` operations.

Real-time sequence:

1.  Launch the VLAN control screen.
2.  Wait for the "start" command to be issued.
3.  Switch to PAL.
4.  Set the duration and auto-increment values.
5.  Request a "preroll."
6.  Initialize the VLAN so that a signal is received one frame prior to recording.
7.  Execute the operation.
8.  Verify that everything proceeded correctly.
9.  Switch back to 60 Hz.
10. Return to step 2.



dps / postscript

files:

man DPS
gr_relnotes
include/DPS/dpsfriends.h
include/DPS/dpsclient.h
pswrap



audio:

manual pages / audio
man cdaudio


Distributed rendering:

Each computer runs a render daemon.
Every request for distributed rendering is directed to the local daemon,
which distributes the task among all accessible daemons.
On any given computer, the daemon can be restricted from rendering
if the computation time consumes too much local processing time.
Optionally, the background renderer should perform a "signal" (or yield)
every few pixels, seconds, or scanlines to ensure it competes as
little as possible with other processes.
It must be possible to terminate processes. A graphical interface
will be provided to stop background rendering, abort animations,
and initiate new ones.
As soon as an animation is started directly from the trace,
background rendering should also cease (for the sake of convenience).


To-do list for the demo:
Wrappers/sleeves
Music
Required:
Labels for VHS tapes, Betacam tapes, envelopes, and diskettes
Wrappers/sleeves for VHS and Betacam tapes.


Pattern recognition (gestures)

Patterns must be reduced to a "universal" format.

1. Independent of the movement's dimensions (sizeX / sizeY).
2. Independent of the movement's speed (number of coordinates).
3. Potentially independent of rotation.

Methodology / Format:

A set of normalized vectors, each with an associated "size" indicator.

A gesture is reduced to a fixed (?) number of vectors (20).
Each segment is matched against a portion of the movement being analyzed.
The direction may deviate, and the length may vary by a factor of 2,
before "penalty points" are applied.


The VR register is located at: PHYS_TO_K1(VME_ISR_ADDR);

in IP12.h !
#define VRSTAT_ADDR	VME_ISR_ADDR	/* VR status read from vme reg */
#define VRSTAT_MASK	0x01		/* Vert retrace status: no interrupt */

HPC_0_ID_ADDR = 0x1fb80000
VME_ISR_ADDR = 0x1fb801d3 of 0x1fb801d0

files :
gr2.h
sgigsc.h
systm.h
gfx.h
IP12.h
sbd.h
rrm.h
IP12.h


The 'retrace bit' can be used to determine the start of a field;
subsequently, the timer can be used to retrieve the remaining data
(field status, line number, etc.).

TODO:

- Fix 'displaytape' errors. 
  Allow deletion of 'ABORTED' entries. 
  Simplify the setting of 'IN', 'OUT', and 'DUR' values. 
  Create an 'EDIT' decision list.
- Enable real-time operation.

The 'ftw' (file tree walk) utility can be used to query the contents of directories.

Issues regarding delta compression for CD-i:

- The largest deltas have already been removed, as they can be placed
in a background plane. Is it possible to further compress Martin's
foreground images relative to one another? Can the 'RL7' format be
improved? Currently, it repeatedly encodes large sections of 'nothing' (empty space).

- Could a bitplane-based method yield further gains? What are the
delta sizes using 'Anim5' (which could likely be improved further),
and what would the delta sizes be with byte-based compression?

- DYUV causes streaking (??). This could potentially be avoided by using
a DYUV image as a 'skybuf'. The question is whether DYUV images can
be mapped 1:1, especially given that the U and V components undergo
compression and decompression. HELP.

1. Implement 'Anim5' compression.
2. Implement 'Anim5' decompression.

Optimizations:

1. When compiling with the '-float' flag, ensure all floating-point constants
(e.g., 0.0) are explicitly cast—for instance, as `((float) 0.0)`. Otherwise,
the entire expression may be promoted to `double` before the result is
cast back to `float`. 2. Converting ulongs (ushorts?) to float requires significantly more
instructions than converting longs (shorts?).


Extension for loadiff:

To enable routines for reading in sequences of images:

1. Initialize routine with permitted sequence types and an initial filename:
- sequences by filename (e.g., .0001)
- directories
- anim5 animations
- TGA deltas
- IFF 24-bit deltas (.delta)

2. Retrieve the next (or previous?) image.

3. Release resources.

R-Y gain (videoframer/vfr) used to be -22; now it’s suddenly -8 (-12)?????????
(at least when switching to PAL first).
Y gain was 25; now it’s 29.
	
what went wrong:
From neogeo!MAILER-DAEMON@relay.nluug.nl Fri Feb 12 01:21:19 1993
Received: from mailhost.tue.nl by rc6.urc.tue.nl with SMTP id AA18472
  (5.65c/IDA-1.4.4 for <wmbfmk@rc6.urc.tue.nl>); Fri, 12 Feb 1993 01:21:17 +0100
Received: from sun4nl.nluug.nl by mailhost.tue.nl with SMTP id AA24149
  (5.65c/IDA-1.4.4 for <wmbfmk@urc.tue.nl>); Fri, 12 Feb 1993 01:24:00 +0100
Received: from neogeo by sun4nl.nluug.nl via EUnet
        id AA26681 (5.65b/CWI-3.3); Fri, 12 Feb 1993 01:20:50 +0100
Received: by neogeo (920330.SGI/920502.SGI)
        for sun4nl!urc.tue.nl!wmbfmk id AA00475; Fri, 12 Feb 93 01:19:52 +0100
Date: Fri, 12 Feb 93 01:19:52 +0100
From: neogeo!MAILER-DAEMON@relay.nluug.nl (Mail Delivery Subsystem)
Subject: Returned mail: Host name server lookup failed
Message-Id: <9302120019.AA00475@neogeo>
To: wmbfmk@urc.tue.nl
Status: RO

   ----- Transcript of session follows -----
451 xfAA00444: line 6: Loop while matching ruleset 0, line 512: Connection refused
451 xfAA00444: line 6: Loop while matching ruleset 0, line 544: Connection refused
451 xfAA00444: line 6: Loop while matching ruleset 0, line 512: Connection refused
451 xfAA00444: line 6: Loop while matching ruleset 0, line 544: Connection refused
451 xfAA00444: line 6: Loop while matching ruleset 0, line 512: Connection refused
451 xfAA00444: line 6: Loop while matching ruleset 0, line 544: Connection refused
451 xfAA00444: line 6: Loop while matching ruleset 0, line 481: Connection refused
554 xfAA00444: line 6: Loop while matching ruleset 0, line 482
554 xfAA00444: line 6: Loop while matching ruleset 0, line 512
451 xfAA00444: line 6: Loop while matching ruleset 0, line 544: Connection refused
554 xfAA00444: line 6: rewrite: expansion too long

   ----- Unsent message follows -----
Received: from sun4nl by neogeo via UUCP (920330.SGI/920502.SGI)
         id AA00444; Fri, 12 Feb 93 01:16:51 +0100
Received: from mailhost.tue.nl by sun4nl.nluug.nl with SMTP
        id AA25701 (5.65b/CWI-3.3); Fri, 12 Feb 1993 01:15:08 +0100
Received: from rw7.urc.tue.nl by mailhost.tue.nl with SMTP id AA24141
  (5.65c/IDA-1.4.4 for <frank@neogeo.nl>); Fri, 12 Feb 1993 01:18:13 +0100
Received: by rw7.urc.tue.nl id AA03301
  (5.65c/IDA-1.4.4 for frank@neogeo.nl); Fri, 12 Feb 1993 01:15:02 +0100
Date: Fri, 12 Feb 1993 01:15:02 +0100
From: Marc van Kempen <wmbfmk@urc.tue.nl>
Message-Id: <199302120015.AA03301@rw7.urc.tue.nl>
To: frank@neogeo.nl
Subject: test

test test

& 




From neogeo!frank@relay.nluug.nl Fri Feb 12 14:32:46 1993
Received: from mailhost.tue.nl by rc6.urc.tue.nl with SMTP id AA28691
  (5.65c/IDA-1.4.4 for <wmbfmk@rc6.urc.tue.nl>); Fri, 12 Feb 1993 14:32:42 +0100
Received: from sun4nl.nluug.nl by mailhost.tue.nl with SMTP id AA27574
  (5.65c/IDA-1.4.4 for <wmbfmk@urc.tue.nl>); Fri, 12 Feb 1993 14:35:17 +0100
Received: from neogeo by sun4nl.nluug.nl via EUnet
        id AA19877 (5.65b/CWI-3.3); Fri, 12 Feb 1993 14:32:01 +0100
Received: by neogeo.nl (920330.SGI/920502.SGI.AUTO)
        for sun4nl!urc.tue.nl!wmbfmk id AA03822; Fri, 12 Feb 93 14:31:15 +0100
Date: Fri, 12 Feb 93 14:31:15 +0100
From: neogeo!frank@relay.nluug.nl (Frank van Beek)
Message-Id: <9302121331.AA03822@neogeo.nl>
To: Marc van Kempen <wmbfmk@urc.tue.nl>
Subject: Neeeeeeeeeeeee

FOh dear, oh dear, Marc.
By now, you really ought to know that FTP and email are completely different
things.

But to be honest: I don’t even know yet how to ensure I remain frank@neogeo.nl,
instead of ending up as frank@neogeo.uucp or neogeo!frank@relay.nluug.nl.

Testing 1,2,3
---

 ||||||        | Frank van Beek
@ o  o @       | NeoGeo Computergraphics
   /           | voice: (+31) 40 461777, fax (+31) 40 464013
  `-'          | e-mail: frank@neogeo.nl


Received: from mailhost.tue.nl by rc6.urc.tue.nl with SMTP id AA29818
  (5.65c/IDA-1.4.4 for <wmbfmk@rc6.urc.tue.nl>); Fri, 12 Feb 1993 17:51:59 +0100
Received: from sun4nl.nluug.nl by mailhost.tue.nl with SMTP id AA29067
  (5.65c/IDA-1.4.4 for <wmbfmk@urc.tue.nl>); Fri, 12 Feb 1993 17:54:33 +0100
Received: from neogeo by sun4nl.nluug.nl via EUnet
        id AA02897 (5.65b/CWI-3.3); Fri, 12 Feb 1993 17:51:19 +0100
Received: by neogeo.nl (920330.SGI/920502.SGI.AUTO)
        for sun4nl!urc.tue.nl!wmbfmk id AA05272; Fri, 12 Feb 93 17:41:16 +0100
Date: Fri, 12 Feb 93 17:41:16 +0100
From: neogeo!frank@relay.nluug.nl (Frank van Beek)
Message-Id: <9302121641.AA05272@neogeo.nl>
To: wmbfmk@urc.tue.nl
Subject: testing

4,5,6

---

   ||||||     | Frank van Beek
  @ o  o @    | NeoGeo Computergraphics
     /        | voice: (+31) 40 461777, fax (+31) 40 464013
    `-'       | e-mail: frank@neogeo.nl



What happens if all unknown mail is copied to neogeo.nl (sun4nl)?


TU:
	2400
					\n \n
	Accesscode: 
					wmbfmk
	Password: 
	
	Dialin TUE> 
					c 300
	SESSION 1 CLOSED TO A058,0
					\n
	RC_server_05>
					c ultrixrc
	login: 
					wmbfmk
	Password:
	



From IRIS:

From frank@iris.neogeo.nl Sat Feb 13 18:38:07 1993
Received: from mailhost.tue.nl by rc6.urc.tue.nl with SMTP id AA09768
  (5.65c/IDA-1.4.4 for <wmbfmk@rc6.urc.tue.nl>); Sat, 13 Feb 1993 18:38:00 +0100
Received: from sun4nl.nluug.nl by mailhost.tue.nl with SMTP id AA01546
  (5.65c/IDA-1.4.4 for <wmbfmk@urc.tue.nl>); Sat, 13 Feb 1993 18:40:40 +0100
Received: from neogeo by sun4nl.nluug.nl via EUnet
        id AA16613 (5.65b/CWI-3.3); Sat, 13 Feb 1993 18:37:26 +0100
From: frank@iris.neogeo.nl
Received: from iris.neogeo.nl by neogeo.nl via SMTP (920330.SGI/920502.SGI.AUTO)
        for sun4nl!urc.tue.nl!wmbfmk id AA06869; Sat, 13 Feb 93 18:36:33 +0100
Received: by iris.neogeo.nl (920330.SGI/920502.SGI.AUTO)
        for @neogeo.nl:wmbfmk@urc.tue.nl id AA18835; Sat, 13 Feb 93 18:36:43 +01
00
Date: Sat, 13 Feb 93 18:36:43 +0100
Message-Id: <9302131736.AA18835@iris.neogeo.nl>
To: wmbfmk@urc.tue.nl
Subject: Testing

7,8,9

---

   ||||||     | Frank van Beek
  @ o  o @    | NeoGeo Computergraphics
     /        | voice: (+31) 40 461777, fax (+31) 40 464013
    `-'       | e-mail: frank@neogeo.nl


gui,forms library, buttons
Check out the Forms Library available by anonynous ftp at sol.cs.ruu.nl.
It has an excellent interface building tool, is designed for GL, and 
all the source code is available.


old installation /data + /fast:

----- partitions-----
part  type       cyls             blocks          Megabytes   (base+size)
  0: efs        5 + 1450       2940 + 852600        1 + 416  
  6: lvol    1455 + 352      855540 + 206976      418 + 101  
  7: efs        5 + 1802       2940 + 1059576       1 + 517  
  8: volhdr     0 + 5             0 + 2940          0 + 1    
 10: entire     0 + 1807          0 + 1062516       0 + 519  

old installation / + /usr + /fast:

----- partitions-----
part  type       cyls             blocks          Megabytes   (base+size)
  0: efs        5 + 55         2940 + 32340         1 + 16   
  1: rawdata   60 + 139       35280 + 81732        17 + 40   
  5: lvol    1455 + 352      855540 + 206976      418 + 101  
  6: efs      199 + 1256     117012 + 738528       57 + 361  
  7: efs        5 + 1802       2940 + 1059576       1 + 517  
  8: volhdr     0 + 5             0 + 2940          0 + 1    
 10: entire     0 + 1807          0 + 1062516       0 + 519  


- NFS performance from the entry point is poor:
/usr/etc/ping -f -s3000 indigo results in 13% packet loss.
- Test neogeo.neogeo.nl with MAIL enabled.
- Test the hard disk.


- Acknowledgments from `tracesd` could potentially circulate indefinitely (loop). 
  - Send acknowledgments as separate messages.
  - Include a length field with the messages.


Michael Toy: >POP UP MENU question                             24 Mar 93 00:24
In article <115324@netnews.upenn.edu> mark@ginger.biophys.upenn.edu (Mark Elliott) writes:
>
>       Can the font style and size be changed from the default in the
>defpup(), newpup(), dopup(), ... routines for creating GL pop-up menus?
>
>       This may sound like an obscure need, but I reeally would like to do it,
>and I can't find any clues in the man pages.

If you are running IRIX 4.0 or later, the answer is yes.
The man page which you couldn't find was "glresources".

Basically there is no programatic way to do what you want,
but you can edit your X resources the get what you want.
You can add

*gl*font: <some x font name>

to your .Xdefaults or .Xresources or however you do that,
to change all gl apps, or you can be more specific and change only
one program's font, details on that are in glresources(3).
If you want your program to do it, you could try something ugly
like

        putenv("GLRES=*gl*font: <some x font name>");

before your first winopen() call, but that won't work right with DGL.

diff -c provides a reasonably clear overview of the differences between files.

alarm: muziek

at 17
sfplay /usr/lib/sounds/prosonus/musictags/tag2.aiff
^D

versturen met sz:
\n
~$echo sz foo && rz -1bv

The -..v appears to be important (suppresses "rz ready ...")

codim
tar cOvf /dev/tapens *


       go to the directory /usr/lib/X11/xdm
        open the file "xdm-config"
        change the line 
             "DisplayManager._0.terminateServer:      False"
     to
           "DisplayManager._0.terminateServer:      True"

> No.  The user sent a job to the printer, went to pick it up, and 
> returned to find his system hung.  (I don't know if the print was 
> successful.)  After I tried to log in over the net unsuccessfully,
> I told him to reset. 


Try `rsh sickhost exec csh -i`.

I recently saw a sick machine that seemed to be hung, but
where that old trick worked.  That trick starts a shell
without using any STREAMS stuff, unlike rlogin and telnet.

If for some reason the system is out of STREAMS buffers,
perhaps because a serial line printer is crazy, you can
use this trick to do things like `netstat -m` to diagnose it.


Vernon Schryver,  vjs@sgi.com


Trace extensions:

- Z-buffering for spotlights (cone)


What Goof needs:

binhex4.bin
unstuffit.bin
tar

When using MacZip, do not position yourself within the directory you intend to zip.

Zip archive name: New Zip file > font.zip
Filename storage: Recurse into directories
Storage method: Store all files
Modify Zip entries: Normally

/FontName = filename

deleting a breakpoint in edge

> status 
xxxx [Y] xxxxx
> delete Y

4Dwm &
libXm Error: xmUninitialized: SHOULDN"T GET HERE


Priya
St Gerlachstraat 25
5643 NJ Eindhoven
2119960

Frens
Willem de Zwijgerstraat 55
5616 AD Eindhoven
2432434 / 2448861


Erwin
Ohmstraat 10 II
1098 ST Amsterdam
020-6639664
Amstelstation buslijn 15 richting Ajaxstadion

Peter en Toby 03404-31521

Ruth Grange en Pascal van den Hurk
Ambachtslaan 130
5506 AK Veldhoven
2540462

Jacki en Jerome
Prins Hendrikstraat 3
5611 HH Eindhoven
2465948 / 2452214

Angelique
Kaneelstraat 8a
5612 LJ Eindhoven
463667 / 386424

Albert en Bettien
Auvergnelaan 44
5627 ES Eindhoven
410014

Paps
Locomotiefstraat 65
5641 TS Eindhoven

Ans en Herman
W Alexanderlaan 15
6026 BN Maarheeze
04959 2060

Frans en Inge
v Rijcke Vorsellaan 65
5673 ND Nuenen

Diederik Martius
Hemelrijken 20
5612 LD Eindhoven
441874

Hannus en Simon
Juliusstraat 12
5621 GD Eindhoven

Sjan van Overbruggen
Ambachtslaan 24
5506 AH Veldhoven

Annie en Arie Reynout
A der Kinderentraat 24
5613 JM Eindhoven

Helga, WP en Judith
Schelfhoutstraat 13
5642 LT Eindhoven
817534

Toon van Overbruggen
Pijlstaartpad 29
5641 GV Eindhoven

Niels en John
Paulus Potterstraat 21
5613 KR Eindhoven

Ruud en Cida
Weserlaan 6
5691 MJ Son
04990-60553

Sven van Sweden
Violierstraat 1
5644 PW Eindhoven
121465

Tandarts Verberne
Uiverlaan
2432029

Vincent
427670 Farna / Pepijn 

Ruud and Andrea
00 33 85246722 / 85246808
From the toll road (péage), take the Chalon-Sud exit
Head towards Montceau-les-Mines
Follow signs for the town centre
Then follow signs for Cluny / Mâcon
Continue past Montcen-Vincent
Turn right 500 metres *after* the "Le Rousset" sign; take the right-hand turn (on a bend) towards Les Essarts
Head uphill, then turn left at the top; you will see the house
"Che Mimi" – or look near the petrol station

Ricki has the wooden slats for the floor
  : 126658, call around 12:00 PM
  St. Gerardusplein 10
After that, pick up clothes from Ruud’s mother
Then, pick up other items from Andrea’s mother

Washing machine.

Procedure for installing a new computer:

IN ALL CASES

- Choose a name and Ethernet address
	- /etc/hosts ensure consistency across old and new systems
	- /etc/sys_id configure
	-  Set the Ethernet address in NVRAM (`/etc/nvram -v netaddr 100.100.100.??`)
- Launch `cdinstmgr` on the server
	- Shut down and perform an NFS-based installation via the network using the miniroot
	(this can be done via FTP at 100.100.100.1):
	- Set up and adjust `/etc/fstab`
	- Set up and adjust `/etc/exports`
	- Mount the hard disks
- Create the `/var2` directory
	Move the directories `/usr/gfx`, `/usr/cpu`, and `/usr/lib/X11/dyDDX` to this location
	Create symbolic links from the original locations pointing to the new ones
- Modify and copy `/etc/cshrc`
- Copy `/.cshrc`, `/.forward`, and `/.ziprc`
- Copy `/etc/passwd`, `/etc/passwd.sgi`, `/etc/services`, and `/etc/group`
- Install traces
- Set `/usr/lib/X11/xdm/Xservers` to 24-bit mode
- Copy `/var/Cadmin/clogin.conf`
- Copy `/usr/lib/aliases` (?)


- initialize email
	cd /usr/lib
	cp sendmail.cf sendmail.cf_oud
	cp sendmail.cf.auto sendmail.cf
	configmail setup
		sun4nl
		yes
		
- set gamma
- crontabs (fsr, mkTIMEZONE)
- set TIMEZONE

- modify /etc/group ??
- install xmailtool
  copy /usr/lib/X11/xmailtool.help
  copy /usr/lib/X11/app-defaults/XMailTool
- install flexfax
  add name to /usr/spool/fax/etc/hosts
- install vfr software
- install impressario and printers
  check if /var/scan exists; if not, copy it from another computer
- install RLamiga (termcap ??)
- virtual swap /etc/chkconfig on

on the server:

- link imbuf & include/local
- set gamma to setuid
- install xmailtool
  copy /usr/lib/X11/xmailtool.help
  copy /usr/lib/X11/app-defaults/XMailTool
- install flexfax
  add name to /usr/spool/fax/etc/hosts
- install vfr software
- install impressario and set up printers
- install RLamiga (termcap ??)


--------------------------------------------------------------------

In the ImBuf, you need to be able to specify how you want an image to be represented:

- with or without (premultiplied) alpha
- colormap, 24-bit, black and white
- bitplanes or rect
- RGB or YUV
- format
- upside down / rotated / normal


/usr/sbin/Add_disk:


#!/bin/sh
#Tag 0x00000600
# Note that this script is limited to SCSI drives, and only those
# on controller 0.
# It makes the filesystem on partition 7 for option drives, creates
# the mount directory, and an fstab entry for the drive, then mounts it.

if [ $# -gt 1 ]
then
	echo "Usage $0 [disk_number]"
	exit 1
elif [ $# -eq 0 ]
then
	NUM=2
elif [ $1 -le 1 ]
then
	echo "The disk number needs to be greater than 1."
	exit 1
else
	NUM=$1
fi

echo "\nAdding SCSI disk"$NUM".."

hinv -c disk | grep -s "unit $NUM on SCSI controller 0" > /dev/null 2>&1
if [ $? -ne 0 ]
then echo SCSI disk $NUM not found on controller 0
	exit 1
fi

/etc/fsstat /dev/dsk/dks0d"$NUM"s7 > /dev/null 2>&1
s7=$?
/etc/fsstat /dev/dsk/dks0d"$NUM"s6 > /dev/null 2>&1
s6=$?
/etc/fsstat /dev/dsk/dks0d"$NUM"s0 > /dev/null 2>&1
s0=$?
if [ $s7 -ne 3 -o $s6 -ne 3 -o $s0 -ne 3 ]
then
	echo "\007SCSI disk $NUM appears to have a valid filesystem, overwrite it? (n)\c"
	read answer
	case "$answer" {
	y|Y|yes|Yes|YES) ;;
	*) echo Disk $NUM not added; exit 1;;
	}
fi

# unmount it by disk name, in case it is mounted on a different mount pt.
umount /dev/dsk/dks0d"$NUM"s7 > /dev/null 2>&1

# create the links to the device files
ln /dev/dsk/dks0d"$NUM"s7 /dev/disk$NUM  > /dev/null 2>&1
ln /dev/rdsk/dks0d"$NUM"s7 /dev/rdisk$NUM > /dev/null 2>&1

# make the new filesystem
mkfs /dev/rdisk$NUM > /dev/null 2>&1
if [ $? -ne 0 ]
then
	rm -f /dev/disk$NUM /dev/rdisk$NUM
	echo Unable to create a filesystem on SCSI disk $NUM
	exit 1
fi

# create directory
if [ ! -d /disk$NUM ]
then
	rm -f /disk$NUM
	mkdir /disk$NUM
fi

# add the entry to /etc/fstab (ignore commented out lines!)
# make sure that the mount point matches also; if it was mounted
# as something else before, the 2nd mount attempt on next boot
# will at least print an error message
egrep -s "^/dev/disk$NUM[ 	][ 	]*/disk$NUM[ 	]" /etc/fstab > /dev/null 2>&1
if [ $? -ne 0 ]
then
	echo "/dev/disk$NUM /disk$NUM efs rw,raw=/dev/rdisk$NUM 0 0" >> /etc/fstab
fi
sync

# label the disk with its directory name
labelit /dev/rdisk$NUM disk$NUM sgi > /dev/null 2>&1

# mount the filesystem
if mount -v /disk$NUM
then echo "\nNew disk ready to use as /disk"$NUM"."; exit 0
else echo "\007Failed to mount disk$NUM"; exit 1
fi

File types are now available on the Iris!

- Origin traces -> float
- Ability to set duration / cyclic / start frames on multiple bases simultaneously
- When a sample in the shadow buffer falls within the soft-edge area, could we use the difference between the surface normal and the shadow-surface normal to determine if self-shadowing is occurring?
- Allow the user to define the relationship between 7, 1, and 3.
- Stars do not react to the sky buffer!
- 'Assign' (colors) remains active outside of edit mode, even though it performs no function there.
- 'Cyclic' for paths should be off by default. Path length should default to the total animation length or the last-set length of a path.
- For spotlights, use Z-buffering on the cone to check if objects fall within the beam. For spotlights that cast shadows, automatically adjust and cap the clip start/end values.
- Could we automatically calculate clip start/end (min/max) values ​​before performing the Z-buffer pass for shadows? (Note: this could be risky if anything in the scene changes.)
- If halo intensity is set to 0, disable halo rendering.

The saver sometimes attempts to close 'window = 0', which implies it has already been closed.

When I type 'exportfs -i /CDROM', all I get is:

directory filename
'basename' and 'dirname' return parts of the filenames.


frames for codim: rl7
(these figures are subject to change)
  12.5 frames / sec = 5 sectors = 11620 bytes / frame
  10.0 frames / sec = 6 sectors = 13944 bytes / frame


Floyd-Steinberg dithering in PostScript:

psrip in /usr/spool/lp/interface/color

header is 350 bytes
Changes made:
Width: word at 0x20; strips at 0xf0 – 0x110
Height: word at 0x2c; strips at 0xf0 – 0x110
Depth: 0x5b; strips at 0xe0 – 0x110


MPEG:
Encoding -
  mpeg -a 0 -b 599 -CIF -s /pics/kasteel.mpg -r 1220100 /pics/mpeg_yuv/
Decoding -
  mpeg -d -s kastgroot.mpg /pics/kast1/
Restoring -
  frommpeg -l 1536 288 /pics/kast1/0 /pics/kunstgeb/000
  scalecdi -x 352 -y 288 -n -rgb *


Berkeley MPEG:

  logarithmic: 76 min
  subsample: 657 min
  twolevel: 240 min


logarithmic:

TIME COMPLETED:  Sun Nov 28 23:20:40 1993
Total time:  49 minutes and 51 seconds

-------------------------
*****I FRAME SUMMARY*****
-------------------------
  Blocks:    15840     (2761205 bits)     (  174 bpb)
  Frames:       40     (2765456 bits)     (69136 bpf)     (31.1% of total)
  Compression:   35:1
  Seconds:         95     (        2 spf)     (  1018889 bps)
-------------------------
*****P FRAME SUMMARY*****
-------------------------
  I Blocks:   3175     (661342 bits)     (  208 bpb)
  P Blocks:  54908     (3169710 bits)     (   57 bpb)
  Skipped:    5277
  Frames:      160     (3849184 bits)     (24057 bpf)     (43.3% of total)
  Compression:  101:1
  Seconds:        662     (        4 spf)     (   587376 bps)
-------------------------
*****B FRAME SUMMARY*****
-------------------------
  I Blocks:    140     ( 15283 bits)     (  109 bpb)
  B Blocks:  118933     (2220830 bits)     (   18 bpb)
  Skipped:   38535
  Frames:      398     (2281312 bits)     ( 5731 bpf)     (25.6% of total)
  Compression:  424:1
  Seconds:       3446     (        8 spf)     (   280938 bps)
---------------------------------------------
Total Compression:  163:1
Total Frames Per Second:  0.199933
Total Output Bit Rate (30 fps):  446368 bits/sec


chksupport (versions filelisting)
list files installed by an installation
example:
  /usr/etc/chksupport list impr_fonts "*"


you can examine file-type rules using `wstype`

you can open a pipe to a command using `popen`. This allows `stdout` to be
directed to your pipe (for example). (see example)

changes:

/usr/lib/uucp/Devices ttyd1 -> ttyf1
/usr/spool/fac/FIFO.ttyd1 -> ttyf1 (stop and start `faxd`)
alias `tue`, `tin`

nice explosion in black:
solar crisis / filmland ehv

bar height set to 7.8

Lily de Rooy, mascot, landlady
Sparrenlaan 18 (??)
tel: 04902-15042

Martin’s insert images:
226 at 1:33:00
411 at 1:40:10
541 at 1:45:15

if the entry is removed:
	/etc/chkconfig timeslave on
	/etc/chkconfig timed off
	/etc/exports to adjust

Both the backup script and the file system (FS) attempt to delete linked directories as if they were directories, rather than as files.

The MO (magneto-optical) drive must also be mountable in a write-protected state: if the MO disk becomes too hot, it could be damaged by the file system routines (FSR).

faqs:

rtfm.mit.edu : /pub/usenet/comp.answers /pub/usenet/alt.answers etc
svin01.info.win.tue.nl : /pub/usenet
					in   /pub/news software, readers etc.
ftp.win.tue.nl                 /pub/usenet/news.answers

Highlight in NN : ^[[1mRe: Idea to speed raytracing^[[m

initialiseren van mo

fx -x
	dksc
	0
	4
	[r]epartition
		[o]ptiondrive
		yes
		..
	exit

mkfs /dev/dsk/dks0d4s7
mount /mo
mkdir "/mo/.. ??_? .."
chmod 000 "/mo/.. ??_? .."
chgrp user /mo
chmod g+w /mo


Handmade by Floyd Steinbergen
															  Input																							Output
/usr/lib/print/psrip -P color_floyd -B 8 -C cmy -F chunky -I /usr/lib/print/data//PSRIPprolog /render/raboschuif/stills/wikkel.ps | /usr/people/bin/floyd > /render/stiff

BECOME A SUPERUSER!
	Output													 				     Copy's
cat /render/stiff | /usr/lib/print/deskjet -P color_floyd -S A4 -X 300 -Y 300 -n 2
cat /tmp/stiff | /usr/lib/print/deskjet -P color_floyd -S legal -X 300 -Y 300 -n 1


North Valley Research - video and other time-based media in a UNIX environment
        North Valley Research; 15262 NW Greenbriar Pkwy; Beaverton, OR  97006
        Phone (503) 531-5707, Fax (503) 690-2320. Todd Brunhoff <toddb@nvr.com>
(503) 236-6121 Don Hershiser

     odump - dumps selected parts of an object file

              - Additions to the MANPATH environment variable

                 If you set the MANPATH environment variable, add
                 two new directories to look for manual pages:
                 /usr/share/catman and /usr/share/man.  These two
                 new directories should be searched before the
                 /usr/catman and /usr/man directories to ensure
                 that the newer manual pages are displayed first.
                 The man(1) command has been modified to search
                 /usr/share/catman, /usr/share/man then /usr/catman
                 and /usr/man, if MANPATH has not been defined in
                 your environment.  Refer to man(1) for more
                 information.

             - Keystroke Composition

                 Under X, IRIX 5.0.1 and later releases allow users
                 to generate characters that are not present on a
                 keyboard by using sequences of other keys.

                 Composition is performed via the Multi key X
                 keysym, which designates the ``compose'' key.  To
                 remain compatible with the IBM PC/AT layout, the
                 default IRIX keymaps do not specify a compose key,
                 but you can add one with xmodmap(1). For example,
                 to make the <Scroll Lock> key behave as
                 ``compose,'' use the command:

                 xmodmap -e "keysym Scroll_lock = Multi_key"

                 Composition is regulated by compose tables, which
                 may vary from locale to locale or from user to
                 user.  A typical composition for, say, the letter
                 N-tilde might be <Multi_key>, <N>, <~>.
                 Composition sequences are intended to be
                 intuitive.

Errors on the Iris:

	Jul  3 05:19:59 4A:iris unix: WARNING: Gr1PcxSwap: TIMEOUT GE not ready for swap
	Jul  3 05:19:59 2A:iris unix: 
	Jul  3 05:19:59 2A:iris unix: 
	Jul  3 05:19:59 4A:iris unix: WARNING: Graphics error: base = 0xbf000000  GE PC = 1163
	Jul  3 05:19:59 2A:iris unix: 
	Jul  3 05:20:00 3B:iris xdm[310]: Server for display :0 terminated unexpectedly: 2304
	
	Jul  4 00:11:26 2A:iris unix: GR1FIFOHandler: TIMEOUT (FIFO still > half full)!
	Jul  4 00:11:26 2A:iris unix: 
	Jul  4 00:11:26 4A:iris unix: WARNING: Graphics error: base = 0xbf000000  GE PC = 1765
	Jul  4 00:11:26 2A:iris unix: 
	Jul  4 00:11:27 3B:iris xdm[310]: Server for display :0 terminated unexpectedly: 2304

mirte, priya, frens
	05219-1782 (1764)


Upline
van Egmond
Aalsterweg

fout:
# stty < /dev/ttyf2
speed 19200 baud; -parity hupcl 
line = 1; eof = ^A; eol = ^A; old-swtch = ^@; susp = ^@; dsusp = ^@; 
-inpck -istrip -ixon -opost 
-isig -icanon -echo -echoe -echok -echoctl 

goed:
# stty < /dev/ttyf2
speed 38400 baud; -parity hupcl clocal 
line = 1; eof = ^A; eol = ^A; old-swtch = ^@; susp = ^@; dsusp = ^@; 
-inpck -istrip -ixon -opost 
-isig -icanon -echo -echoe -echok -echoctl 

na uucp nog steeds goed:
# stty < /dev/ttyf2
speed 19200 baud; -parity hupcl clocal 
line = 1; eof = ^A; eol = ^A; old-swtch = ^@; susp = ^@; dsusp = ^@; 
-inpck -istrip -ixon -opost 
-isig -icanon -echo -echoe -echok -echoctl 


btw belastingnummer

91.03.557.B.01


parity error in Simm S8 on the quad.
2 * parity error in Simm S7 on the quad
parity error in Simm B3 on the xs.

Oct 15 16:22:20 2A:neogeo unix: Recoverable parity error at or near physical address 0xb7547f0 <0x320>, Data: 0x100/0x0
Oct 15 16:22:20 2A:neogeo unix: 
Oct 15 16:22:20 1A:neogeo unix: ALERT: Memory Parity Error in SIMM  S8 [HELP=MEM_ERROR]
Oct 15 16:22:20 2A:neogeo unix: 

Oct 14 23:17:05 2A:neogeo unix: Transient parity error at or near physical address 0xae93900 <0x308>
Oct 14 23:17:05 2A:neogeo unix: CPU Error/Addr 0x308<RD PAR >: 0xae93900
Oct 14 23:17:05 2A:neogeo unix: 
Oct 14 23:17:05 1A:neogeo unix: ALERT: Memory Parity Error in SIMM  S7 [HELP=MEM_ERROR]
Oct 14 23:17:05 2A:neogeo unix: 
Oct 14 23:17:05 2A:neogeo unix: 
Oct 14 23:17:05 1A:neogeo unix: ALERT: Process 11716 [traces] sent SIGBUS due to Memory Error in SIMM  S7 [HELP=MEM_ERROR]
Oct 14 23:17:05 2A:neogeo unix: 	at Physical Address 0xae93900, Data: 0x49ba7779/0xbeba2226
Oct 14 23:17:05 2A:neogeo unix: 
Oct 14 23:20:18 2A:neogeo unix: Transient parity error at or near physical address 0xae93900 <0x308>
Oct 14 23:20:18 2A:neogeo unix: CPU Error/Addr 0x308<RD PAR >: 0xae93900
Oct 14 23:20:18 2A:neogeo unix: 
Oct 14 23:20:18 1A:neogeo unix: ALERT: Memory Parity Error in SIMM  S7 [HELP=MEM_ERROR]
Oct 14 23:20:18 2A:neogeo unix: 
Oct 14 23:20:18 2A:neogeo unix: 
Oct 14 23:20:18 1A:neogeo unix: ALERT: Process 11716 [traces] sent SIGBUS due to Memory Error in SIMM  S7 [HELP=MEM_ERROR]
Oct 14 23:20:18 2A:neogeo unix: 	at Physical Address 0xae93900, Data: 0x49cfbe1b/0xbeab87cd
Oct 14 23:20:18 2A:neogeo unix: 

Oct 20 15:50:40 2A:neogeo unix: Transient parity error at or near physical address 0xaf67900 <0x308>
Oct 20 15:50:40 2A:neogeo unix: CPU Error/Addr 0x308<RD PAR >: 0xaf67900
Oct 20 15:50:40 2A:neogeo unix: 
Oct 20 15:50:40 1A:neogeo unix: ALERT: Memory Parity Error in SIMM  S7 [HELP=MEM_ERROR]
Oct 20 15:50:40 2A:neogeo unix: 
Oct 20 15:50:40 2A:neogeo unix: 
Oct 20 15:50:40 1A:neogeo unix: ALERT: Process 7364 [iv] sent SIGBUS due to Memory Error in SIMM  S7 [HELP=MEM_ERROR]
Oct 20 15:50:40 2A:neogeo unix: 	at Physical Address 0xaf67900, Data: 0x7b943984/0x9c428ca5
Oct 20 15:50:40 2A:neogeo unix: 


Extreme: 52,000 upgrade
One week -> 7% / month: 50,000 / month
Tools for performer: 20,000 (level of detail)


EDC print resolution: 300 DPI, max 84 x 118.80 cm
In pixels, this is: 9921 x 14031

Scaled at 1/6: 2338 x 1653
In multiples of 16: 2336 x 1648
The image size (for a 'Frame It' mat/passe-partout) then becomes 82.5 x 116.5

Scaled at 1/5: 2800 x 1984
Scaled at 1/4: 3504 x 2480

You can use 'tr' to convert input characters into output characters.

Sun = convenient (administration-wise), but not fast.
DEC = a disaster (in terms of both software and administration).

Removed: showcase / systour

Feb 21 19:57:31 1A:iris unix: ALERT: Parity Error in SIMM B1  [HELP=MEM_ERROR]
Feb 21 19:57:31 2A:iris unix: 
Feb 21 19:57:31 2A:iris unix: 
Feb 21 19:57:31 1A:iris unix: ALERT: Process 28801 [render] sent SIGBUS due to Memory Error in SIMM B1  [HELP=MEM_ERROR]
Feb 21 19:57:31 2A:iris unix: 	Physical Addresses 0x2000000 and 0x23fffff
Feb 21 19:57:31 2A:iris unix: 
Feb 21 20:06:27 1A:iris unix: ALERT: Parity Error in SIMM B1  [HELP=MEM_ERROR]
Feb 21 20:06:27 2A:iris unix: 
Feb 21 20:06:27 2A:iris unix: 
Feb 21 20:06:27 1A:iris unix: ALERT: Process 29232 [render] sent SIGBUS due to Memory Error in SIMM B1  [HELP=MEM_ERROR]
Feb 21 20:06:27 2A:iris unix: 	Physical Addresses 0x2000000 and 0x23fffff
Feb 21 20:06:27 2A:iris unix: 
Feb 21 20:09:03 1A:iris unix: ALERT: Parity Error in SIMM B1  [HELP=MEM_ERROR]
Feb 21 20:09:03 2A:iris unix: 
Feb 21 20:09:03 2A:iris unix: 
Feb 21 20:09:03 1A:iris unix: ALERT: Process 29258 [render] sent SIGBUS due to Memory Error in SIMM B1  [HELP=MEM_ERROR]
Feb 21 20:09:03 2A:iris unix: 	Physical Addresses 0x2000000 and 0x23fffff
Feb 21 20:09:03 2A:iris unix: 


vacation days

1994
    15 vacation days
    2 days between Christmas and New Year’s

1995
    2 days for renovations at ‘Kleine Bleek’
    2 days visiting Ruud and Andrea
    1 day for Carnival
    __
    22 days -> 4 remaining

    26 vacation days for 1995
    4 still remaining from ’94
    __
    30

    +8 overtime (Schiphol II)
    -3 days for moving

    -15 vacation in Portugal
    +2 overtime (Wiard)
    __
    22

    +12 overtime (Morkramia)
    -5 days away in December
    __
    29

    3 days of overtime paid out
    __
    26	as of Jan 1, 1996
    -1	January 2nd

    __
    25


hp-support : 020 - 6816473
	printer serial number

man gmatch : pattern matching *[a-z]


Ohra Winkel
Hans Verbakel
Leenderweg 95
5614 HL  Eindhoven
125555


frame rates mpeg:
{1.0, 23.976, 24.0, 25.0, 29.97, 30.0, 50.0 ,59.94, 60.0};

MPEG defaults according to nob

				Video CD	CDi Full motion Video
		
resol			352x288		368x272
bitrate			1.15 Mbit	1.18 Mbit
vid buf			40960 kB	40960 kB	(kilo Bytes ?? dat is veel)
audio coding	layer 2		layer 2
sampl freq		44.1 kHz	44.1 kHz
audio bitrate	224 kbit/s	192 kbit/s
syst bitrate	1.4112 Mbit	1.4112 Mbit

program for identifying the boot partition under MS-DOS : os-bs135.exe

mac-syquest mounting:
	mount -t hfs /dev/rdsk/fds0d6.48 /syquest/
of:	mount -t hfs /dev/rdsk/dks0d6vol /syquest/
mac-syquest formatting:
	mkfp -t hfs /dev/rdsk/fds0d6.48

PTT error code: 06-0407

Indigo 2 has a 50-pin high-density connector
Indigo / Iris has a Centronics connector

Karseboom 2439597

Nov 21 18:26:49 2A:indi unix: GIO Error/Addr 0x108:<RD > 0xba76818
Nov 21 18:26:49 1A:indi unix: ALERT: Parity Error in SIMM  S4A
Nov 21 18:26:49 2A:indi unix: 
Nov 21 18:26:49 2A:indi unix: Process 20997 [imp] sent SIGBUS due to Memory Error in SIMM  S4A
Nov 21 18:26:49 2A:indi unix: 	at Physical Address 0xba76818, Data: 0x80000000/0x0

Hoi frank,

The following appeared in my console this morning. Not that you can do much with it (I suppose), but it’s always good to know.


IO Error/Addr 0x101:<RD > 0xb9e2d1c
ALERT: Parity Error in SIMM  S4A

Process 8917 [traces] sent SIGBUS due to Memory Error in SIMM  S4A
        at Physical Address 0xb9e2d1c, Data: 0x1003cd3c/0x1

-- 
Groetje Paul

Instellen TV
i+ / 5 / Volume+ / TV-symbool
(TV gaat aan)
Scart-symbool / Menu
	Ver Size	25
	Ver Breath	00
	Pin Ampl	06
	Par Tilt	32
	V linear	32
	Corn corr	00
	Vcen or EW	22
	V position	50
	H Centre	41
	Blue HWB	13
	Green HWB	17
	Red HWB		23
	B&W Delay	00

AGC 52
PLL 45

799,- PlayStation + joystick + 1 game
Bart Smit (Hardware)
Hoogstraat Replay (Games)
Hermanus Boekxstraat Superclub (expensive)
InterToys / V&D

pixar / toystory

copying /onyx

	update nfsmountpoints in /net/ and /
	rename /.desktop-foo.neogeo.nl
/etc
	fstab
	exports
	sys_id
	lvtab
	rc0.d/*
	rc2.d/*
	config/*

/var/spool
	cron/crontabs
	lp

create symbolic links in /usr pointing to /backup
