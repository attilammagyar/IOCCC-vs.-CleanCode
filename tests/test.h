#include <stdio.h>
#include <stdlib.h>

int all_assertions = 0;
int failed_assertions = 0;

#define assert_equals_int(expected, actual) \
	do \
	{ \
		++all_assertions; \
		if (expected != actual) \
		{ \
			fprintf( \
				stderr, \
				"ERROR: Assertion failed.\n" \
				"    %s:%s():%d\n    Expected: %d\n    Actual: %d\n", \
				__FILE__, __func__, __LINE__, expected, actual \
			); \
			++failed_assertions; \
		} \
	} while (0)

#define assert_true(actual) assert_equals_int(1, actual)
#define assert_false(actual) assert_equals_int(0, actual)

#define finish_testing() \
	do { \
		if (0 < failed_assertions) \
		{ \
			fprintf( \
				stderr, \
				"\n%d/%d assertions failed.\n",\
				failed_assertions, all_assertions \
			); \
			exit(1); \
		} \
		else \
		{ \
			fprintf(stderr, "PASS: %s\n", __FILE__); \
			exit(0); \
		} \
	} while (0)
