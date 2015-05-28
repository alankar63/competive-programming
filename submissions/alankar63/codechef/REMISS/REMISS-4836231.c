#include<stdio.h>
int main()
{
    int t,a,b,min,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        if(a>=b)
        min=a;
        else
        min=b;
        max=a+b;
        printf("%d %d\n",min,max);
 
    }
    return 0;
}