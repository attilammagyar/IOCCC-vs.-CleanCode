#include "test.h"

#include <lib/primes.h>

void zero_is_not_prime()
{
	assert_false(is_prime(0));
}

void one_is_not_prime()
{
	assert_false(is_prime(1));
}

void two_is_prime()
{
	assert_true(is_prime(2));
}

void three_is_prime()
{
	assert_true(is_prime(3));
}

void six_is_not_prime()
{
	assert_false(is_prime(6));
}

void forty_two_is_not_prime()
{
	assert_false(is_prime(42));
}

void forty_three_is_prime()
{
	assert_true(is_prime(43));
}

int main()
{
	zero_is_not_prime();
	one_is_not_prime();
	two_is_prime();
	three_is_prime();
	six_is_not_prime();
	forty_two_is_not_prime();
	forty_three_is_prime();
	finish_testing();
}
