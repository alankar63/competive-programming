//bottom up approach

#include<stdio.h>
void cal(int i,int j,int n);
char arr[1001][1001];
int iarr[1001][1001];
int main()
{
    int t,i,j,n,f,ki,kj;
 
    scanf("%d",&t);
    while(t--)
    {
        f=0;ki=0;kj=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",arr[i]);
 
        for(i=0;i<n;i++)
        {
              for(j=0;j<n;j++)
              {
                  if(arr[i][j]=='K')
                  {
                      ki=i;
                      kj=j;
                      f=1;
                    break;
                    }
                }
              if(f==1)
                break;
          }
 
             for(j=n-1;j>=kj;j--)
                {
                    for(i=0;i<n;i++)
                    {
                        iarr[i][j]=0;
                        cal(i,j,n);
                    }
                }
            printf("%d\n",iarr[ki][kj]);
    }
    return 0;
}
 
int big(int x,int y)
{
   return(x>y?x:y);
}
 
void cal(int i,int j,int n)
{
    int a=0,b=0,c=0,d=0;
 
    if(i+2<n && j+1<n)
    {
        a=iarr[i+2][j+1];
    }
    if(i-2>=0 && j+1<n)
    {
        b=iarr[i-2][j+1];
    }
    if(i+1<n && j+2<n)
    {
        c=iarr[i+1][j+2];
    }
    if(i-1>=0 && j+2<n)
    {
        d=iarr[i-1][j+2];
    }
     iarr[i][j]=big(big(b,d),big(a,c));
     if(arr[i][j]=='P')
         iarr[i][j]++;
}