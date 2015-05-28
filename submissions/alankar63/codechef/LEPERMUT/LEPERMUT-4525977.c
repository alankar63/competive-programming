#include <stdio.h>
#include <stdlib.h>
 
int main()
{
      int t=0;
      scanf("%d",&t);
      while (t--)
      {
 
        int a[100];int flag=0;int n=0;int i=0;int j=0;
        scanf("%d",&n);
 
 
 
      for (i=0;i<n;i++)
      scanf("%d",&a[i]);
 
      if (n==1||n==2)
        {
            printf("YES\n");
            continue;
        }
 
      for (i=0;i<n-2;i++)
      {
          
          for (j=i+2;j<n;j++)
          {
              if (a[i]>a[j])
              {
                 flag++;break;
              }
          }
      }
 
      if (flag>0)
      printf("NO\n");
      else
        printf("YES\n");
      }
      
      return 0;
}