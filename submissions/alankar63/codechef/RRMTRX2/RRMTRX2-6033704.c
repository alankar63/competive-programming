#include<stdio.h>
int main()
{
    int n,m,sum,i,j,x;
    long long int a[40]={0};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&x);
            a[j]=(a[j]+x)%10000007;
        }
    }
    int res=1;
    for(i=0;i<m;i++)
    {
        res=(res*a[i])%10000007;
    }
    res=(res+10000007)%10000007;
    /*for(j=0;j<m;j++)
    {   sum=0;
        for(i=0;i<n;i++)
        {
            sum=sum+a[i][j];
        }
        pro=pro*sum;
    }*/
    printf("%d\n",res);
    return 0;
}