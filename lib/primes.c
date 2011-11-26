#include "primes.h"

#include <math.h>
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
	int divisor_candidate = 3,
		signum = (number < 0) ? -1 : 1,
		absolute_value = abs(number),
		square_root = (int)sqrt((double)absolute_value) + 1;

	if (is_divisable(absolute_value, 2))
		return signum * 2;

	while (!is_divisable(absolute_value, divisor_candidate))
	{
		divisor_candidate += 2;
		if (divisor_candidate > square_root)
		{
			divisor_candidate = absolute_value;
			break;
		}
	}

	return signum * divisor_candidate;
}

static int
is_divisable(int dividend, int divisor)
{
	return 0 == dividend % divisor;
}

