#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,f,i,j,sum;
        scanf("%d%d",&n,&m);
        int a[n];
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        for(i=1;i<pow(2,n);i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if((i&(1<<j))>0)
                sum=sum+a[j];
            }
            if(sum==m)
            {
                f=0;
                printf("Yes\n");
                break;
            }
            else
            f=1;
        }
        if(f==1)
        printf("No\n");
    }
    return 0;
}