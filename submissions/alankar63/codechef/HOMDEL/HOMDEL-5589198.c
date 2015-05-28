#include<stdio.h>
#include<stdlib.h>
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    //long int a[250][250];
    int s,g,d;
    int n,m,i,j,k;
    long int t[250][250],t1,t2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                scanf("%ld",&t[i][j]);//t[i][j]=a[i][j];
            }
    }
 
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            t[i][j]=a[i][j];
    }*/
for(k=0;k<n;k++)
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            t[i][j]=min(t[i][k]+t[k][j],t[i][j]);
        }
    }
}
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d%d",&s,&g,&d);
        t1=t[s][g]+t[g][d];
        t2=t1-t[s][d];
        printf("%ld %ld\n",t1,t2);
    }
    return 0;
}