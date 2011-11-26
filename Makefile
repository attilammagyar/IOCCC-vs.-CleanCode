LIBS=./lib/primes.c \
	./lib/palindromes.c \
	./lib/octal_palindromic_primes.c

TESTS=tests/test_primes \
	tests/test_palindromes \
	tests/test_octal_palindromic_primes

RM=rm
DIFF=diff -u
CFLAGS=-lm -ansi -O3 -Wall -I .
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

performance:
	(	for type in original refactored; \
		do \
			${CC} ${CFLAGS} -o perf_$$type ${LIBS} ./tests/performance/perf_$$type.c || exit 1; \
		done; \
	)

clean:
	$(RM) -f *.o makarios perf_original perf_refactored tests/*.test
