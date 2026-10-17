# Traces


# Building the source code on IRIX 5.3

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

some program required FORMS library

# Directory layout

    /usr/people/bin/            binaries go here
    /usr/people/blend/          copy blenderbuttons here
    /usr/people/traces/         this repo
    /usr/people/traces/scenes/  sample scene from Traces Amiga version

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


