#include<stdio.h>
#include<stdlib.h>
long long int a[100001],b[100001];
int main()
{ long long int t,l,r,i,j,z,n,m,flag=1,sum,sum1;
scanf("%llu",&t);
while(t--)
{flag=1,z=1,sum=0,sum1=0;
    scanf("%llu%llu",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%llu",&a[i]);
        b[i]=0;
    }

    for(i=1;i<=m;i++)
    {
       scanf("%llu%llu",&l,&r);
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