LIBS=./lib/primes.c
TESTS=

RM=rm
DIFF=diff -u
CFLAGS=-ansi -O -Wall -I .
CC=gcc

makarios: makarios.c
	${CC} ${CFLAGS} -o makarios ${LIBS} makarios.c

check: makarios
	./makarios | ${DIFF} "expected_output.txt" - >&2

clean:
	$(RM) -f *.o makarios tests/*.test
