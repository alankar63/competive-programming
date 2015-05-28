#include<stdio.h>
#include<string.h>
#define size 4512
long long int a[size];
void fibo()
{
    int i;
    a[0]=0;
    a[1]=1;
    for(i=2;i<size;i++)
       a[i]=a[i-2]+a[i-1];
}
int main()
{
    int t,flag,l;
    long long num;
    char b[1004];
    int i;
    fibo();
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        num=0;
        scanf("%s",b);
        l=strlen(b);
        for(i=0;i<l;i++)
            num=num*10+(b[i]-'0');
        for(i=0;i<size;i++)
        {
            if(a[i]==num)
            {
             flag=1;
             break;
            }
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}