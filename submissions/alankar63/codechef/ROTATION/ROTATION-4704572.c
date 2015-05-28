#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define gc getchar_unlocked
inline long long  int inp()  //for fast input
{
    long long  int h=0,sign=1;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';


        c=gc();
    } //n=n*sign;

     return h;
}
int main()
{long long int a[100000],i,t,ans,n,m,start=0;
char z;
scanf("%d%d",&n,&m);
for(i=0;i<n;i++)
{
    a[i]=inp();
}
for(i=0;i<m;i++)
{
    scanf("%c",&z);
    t=inp();
    if(z=='C')
    {
       start=(start+t)%n;
    }
    else if(z=='A')
    {
        start=(start-t);
        if(start<0)start=n+start;
    }
    else
    {
        printf("%llu\n",a[(start+t-1)%n]);
    }
}

    return 0;
}