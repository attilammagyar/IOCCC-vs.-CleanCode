#include "primes.h"

#include <math.h>
#include <stdlib.h>

static int is_divisable_by_non_trivial_divisor(int number);

int
is_prime(int number)
{
	if (number == 0 || number == 1 || number == -1)
		return 0;

	return !is_divisable_by_non_trivial_divisor(number);
}

static int is_even(int number);
static int is_divisable(int dividend, int divisor);

static int
is_divisable_by_non_trivial_divisor(int number)
{
	int absolute_value = abs(number),
		square_root, divisor;

	if (is_even(absolute_value))
		return 2 != absolute_value;

	square_root = (int)sqrt((double)absolute_value) + 1;

	for (divisor = 3; divisor <= square_root; divisor += 2)
	{
		if (is_divisable(number, divisor))
			return 1;
	}

	return 0;
}

static int
is_even(int number)
{
	return !(number & 1);
}

static int
is_divisable(int dividend, int divisor)
{
	return 0 == dividend % divisor;
}

