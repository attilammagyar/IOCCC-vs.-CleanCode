#include "test.h"

#include <lib/palindromes.h>

void one_digit_is_palindromic()
{
	assert_true(is_palindromic_in_octal_base(2));
	assert_true(is_palindromic_in_octal_base(3));
	assert_true(is_palindromic_in_octal_base(4));
	assert_true(is_palindromic_in_octal_base(5));
	assert_true(is_palindromic_in_octal_base(6));
	assert_true(is_palindromic_in_octal_base(7));
}

void even_number_of_digits_can_be_palindromic()
{
	assert_true(is_palindromic_in_octal_base((1)*8 + (1)));
	assert_true(is_palindromic_in_octal_base((7)*8 + (7)));

	assert_true(
		is_palindromic_in_octal_base(
			(5)*8*8*8 + (7)*8*8 + (7)*8 + (5)
		)
	);
}

void odd_number_of_digits_can_be_palindromic()
{
	assert_true(is_palindromic_in_octal_base((2)*8*8 + (7)*8 + (2)));

	assert_true(
		is_palindromic_in_octal_base(
			(7)*8*8*8*8 + (0)*8*8*8 + (2)*8*8 + (0)*8 + (7)
		)
	);
}

void numbers_are_not_accepted_if_not_palindromic()
{
	assert_false(is_palindromic_in_octal_base((1)*8*8 + (7)*8 + (2)));
	assert_false(is_palindromic_in_octal_base((4)*8 + (2)));

	assert_false(
		is_palindromic_in_octal_base(
			(1)*8*8*8 + (2)*8*8 + (3)*8 + (4)
		)
	);

	assert_false(
		is_palindromic_in_octal_base(
			(7)*8*8*8*8 + (3)*8*8*8 + (2)*8*8 + (5)*8 + (7)
		)
	);
}

int main()
{
	one_digit_is_palindromic();
	even_number_of_digits_can_be_palindromic();
	odd_number_of_digits_can_be_palindromic();

	numbers_are_not_accepted_if_not_palindromic();

	finish_testing();
}
