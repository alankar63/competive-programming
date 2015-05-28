#include<stdio.h>
#define sizer 10000
void sieve(int a[],int n)
{
   int i,j;
   for(i=2;i<=n;i++)
   {
       if(a[i]==1)
       {
           for(j=i;(i*j)<=n;j++)
            a[i*j]=0;
       }
   }
}
int main()
{
    int t,x,y,m=0,k=1000;
    int i,n=2004;
    int a[sizer];
    scanf("%d",&t);
    for(i=2;i<=n;i++)
        {
            a[i]=1;
        }
        sieve(a,n);
    while(t--)
    {
        scanf("%d%d",&x,&y);
 
       for(i=2;i<=n;i++)
    {
        if(a[i]==1)
        {
            m=i-x-y;
        }
        if(m>0)
            break;
 
    }
    printf("%d\n",m);
 }
    return 0;
}