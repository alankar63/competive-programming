#include<stdio.h>
#include<stdlib.h>
inline int max(a,b)
{
    if(a>b)return a;
       return b;
}
int main()
{int test,n,i,j,ar[101][101];
scanf("%d",&test);
  while(test--)
  {scanf("%d",&n);

   i=0;
   while(i<n)
    {
       for(j=0;j<=i;j++)
        scanf("%d",&ar[i][j]);
        i++;
    }
   for(i=n-2;i>=0;i--)
   {
       for(j=0;j<=i;j++)
        ar[i][j]=ar[i][j]+max(ar[i+1][j],ar[i+1][j+1]);
   }
    printf("%d\n",ar[0][0]);
  }

return 0;
}