#include "palindromes.h"

static int is_invalid_base(int base);
static int get_last_digit(int number, int base);
static int append_digit(int number, int digit, int base);
static int remove_last_digit(int number, int base);

int
is_palindromic(int number, int base)
{
	int reversed_digits = 0,
		remaining_digits = abs(number);

	if (is_invalid_base(base))
		return PALINDROME_ERROR;

	/* NOTE: The loop will stop when the digit in the middle is reached.  */
	while (reversed_digits < remaining_digits)
	{
		int digit = get_last_digit(remaining_digits, base);
		reversed_digits = append_digit(reversed_digits, digit, base);
		remaining_digits = remove_last_digit(remaining_digits, base);
	}

	/* NOTE: For an odd number of digits, reversed_digits contains
			 an extra digit (coming from the middle). */
	return (reversed_digits == remaining_digits)
		|| (remove_last_digit(reversed_digits, base) == remaining_digits);
}

static int
is_invalid_base(int base)
{
	return base < 2;
}

static int
get_last_digit(int number, int base)
{
	return number % base;
}

static int
append_digit(int number, int digit, int base)
{
	return number * base + digit;
}

static int
remove_last_digit(int number, int base)
{
	return number / base;
}

