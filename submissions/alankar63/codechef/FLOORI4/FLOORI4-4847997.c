#include<stdio.h>
    long long int fun(long long int n,long long int mod)
    {
    long long int v,i,ans1,r;
    for(i=0;i<10;i++)
    {
    	
    }
    v=30*mod;
    ans1=1;
	ans1=(ans1*n)%v;
    ans1=(ans1*(n+1))%v;
    ans1=(ans1*(2*n+1))%v;
    r=(((3*n)%v)*(n+1))%v;
    r=(r-1);
    if(r<0)
    r=r+v;
    
    ans1=(ans1*r)%v;
 
    //ans1=((((((n*(n+1))%v)*(2*n+1))%v)*(3*n*(n+1)-1))%v)%v;
    ans1=ans1/30;
    
    return ans1;
    }
    int main()
    {
    long long int t,n,m,i,p,q,x,z;
    scanf("%lld",&t);
    while(t--)
    {
    scanf("%lld %lld",&n,&m);
    i=1;
    x=0;
   
    while(i<=n)
    {
    p=n/i;
    q=n/p;
    z=fun(n/i,m);
    z=(z*(q-i+1))%m;
    
    i=i+(q-i)+1;
    x=(x+z)%m;
 
    }
    
    printf("%lld\n",x);
    }
    return 0;
    }