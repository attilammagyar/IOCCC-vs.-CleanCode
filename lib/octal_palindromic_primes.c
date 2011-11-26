#include "octal_palindromic_primes.h"

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
