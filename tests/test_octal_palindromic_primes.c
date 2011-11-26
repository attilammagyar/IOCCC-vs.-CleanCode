#include "test.h"

#include <lib/octal_palindromic_primes.h>

int main()
{
	assert_equals_int(2, find_octal_palindromic_prime_bigger_than(-1));
	assert_equals_int(3, find_octal_palindromic_prime_bigger_than(2));
	assert_equals_int(522233, find_octal_palindromic_prime_bigger_than(519097));

	finish_testing();
}
