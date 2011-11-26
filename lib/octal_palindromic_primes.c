#include "octal_palindromic_primes.h"

static void print_octal(int number);

void
print_first_150_octal_palindromic_primes()
{
	int n = 0, i;

	for (i = 0; i != 150; ++i)
	{
		n = find_octal_palindromic_prime_bigger_than(n);
		print_octal(n);
	}
}

int
find_octal_palindromic_prime_bigger_than(int lower_bound)
{
	int candidate = lower_bound;

	do
	{
		++candidate;
	} while (!(is_palindromic(candidate, OCTAL) && is_prime(candidate)));

	return candidate;
}

static void
print_octal(int number)
{
	printf("%o\n", number);
}
