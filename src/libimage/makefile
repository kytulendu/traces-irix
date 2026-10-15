# This makefile generates libimage.so from libimage.a, which we
# need in order to work around a Global Offset Table problem with large
# vcs derived executables.

TARGETS	= libimage.so
LDIRT = so_locations

default exports: $(TARGETS)

#
# Nothing to install; we'll leave libimage.so in place for now.  Eventually
# it might need to be installed if we run into an inst boot-phase problem
# when creating images.
#
install : default
	
libimage.so: /usr/lib/libimage.a
	ld -soname libimage.so -elf -shared -all /usr/lib/libimage.a \
	-lc -o libimage.so
