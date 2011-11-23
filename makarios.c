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

		if (!((a == i) || (a/8 == i)))
			continue;

		m = 2;
		while (0 != n%m)
		{
			++m;
		}

		if (m == n)
			printf("%o\n", n);
	}

	return 0;
}
