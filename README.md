# Traces

Traces is an ancient in-house 3D modeling, animation, and ray tracing software from the '90, developed by the Dutch animation studio NeoGeo. Later this software become [Blender](https://www.blender.org/).

Originally develop for Commodore Amiga, later was ported to Silicon Graphics workstation.

Source code and some compiled binaries originally released on [Official Blender source code archive](https://download.blender.org/source/chest/) in file `neogeo.tar.gz`.

The IRIX binaries from `neogeo.tar.gz` required `libimbuf.so` and `libimage.so` that didn't included in the tarball. While the source code for `libimbuf.so` did included, it's makefile require `libimbuf.so` to build, which are circular dependency problem.
I have untangle that problem and found it only used for building `make_convert` to generate `convert_arrays.h`, which `convert_arrays.h` is already included in the source code tarball.

For `libimage.so`, it is dynamic library version of `libimage.a`, which can be install from IRIX 5.3 IDO and can just link it to a dynamic library.

Some changes to the source code other than to make the source code compile:

- Update jpeg library from v6a to v6b.
- Re-enable IGES and Cyberware Digitizer Data support.

  In IGES code, `DL_POINT` type is not exist, even in newer version of blender. I have assign it as `DL_SEGM` as a guess.


# Building the source code on IRIX 5.3

It currently compile with `-mips2` flags, which the result binary will required R4000 CPU.

To compile for R3000 CPU, change `CFLAGS` variable in `makefile` from `-mips2` to `-mips1` and rebuild all source code.

**TODO: fix and compile all the remaining utility programs.**
**TODO: some program required FORMS library.**
**TODO: see about some of the hard coded paths in various places.**

- Install IRIX 5.3 IDO
- Open a terminal and change directory to `src/imbuf/`
- `make`
- Copy `libimbuf.so` and `libimbuf.a` to `/usr/lib/`
- `cd ../libimage`
- `make`
- Copy `libimage.so` to `/usr/lib/`
- `cd ../traces`
- `make`
- copy `traces_new` to `/usr/people/bin/traces`
- `cd ..`, the current directory will be at `src/`
- `make`
- copy the compiled binaries to `/usr/people/bin/`

# How to use Traces

TODO

# Directory layout

This was the directory layout that I used while fixing and compiling Traces on IRIX.

    /usr/people/bin/                    binaries go here
    /usr/people/blend/                  copy blenderbuttons here (if Blender 1.0 installed)
    /usr/people/khral/traces/           this repo
    /usr/people/khral/traces/scenes/    sample scene from Traces Amiga version
    /usr/people/khral/traces/src/       trace source code from this repo

# Some unused source code files

    src/traces/
    brender.c                   unfinished code
    makeblender.c               edit compiled traces in to blender
    oud.c                       experimental code
    performance.c               cpu benchmark
    psfont405.c                 psfont.c for IRIX 4.0.5
    rt.c                        for testing Normalise function
    stars.c                     make_stars function
    tab.c                       for testing makekeytab function
    test.c                      for testing qsortN2 function
    verditSort.c                older or experimental? version of verdit.c

# Information about Traces

[TRACES - The beginnings of Blender](https://www.youtube.com/watch?v=_WH0arC4cDw) on SGI Indy

[Traces, Blender from 1995](https://www.youtube.com/watch?v=wreHFveYdDg) on SGI Indy

[Traces (Amiga version) on GitHub](https://github.com/Endertainer007/Traces_Amiga)

[Blender's prehistory — Traces on Commodore Amiga (1987–1991)](https://zgodzinski.com/blender-prehistory/)

[Traces (Blender's Predecessor)](https://www.youtube.com/watch?v=glhi_l2VDVE) on Amiga

[Traces Tutorial - Blender Bach](https://www.youtube.com/watch?v=zKn8qjgG1YA) on Amiga
