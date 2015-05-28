#include <stdio.h>
int main()
{
    int t,n,i;
    char a,b,c;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        if(n>360)
        {
            a='n';
            b='n';
            c='n';
        }
        else
        {
            b='y';
            if(360%n==0)
                a='y';
            else
                a='n';
            if(n<27)
                c='y';
            else
                c='n';
 
        }
        printf("%c %c %c\n",a,b,c);
    }
    return 0;
}