#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int t,n,i,bal,max_bal;
    char str[100005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",&str);
        n=strlen(str);
        max_bal=0;
        bal=0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='(')
                bal=bal+1;
            if(str[i]==')')
                bal=bal-1;
            max_bal=max_bal>bal?max_bal:bal;
        }
        for(i=0;i<max_bal;i++)
        {
            printf("(");
        }
        for(i=0;i<max_bal;i++)
            printf(")");
        printf("\n");
    }
    return 0;
}