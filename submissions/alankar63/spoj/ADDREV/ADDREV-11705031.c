#include<stdio.h>
int rev(int e)
{int d=0,b,c=0;
b=e%10;
e=e/10;
c=b;
while(e)
{
b=e%10;
e=e/10;
c=c*10+b;
}


return c;
}
int main()
{int n,a,b,c,d;
scanf("%d",&n);
while(n--) 
{scanf("%d%d",&a,&b);
c=rev(a);
d=rev(b);
printf("%d\n",rev(c+d));


}

return 0;
}
