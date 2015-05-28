#include <stdio.h>
#include <stdlib.h>
int main()
{
    int tc,n,m,i,s;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&m);
        int a[n];
        for(i=1;i<=n;i++)
            a[i]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d",&s);
            a[s]++;
        }
        s=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(s==0)
                {
                    printf("%d ",i);
                    s++;
                }
                else
                    s--;
            }
        }
        printf("\n");
        s=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(s==0)
                   s++;
                else
                {
                   printf("%d ",i);
                   s--;
                }
            }
        }
        printf("\n");
    }
    return 0;
}