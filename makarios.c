#include <stdio.h>

#define STOP_AT 522233

static int magic_algorithm(int number);
static int is_prime(int number);
static void print_octal(int number);

int main(int argc, char* argv[])
{
	int n;

	for (n = 2; n <= STOP_AT; ++n)
	{
		if (magic_algorithm(n) && is_prime(n))
			print_octal(n);
	}

	return 0;
}

static int
magic_algorithm(int number)
{
	int a = 0,
		i = number;

	while (a < i)
	{
		a = a*8 + i%8;
		i /= 8;
	}

	return (a == i) || (a/8 == i);
}

static int find_smallest_divisor_greater_than_one(int number);

static int
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

static void
print_octal(int number)
{
	printf("%o\n", number);
}
