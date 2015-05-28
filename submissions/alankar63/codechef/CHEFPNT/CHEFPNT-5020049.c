#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define gc getchar_unlocked
/*inline int inp()
{
    int h=0,sign=1;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {if(c=='-')	sign=-sign;
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';


        c=gc();
    } h=h*sign;

     return h;
}
*/
int a[101][101];
int ans[10000][2];
int main()
{int i,j,n,m,k,y,z,l,p,count=1;
scanf("%d%d%d",&n,&m,&k);


for(i=1;i<=n;i++)
   for(j=1;i<=m;i++)
        a[i][j]=0;
for(i=1;i<=k;i++)
{
   scanf("%d%d",&y,&z);
   a[y][z]=1;
}
//if(n<m)
{   for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(!a[i][j])
            {
                ans[count][0]=i;
                ans[count][1]=j;
                count++;
                l=j;
                while((a[i][l]!=1)&&l<=m)
                {
                    a[i][l]=1;
                    l++;
                }
                l=j;
                 while((a[i][l]!=1)&&l>0)
                {
                    a[i][l]=1;
                    l--;
                }
            }
        }
    }printf("%d\n",count-1);
    for(i=1;i<count;i++)
    {
        printf("%d %d 0\n",ans[i][0],ans[i][1]);
    }
  //print
}
/*
else
{ for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(!a[i][j])
            {
                ans[count][0]=i;
                ans[count][1]=j;
                count++;
                l=i;
                while((a[l][j]!=1)&&l<=n)
                {
                    a[l][j]=1;
                    l++;
                }
                l=i;
                 while((a[l][j]!=1)&&l>0)
                {
                    a[l][j]=1;
                    l--;
                }
            }
        }
    }
    printf("%d\n",count-1);
    for(i=1;i<count;i++)
    {
        printf("%d %d 1\n",ans[i][0],ans[i][1]);
    }
  //print
}
*/
    return 0;
}