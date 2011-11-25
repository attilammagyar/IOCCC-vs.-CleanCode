#include "test.h"

#include <lib/palindromes.h>

#define OCTAL_11        (                                     (1)*8 + (1) )
#define OCTAL_77        (                                     (7)*8 + (7) )
#define OCTAL_272       (                           (2)*8*8 + (7)*8 + (2) )
#define OCTAL_5775      (               (5)*8*8*8 + (7)*8*8 + (7)*8 + (5) )
#define OCTAL_70207     ( (7)*8*8*8*8 + (0)*8*8*8 + (2)*8*8 + (0)*8 + (7) )

#define OCTAL_42        (                                     (4)*8 + (2) )
#define OCTAL_172       (                           (1)*8*8 + (7)*8 + (2) )
#define OCTAL_1234      (               (1)*8*8*8 + (2)*8*8 + (3)*8 + (4) )
#define OCTAL_73257     ( (7)*8*8*8*8 + (3)*8*8*8 + (2)*8*8 + (5)*8 + (7) )

void one_digit_is_palindromic()
{
	assert_true(is_palindromic_in_octal_base(0));
	assert_true(is_palindromic_in_octal_base(1));
	assert_true(is_palindromic_in_octal_base(2));
	assert_true(is_palindromic_in_octal_base(3));
	assert_true(is_palindromic_in_octal_base(4));
	assert_true(is_palindromic_in_octal_base(5));
	assert_true(is_palindromic_in_octal_base(6));
	assert_true(is_palindromic_in_octal_base(7));
}

void even_number_of_digits_can_be_palindromic()
{
	assert_true(is_palindromic_in_octal_base(OCTAL_11));
	assert_true(is_palindromic_in_octal_base(OCTAL_77));
	assert_true(is_palindromic_in_octal_base(OCTAL_5775));
}

void odd_number_of_digits_can_be_palindromic()
{
	assert_true(is_palindromic_in_octal_base(OCTAL_272));
	assert_true(is_palindromic_in_octal_base(OCTAL_70207));
}

void numbers_are_not_accepted_if_not_palindromic()
{
	assert_false(is_palindromic_in_octal_base(OCTAL_42));
	assert_false(is_palindromic_in_octal_base(OCTAL_172));
	assert_false(is_palindromic_in_octal_base(OCTAL_1234));
	assert_false(is_palindromic_in_octal_base(OCTAL_73257));
}

void negative_palindromic_numbers_are_accepted()
{
	assert_true(is_palindromic_in_octal_base(-5));
	assert_true(is_palindromic_in_octal_base(-OCTAL_5775));
	assert_true(is_palindromic_in_octal_base(-OCTAL_70207));
}

void negative_numbers_are_not_accepted_if_not_palindromic()
{
	assert_false(is_palindromic_in_octal_base(-OCTAL_42));
	assert_false(is_palindromic_in_octal_base(-OCTAL_172));
	assert_false(is_palindromic_in_octal_base(-OCTAL_1234));
	assert_false(is_palindromic_in_octal_base(-OCTAL_73257));
}

int main()
{
	one_digit_is_palindromic();
	even_number_of_digits_can_be_palindromic();
	odd_number_of_digits_can_be_palindromic();

	numbers_are_not_accepted_if_not_palindromic();

	negative_palindromic_numbers_are_accepted();
	negative_numbers_are_not_accepted_if_not_palindromic();

	finish_testing();
}
