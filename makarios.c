#include <stdio.h>

#define STOP_AT 522233

int main(int argc, char* argv[])
{
	int n = 1,
		i, a, m;

	while((i=++n) <= STOP_AT)
	{
		for(a=0;a<i?a=a*8+i%8,i/=8,m=a==i|a/8==i,1:(n-++m||printf("%o\n",n))&&n%m;)
		{
		}
	}

	return 0;
}
