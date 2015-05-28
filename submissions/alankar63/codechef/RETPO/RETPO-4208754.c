#include<stdio.h>
#include<string.h>

int main()
{
long long int test,n,a,b,ans,c,d;
scanf("%llu",&test);
while(test--)
{scanf("%llu %llu",&a,&b);
ans =0;
a=(a>0?a:-a);
b=(b>0?b:-b);
ans=(a>b?2*b:2*a);
c=a-b;

c=(c>0?c:-c);
if(c%2==0)
    ans=ans+c*2;
else
  { if(a>b)ans= ans+2*c+1;
     else

   ans=ans+2*c-1;
}
printf("%llu\n",ans);
}
return 0;
}