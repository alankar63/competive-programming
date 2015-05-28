#include<stdio.h>
int main()
{
    int t,a,n,n1;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d",&a);
        while(a--)
        {
            scanf("%d%d",&n,&n1);
            sum+=n-n1;
        }
        printf("%d\n",sum);
    }
    return 0;
}