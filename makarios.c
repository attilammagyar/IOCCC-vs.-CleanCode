#include <stdio.h>

#define STOP_AT 522233

int main(int argc, char* argv[])
{
	int n;

	for (n = 2; n <= STOP_AT; ++n)
	{
		int a = 0,
			i = n,
			m, is_not_ready;

		do
		{
			if (a < i)
			{
				a = a*8 + i%8;
				i /= 8;
				m = (a == i) || (a/8 == i);
				is_not_ready = 1;
			}
			else
			{
				++m;
				if (m == n)
					printf("%o\n", n);

				is_not_ready = 0 != n%m;
			}
		} while (is_not_ready);
	}

	return 0;
}
