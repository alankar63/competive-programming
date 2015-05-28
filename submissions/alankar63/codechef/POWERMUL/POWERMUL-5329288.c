#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long int fastpower(long int base,long int power,long int M)
{
        long int result=1;
        while (power>0)
        {
                if ((power&1)==1)
                        result = (result*base)%M;
                base = (base*base)%M;
                power/=2;
        }
        return result;
}
int main()
{  long int t,n,m,q,a,b,r,i,temp;
scanf("%ld",&t);
while(t--)
{
    scanf("%ld%ld%ld",&n,&m,&q);
    while(q--)
    { a=1;
        scanf("%ld",&r);
        b=n-r;
        if(n<=5)
        {


        i=2;
        while(i<=n)
        {a=a*pow(i,i);i++;
        }
       // printf("%llu\n",a);
        i=2;
        while(i<=r)
        {a=a/(int)pow(i,i);i++;
        }
             //   printf("%llu\n",a);

        i=2;
        while(i<=b)
        {a=a/(int)pow(i,i);i++;
        }
       // printf("%llu\n",a);

    printf("%ld\n",a%m);
        }
        else
        {
            if(n-r>r)
            {
               temp=n-r;
               b=r;
               r=temp;
            }
            i=r+1;
             while(i<=n)
        {a=(a*fastpower(i,i,m))%m;i++;
        }
        i=2;
         while(i<=n-r)
        {a=(a*fastpower(fastpower(i,i,m),m-2,m))%m;i++;
        }
          printf("%ld\n",a);
        }
}
}
    return 0;
}