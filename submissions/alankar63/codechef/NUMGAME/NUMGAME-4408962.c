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
    if(c)puts("BOB\n");
    else   puts("ALICE\n"); 
}
return 0;
}