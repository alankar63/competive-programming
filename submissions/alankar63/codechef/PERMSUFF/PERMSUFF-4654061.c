#include<stdio.h>
#include<stdlib.h>
int a[100001],b[100001];
#define gc getchar_unlocked

inline int inp()  //for fast input
{
    int h=0,sign=1;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';


        c=gc();
    } //n=n*sign;

     return h;
}


int main()
{  int t,l,r,i,j,z,n,m,flag=1,sum,sum1;
//t=inp();

scanf("%d",&t);
while(t--)
{flag=1,z=1,sum=0,sum1=0;
//n=inp();m=inp();
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {//a[i]=inp();
       scanf("%d",&a[i]);
        b[i]=0;
    }

    for(i=1;i<=m;i++)
    {
       scanf("%d%d",&l,&r);
       if(b[l]==0)b[l]=2;
       if(b[l]==1)b[l]=1;
       if(b[l]==2)b[l]=2;
       for(j=l+1;j<=r;j++)
       {
           b[j]=1;
       }
    }

    for(i=1;i<=n;i++)
    {

        if(b[i]==2)
        {   if((sum!=sum1))
            {
              flag=0; break; 
            }
            sum=a[i];sum1=i;
        }
        else if(b[i]==1)
        {
            sum= sum+a[i];sum1=sum1+i;
        }
         else
         {
             if((sum!=sum1)||(a[i]!=i))
             {
                 flag=0;break;
             }
             sum=0;sum1=0;
         }
       // if((b[i]==0))
        //{
         //   d[]
        //}
    }
    if(flag==0)
    {
      printf("Impossible\n") ;
    }
    else
    {
       printf("Possible\n") ;
    }
}
    return 0;
}