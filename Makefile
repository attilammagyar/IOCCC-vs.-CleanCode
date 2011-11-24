TESTS=

RM=rm
DIFF=diff -u
CFLAGS=-ansi -O -Wall
CC=gcc

makarios: makarios.c
	${CC} ${CFLAGS} -o makarios makarios.c

check: makarios
	./makarios | ${DIFF} "expected_output.txt" - >&2

clean:
	$(RM) -f *.o makarios tests/*.test
