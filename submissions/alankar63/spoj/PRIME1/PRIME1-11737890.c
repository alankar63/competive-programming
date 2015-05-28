#include<stdio.h>
#include<math.h>
 
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        long long m,n,i,j;
        scanf("%lld %lld",&m,&n);
        int primes[n-m+2];
        for(i=0; i<=n-m+1; i++)
            primes[i] = 0;
        if(m==1)    primes[0] = 1;
        for(i=2; i<=sqrt(n); i++)
        {
            j = m/i;    j *= i;
            if(j>m)
                j+=i;
            for(; j<=n; j+=i)
             {
                 if(j!=i)
                    primes[j-m] = 1;
             }
        }
 
        for(i=0; i<=n-m; i++)
            if(!primes[i])
                printf("%d ",i+m);
 
        printf("\n");
    }
}