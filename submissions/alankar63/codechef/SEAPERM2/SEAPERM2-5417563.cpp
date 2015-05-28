#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int x[302]={0};
int n,a[302][3]={{0}};
int b[302][302]={{0}};
int ans[302]={0};
void func()
{int i,j,k;
    for(i=1;i<=n;i++)
    {
       a[i][0]=n-i;
       a[i][1]=i-1;
    }
}
int main()
{int t,i,j,k,count,l,m,q;
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
k=1;
for(i=0;i<=n;i++)
    x[i]=0;
    func();
    for(i=1;i<=n;i++)
        for(j=1;j<n;j++)
           scanf("%d",&b[i][j]);
    for(i=1;i<=n;i++)
    {x[b[i][1]]++;

    }
  for(i=1;i<=n;i++)
  {
      if((x[i]>=a[i][0])&&(x[i-1]>=a[i][1]))
      {
         ans[k]=i;
         x[i]=x[i]-a[i][0];
         x[i-1]=x[i-1]-a[i][1];
         k++;
         break;
      }
  }
  for(i=1;i<=n;i++)
  {
      if(x[i])
      {
         if(x[i]>=ans[k-1])
          {

            ans[k]=i+1;k++;}
         else
           {

            ans[k]=i;k++;}
            break;
      }
  }
  for(i=2;i<n;i++)
  {
      for(j=1;j<=n;j++)
      {
          x[b[j][i]]++;
      }
      x[ans[k-1]]=x[ans[k-1]]-a[ans[k-1]][0];
       x[ans[k-1]-1]=x[ans[k-1]-1]-a[ans[k-1]][1];
       //printf("%d%d%d",x[1],x[2],x[3]);
       m=0;count=0;q=0;
        for(l=1;l<=n;l++)
  {
      if(x[l])
      {   if((l!=m)&&(l!=q))
        {
          count++;
          if(!m)
          m=l;
          else
            q=l;
        }
        // if(x[i]>=ans[k-1])
         //   ans[k++]=i+1;
        // else
          //  ans[k++]=i;
      }
  }
  //printf("%d%d",m,q);
  if(count==2)
  {
     if(m>q)
        ans[k++]=m;
     else
        ans[k++]=q;
  }
  else
  {if(m>=ans[k-1])
     ans[k++]=m+1;
     else
        ans[k++]=m;

  }
  }
for(i=1;i<=n;i++)
    printf("%d ",ans[i]);
printf("\n");
}
    return 0;
}