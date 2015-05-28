#include<stdio.h>
/*long long gcd(long long n,long long k)
{
    if (k==0)
     return n;
  else return gcd(k,n%k);
}*/
 
long long comb(int n,int k)
{
    long long N=1,K=1,p=1;
    if(k>n/2)
    k=n-k;
    int j,i;
    for(j=1,i=n;j<=k;j++,i--)
    {
        //g=gcd(N,K);
       // K=K/g;
        //N=N/g;
       p=p*i;
       p=p/j;
    }
    return p;
 
}
 
int main()
{
    int t,n,k;
    scanf("%d",&t);
 
    while(t--)
    {
       long long c;
       scanf("%d%d",&n,&k);
       c=comb(n-1,k-1);
       printf("%lld\n",c);
    }
}