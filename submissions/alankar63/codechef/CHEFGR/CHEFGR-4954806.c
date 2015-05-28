#include<stdio.h>
#include<stdlib.h>
int main()
{ int t,i,j,n,m,max;
scanf("%d",&t);
while(t--)
{max=-1;
    scanf("%d%d",&n,&m);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max)
        {
            max=a[i];
        }
    }
      for(i=0;i<n;i++)
      {
          m=m-(max-a[i]);
      }
      if(m<0)
      {
          printf("No\n");

      }
      else
      {
          if(m==0)
             printf("Yes\n");
          else
          {
              if(m%n==0)
                 printf("Yes\n");
              else
                 printf("No\n");
          }
      }
}

    return 0;
}