LIBS=./lib/primes.c \
	./lib/palindromes.c

TESTS=tests/test_primes \
	tests/test_palindromes

RM=rm
DIFF=diff -u
CFLAGS=-ansi -O -Wall -I .
CC=gcc

makarios: makarios.c
	${CC} ${CFLAGS} -o makarios ${LIBS} makarios.c

unit_tests:
	(	for test in ${TESTS}; \
		do \
			${CC} ${CFLAGS} -o "$$test.test" ${LIBS} "$$test.c" || exit 1; \
		done; \
	)

check: makarios unit_tests
	(	for test in ${TESTS}; \
		do \
			"$$test.test" || exit 1; \
		done; \
	) \
	&& ./makarios | ${DIFF} "expected_output.txt" - >&2

clean:
	$(RM) -f *.o makarios tests/*.test