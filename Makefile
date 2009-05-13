# TODO:  Wow, everything hard-coded.  Nice.

test_run: test
	./test

test: test.c hexward.c hexward.h
	cc -I. -ggdb ${CFLAGS} -o test test.c hexward.c

libhexward.so: hexward.c hexward.h 
	cc -I. ${CFLAGS} -o libhexward.so -shared -fPIC -DPIC -DREENTRANT \
		hexward.c
