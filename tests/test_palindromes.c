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

#define BINARY_10101    ( (1)*2*2*2*2 + (0)*2*2*2 + (1)*2*2 + (0)*2 + (1) )
#define BINARY_11101    ( (1)*2*2*2*2 + (1)*2*2*2 + (1)*2*2 + (0)*2 + (1) )

#define DECIMAL_123321  123321
#define DECIMAL_123456  123456

#define HEXADECIMAL_abccba 0xabccba
#define HEXADECIMAL_abcdef 0xabcdef

void one_digit_is_palindromic()
{
	assert_true(is_palindromic(0, OCTAL));
	assert_true(is_palindromic(1, OCTAL));
	assert_true(is_palindromic(2, OCTAL));
	assert_true(is_palindromic(3, OCTAL));
	assert_true(is_palindromic(4, OCTAL));
	assert_true(is_palindromic(5, OCTAL));
	assert_true(is_palindromic(6, OCTAL));
	assert_true(is_palindromic(7, OCTAL));
}

void even_number_of_digits_can_be_palindromic()
{
	assert_true(is_palindromic(OCTAL_11, OCTAL));
	assert_true(is_palindromic(OCTAL_77, OCTAL));
	assert_true(is_palindromic(OCTAL_5775, OCTAL));
}

void odd_number_of_digits_can_be_palindromic()
{
	assert_true(is_palindromic(OCTAL_272, OCTAL));
	assert_true(is_palindromic(OCTAL_70207, OCTAL));
}

void numbers_are_not_accepted_if_not_palindromic()
{
	assert_false(is_palindromic(OCTAL_42, OCTAL));
	assert_false(is_palindromic(OCTAL_172, OCTAL));
	assert_false(is_palindromic(OCTAL_1234, OCTAL));
	assert_false(is_palindromic(OCTAL_73257, OCTAL));
}

void negative_palindromic_numbers_are_accepted()
{
	assert_true(is_palindromic(-5, OCTAL));
	assert_true(is_palindromic(-OCTAL_5775, OCTAL));
	assert_true(is_palindromic(-OCTAL_70207, OCTAL));
}

void negative_numbers_are_not_accepted_if_not_palindromic()
{
	assert_false(is_palindromic(-OCTAL_42, OCTAL));
	assert_false(is_palindromic(-OCTAL_172, OCTAL));
	assert_false(is_palindromic(-OCTAL_1234, OCTAL));
	assert_false(is_palindromic(-OCTAL_73257, OCTAL));
}

void can_work_with_binary_base()
{
	assert_true(is_palindromic(BINARY_10101, BINARY));
	assert_false(is_palindromic(BINARY_11101, BINARY));
}

void can_work_with_decimal_base()
{
	assert_true(is_palindromic(DECIMAL_123321, DECIMAL));
	assert_false(is_palindromic(DECIMAL_123456, DECIMAL));
}

void can_work_with_hexadecimal_base()
{
	assert_true(is_palindromic(HEXADECIMAL_abccba, HEXADECIMAL));
	assert_false(is_palindromic(HEXADECIMAL_abcdef, HEXADECIMAL));
}

void invalid_base_results_in_error()
{
	assert_equals_int(PALINDROME_ERROR, is_palindromic(42, -1));
	assert_equals_int(PALINDROME_ERROR, is_palindromic(42, 0));
	assert_equals_int(PALINDROME_ERROR, is_palindromic(42, 1));
}

int main()
{
	one_digit_is_palindromic();
	even_number_of_digits_can_be_palindromic();
	odd_number_of_digits_can_be_palindromic();

	numbers_are_not_accepted_if_not_palindromic();

	negative_palindromic_numbers_are_accepted();
	negative_numbers_are_not_accepted_if_not_palindromic();

	can_work_with_binary_base();
	can_work_with_decimal_base();
	can_work_with_hexadecimal_base();

	invalid_base_results_in_error();

	finish_testing();
}
