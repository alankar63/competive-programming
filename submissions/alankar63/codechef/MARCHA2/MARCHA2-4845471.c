#include<stdio.h>
int main()
{
    int t,n,i,j,a,stem;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
           scanf("%d",&a);
           stem=1;
           stem=(stem-a)*2;
           for(j=2;j<=n;j++)
           {
               scanf("%d",&a);
               stem=(stem-a)*2;
               if(stem<0)
                break;
            }
        if(j==n+1 && stem==0)
         printf("Yes\n");
       else
        printf("No\n");
 
    }
return 0;
}