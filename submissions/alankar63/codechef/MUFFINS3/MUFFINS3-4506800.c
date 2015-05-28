#include<stdio.h>
#include<stdlib.h>
int main()
{
  long long int t,N,z;
  scanf("%lld",&t);
  while(t--)
  {
     scanf("%lld",&N);
     z=N/2;
     z=z+1;
     printf("%lld\n",z);
  }
  return 0;
}