#include<stdio.h>
int main()
{long long int i,a=0,n,k;
scanf("%llu %llu",&n,&k);
while(n--)
{
    scanf("%llu",&i);
    if(i%k==0)
        a++;
}
   printf("%llu",a);
    return 0;
}