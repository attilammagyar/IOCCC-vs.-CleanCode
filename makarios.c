#include <stdio.h>

#define STOP_AT 522233

static int magic_algorithm(int number);
static int other_magic_algorithm(int number);
static void print_octal(int number);

int main(int argc, char* argv[])
{
	int n;

	for (n = 2; n <= STOP_AT; ++n)
	{
		if (magic_algorithm(n) && other_magic_algorithm(n))
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

static int is_divisable(int dividend, int divisor);

static int
other_magic_algorithm(int number)
{
	int m;

	m = 2;
	while (!is_divisable(number, m))
	{
		++m;
	}

	return m == number;
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
