#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define gc getchar_unlocked
inline long long int inp()
{
  long long  int h=0,sign=1;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {if(c=='-')	sign=-sign;
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';


        c=gc();
    } h=h*sign;

     return h;
}

int n,b[100001][2];
long long int a[100001]={0};
void update( int p,long long int v)
 {

    for (; p <= n; p += p&(-p))
        a[p] += v ;
 }
     long long int  query(long long int b)
  {

   long long int  sum = 0  ;
    for(; b > 0; b -= b&(-b))
        sum += a[b];
    return sum;
  }
int main()
{ int i,q,h,t,d,e,x;
long long int v,y,ans,g;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
   // scanf("%llu",&v);

    v=inp();
    update(i,v);
}
for(i=1;i<=n;i++)
{
    scanf("%d%d",&b[i][0],&b[i][1]);
}
scanf("%d",&q);
while(q--)
{ans=0;
    scanf("%d",&h);
    if(h==1)
    {
         scanf("%d%llu",&x,&y);
         g=query(x)-query(x-1);
         y=y-g;
         update(x,y);
    }
    else
    {
         scanf("%d%d",&d,&e);
         for(t=d;t<=e;t++)
         {
             ans=ans+query(b[t][1])-query(b[t][0]-1);
         }
         printf("%llu\n",ans);
    }
}
    return 0;
}