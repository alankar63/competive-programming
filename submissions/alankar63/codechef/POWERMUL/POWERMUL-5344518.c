#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int total[95];
int prime[95]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};

void primefactors(long int n,long int pow,int flag)
{
    int i,j,k;
    i=0;
    while(i<95&&n>1)
    {
        while(n%prime[i]==0)
        {
            n=n/prime[i];
            if(flag==1)
            total[i]=total[i]+pow;
            else
               total[i]=total[i]-pow;
        }
        i++;
    }
}
long int fastpower(long int base,long int power,long long int M)
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
{long int t,n,q,b,r,i,temp;
long long int a,m;
scanf("%ld",&t);
while(t--)
{ scanf("%ld%llu%ld",&n,&m,&q);
    while(q--)
   {
       for(i=0;i<95;i++)
        total[i]=0;
    a=1;
        scanf("%ld",&r);
        b=n-r;
         if(n-r>r)
            {
               temp=n-r;
               b=r;
               r=temp;
            }
             i=r+1;
             while(i<=n)
             {
                primefactors(i,i,1) ;i++;
             }
             i=2;
         while(i<=n-r)
         {
             primefactors(i,i,0) ;i++;
         }
         for(i=0;i<95;i++)
         {
             if(total[i])
             {
                 a=(a*fastpower(prime[i],total[i],m))%m;
             }
         }
         printf("%llu\n",a);
   }
}

}