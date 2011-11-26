#include "performance.h"

main(n,i,a,m){repeat(n=1;while((i=++n)<=522233)
for(a=0;a<i?a=a*8+i%8,i/=8,m=a==i|a/8==i,1:(n-++m||printf("%o\n",n))&&n%m;););return 0;}
