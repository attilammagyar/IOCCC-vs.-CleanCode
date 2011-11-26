#include <stdio.h>

#include <lib/octal_palindromic_primes.h>

static void print_octal(int number);

int main(int argc, char* argv[])
{
	int n = 0, i;

	for (i = 0; i != 150; ++i)
	{
		n = find_octal_palindromic_prime_bigger_than(n);
		print_octal(n);
	}

	return 0;
}

static void
print_octal(int number)
{
	printf("%o\n", number);
}
