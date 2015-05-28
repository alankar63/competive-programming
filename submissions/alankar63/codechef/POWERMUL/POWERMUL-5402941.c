#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int prime[501]={0};
long int fact[501][501]={{0}};
long int total[501]={0};
int count[501]={0};

//prime[1]=prime[0]=0;
void seive()
{ int j,i;
    for (i=2;i<=500;i++)
        if (!prime[i])
            for (j=i;i*j<=500;j++)
                prime[i*j]=1;

}
void calc()
{int i,j,k,l,m,n;
  for(i=2;i<500;i++)
  {   if(!prime[i])
    {

      for(j=i;j<=500;j=j+i)
      {

          {k=0;
            while((count[j]%i)==0)
            {
                k++;
               count[j]=count[j]/i;
            }
              fact[j][i]=fact[j-i][i]+k*j;
          }
      }
    }

  }

}
long long int fastpower(long long int base,long int power,long long int M)
{
        long long int result=1;
        while (power>0)
        {
                if ((power&1)==1)
                        result = (result*(base))%M;
                base = (((base)*(base)))%M;
                power/=2;
        }
        return result;
}
int main()
{long int t,n,q,b,r,temp,x;
long long int a,m,i;
for(i=1;i<=500;i++)
    count[i]=i;
scanf("%ld",&t);
seive();
calc();
while(t--)
{scanf("%ld%llu%ld",&n,&m,&q);
  while(q--)
  {for(i=1;i<=n;i++)
        total[i]=0;
          scanf("%ld",&r);
        b=n-r;
        a=1;
         if((n-r)>r)
            {
               temp=n-r;
               b=r;
               r=temp;
            }
            for(x=2;x<=n;x++)
            {if(!prime[x])
                total[x]=fact[x*(n/x)][x]-fact[x*(r/x)][x];
            }
            for(x=2;x<=n-r;x++)
               {if(!prime[x])
                   total[x]=total[x]-fact[x*((n-r)/x)][x];

               }
            for(i=2;i<=n;i++)
         {
             if(total[i])
             {
                 a=(a*fastpower(i,total[i],m))%m;
             }
         }
          printf("%llu\n",a);
  }

}
    return 0;
}