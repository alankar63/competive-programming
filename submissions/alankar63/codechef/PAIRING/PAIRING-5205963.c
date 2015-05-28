#include<stdio.h>
int main ()
{
    int t,n,m,i,count,j,p[100005][2]={0};
    scanf("%d",&t);
    while(t--)
    {  int q[100005]={0},a[100005]={0};
        scanf("%d",&n);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&p[i][0]);
            scanf("%d",&p[i][1]);
        }
        j=0;
        for(i=m-1;i>=0;i--)
        {
            if(a[ p[i][0] ]==0&a[ p[i][1] ]==0)
            {
                a[ p[i][0] ]=a[ p[i][1] ]=1;
                q[j++]=i;
 
            }
 
        }
        for(i=j-1;i>=0;i--)
        {
            printf("%d ",q[i]);
        }
        printf("\n");
    }
return 0;
}