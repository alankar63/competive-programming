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
int ans[10000][3];
int main()
{int i,j,n,m,k,y,z,l,p,count=1,f1,f2;
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
            {   f1=f2=0;
                ans[count][0]=i;
                ans[count][1]=j;
                
                l=j;
                while((a[i][l]!=1)&&l<=m)
                {
                   // a[i][l]=1;
                    l++;f1++;
                }
                l=j-1;
                 while((a[i][l]!=1)&&l>0)
                {
                   // a[i][l]=1;
                    l--;f1++;
                }
                 l=i;
                while((a[l][j]!=1)&&l<=n)
                {
                   // a[l][j]=1;
                    l++;f2++;
                }
                l=i-1;
                 while((a[l][j]!=1)&&l>0)
                {
                   // a[l][j]=1;
                    l--;f2++;
                }


                 if(f1>f2)
            {ans[count][2]=0;
            count++;
                  l=j;
                while((a[i][l]!=1)&&l<=m)
                {
                    a[i][l]=1;
                    l++;
                }
                l=j-1;
                 while((a[i][l]!=1)&&l>0)
                {
                    a[i][l]=1;
                    l--;
                }
            }
            else
            {
              ans[count][2]=1;
              count++;
                               l=i;
                while((a[l][j]!=1)&&l<=n)
                {
                    a[l][j]=1;
                    l++;
                }
                l=i-1;
                 while((a[l][j]!=1)&&l>0)
                {
                    a[l][j]=1;
                    l--;
                }
            }
            }

        }
    }printf("%d\n",count-1);
    for(i=1;i<count;i++)
    {
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
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