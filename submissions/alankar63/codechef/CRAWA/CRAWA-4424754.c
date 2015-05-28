#include<stdio.h>
#include<stdlib.h>

int main()
{long long int test,x,y,flag;
scanf("%llu",&test);
while(test--)
{scanf("%llu %llu",&x,&y);
flag=0;
if(x==0&&y==0)flag=1;
if(!(y&1))
{
    if((y>0)&&(x<=y-1)&&(x>=(-y)))flag=1;
    if((y<0)&&(x>=y)&&(x<=(-y+1)))flag=1;
}
 if((x&1)&&(x>0)&&(y>=(-x+1))&&(y<=(x+1)))flag=1;
 if(!(x&1)&&(x<0)&&(y<=-x)&&(y>=x))flag=1;
 if(flag==1)printf("YES\n");
 if(flag==0) printf("NO\n");
}
return 0;
}