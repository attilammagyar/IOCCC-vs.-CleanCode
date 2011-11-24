#include <stdio.h>

#include <lib/primes.h>

#define STOP_AT 522233

static int is_palindromic_in_octal_base(int number);
static void print_octal(int number);

int main(int argc, char* argv[])
{
	int n;

	for (n = 2; n <= STOP_AT; ++n)
	{
		if (is_palindromic_in_octal_base(n) && is_prime(n))
			print_octal(n);
	}

	return 0;
}

static int get_last_octal_digit(int number);
static int append_octal_digit(int number, int digit);
static int remove_last_octal_digit(int number);

static int
is_palindromic_in_octal_base(int number)
{
	/* FIXME: handle negative numbers */

	int reversed_digits = 0,
		remaining_digits = number;

	/* NOTE: The loop will stop when the digit in the middle is reached.  */
	while (reversed_digits < remaining_digits)
	{
		int digit = get_last_octal_digit(remaining_digits);
		reversed_digits = append_octal_digit(reversed_digits, digit);
		remaining_digits = remove_last_octal_digit(remaining_digits);
	}

	/* NOTE: For an odd number of digits, reversed_digits contains
			 an extra digit (coming from the middle). */
	return (reversed_digits == remaining_digits)
		|| (remove_last_octal_digit(reversed_digits) == remaining_digits);
}

static int
get_last_octal_digit(int number)
{
	return number % 8;
}

static int
append_octal_digit(int number, int digit)
{
	/* FIXME: handle invalid digits */
	return number * 8 + digit;
}

static int
remove_last_octal_digit(int number)
{
	return number / 8;
}

static void
print_octal(int number)
{
	printf("%o\n", number);
}
