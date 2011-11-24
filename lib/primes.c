#include "primes.h"

#include <stdlib.h>

static int find_divisor_closest_to_one(int number);

int
is_prime(int number)
{
	if (number == 0 || number == 1 || number == -1)
		return 0;

	return find_divisor_closest_to_one(number) == number;
}

static int is_divisable(int dividend, int divisor);

static int
find_divisor_closest_to_one(int number)
{
	/* OPTIMIZATION FIXME: The smallest divisor is always less than
						   the square root of the number. */

	int divisor_candidate = 2,
		signum = (number < 0) ? -1 : 1,
		absolute_value = abs(number);

	while (!is_divisable(absolute_value, divisor_candidate))
	{
		++divisor_candidate;
	}

	return signum * divisor_candidate;
}

static int
is_divisable(int dividend, int divisor)
{
	return 0 == dividend % divisor;
}

