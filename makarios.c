#define STOP_AT 522233

main(n,i,a,m){while((i=++n) <= STOP_AT)
for(a=0;a<i?a=a*8+i%8,i/=8,m=a==i|a/8==i,1:(n-++m||printf("%o\n",n))&&n%m;);}
