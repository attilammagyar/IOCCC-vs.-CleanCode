#include <stdio.h>

#include <lib/primes.h>
#include <lib/palindromes.h>

#define STOP_AT 522233

static void print_octal(int number);

int main(int argc, char* argv[])
{
	int n;

	for (n = 2; n <= STOP_AT; ++n)
	{
		if (is_palindromic(n, OCTAL) && is_prime(n))
			print_octal(n);
	}

	return 0;
}

static void
print_octal(int number)
{
	printf("%o\n", number);
}
