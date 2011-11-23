#include <stdio.h>

#define STOP_AT 522233

int main(int argc, char* argv[])
{
	int n;

	for (n = 2; n <= STOP_AT; ++n)
	{
		int a = 0,
			i = n,
			m;

		while (a < i)
		{
			a = a*8 + i%8;
			i /= 8;
		}

		m = (a == i) || (a/8 == i);

		while (1)
		{
			++m;
			if (m == n)
				printf("%o\n", n);

			if (0 == n%m)
				break;
		}
	}

	return 0;
}
