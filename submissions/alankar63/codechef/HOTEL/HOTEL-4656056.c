#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int t,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n][2];
        for(i=0;i<n;i++)
            scanf("%d",&a[i][0]);
        for(i=0;i<n;i++)
            scanf("%d",&a[i][1]);
        int b[1001];
        for(i=1;i<=1000;i++)
            b[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=a[i][0];j<a[i][1];j++)
             b[j]++;
        }
        int max=0;
        for(i=1;i<=1000;i++)
            if(b[i]>max) max=b[i];
        printf("%d\n",max);
 
        }
}