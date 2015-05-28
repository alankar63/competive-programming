#include<stdio.h>
#include<stdlib.h>

int main()
{int a;
long long int b,c;
scanf("%d",&a);
while(a--)
{
    scanf("%llu",&b);
    c=b&1;
    if(c)printf("BOB\n");
    else   printf("ALICE\n"); 
}
return 0;
}