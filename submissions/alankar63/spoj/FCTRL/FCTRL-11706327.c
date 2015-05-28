#include<stdio.h>
int main()
{int t;
long long int a,b,c;
scanf("%d",&t);
while(t--)
{b=5;
c=0;
scanf("%llu",&a);
while((a/b)!=0)
{c=c+a/b;
b=b*5;
}printf("%llu\n",c);
}

return 0;
}