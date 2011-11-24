#include "primes.h"

static int find_smallest_divisor_greater_than_one(int number);

int
is_prime(int number)
{
	/* FIXME: handle 0 and 1 */
	return find_smallest_divisor_greater_than_one(number) == number;
}

static int is_divisable(int dividend, int divisor);

static int
find_smallest_divisor_greater_than_one(int number)
{
	/* FIXME: handle negative numbers */

	/* OPTIMIZATION FIXME: The smallest divisor is always less than
						   the square root of the number. */

	int smallest_divisor = 2;

	while (!is_divisable(number, smallest_divisor))
	{
		++smallest_divisor;
	}

	return smallest_divisor;
}

static int
is_divisable(int dividend, int divisor)
{
	/* FIXME: handle division by zero */
	return 0 == dividend % divisor;
}

