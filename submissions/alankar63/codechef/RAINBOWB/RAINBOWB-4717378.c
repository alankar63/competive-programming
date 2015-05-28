#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define mod 1000000007
 long long int C[500001][7];
// Prototype of a utility function that returns minimum of two integers
int min(int a, int b);

// Returns value of Binomial Coefficient C(n, k)
long long int binomialCoeff(int n)
{

    int i, j;

    // Caculate value of Binomial Coefficient in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= min(i, 6); j++)
        {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1;

            // Calculate value using previosly stored values
            else
                C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }

    return C[n][6];
}

// A utility function to return minimum of two integers
int min(int a, int b)
{
    return (a<b)? a: b;
}


int main()
{int n,i,j;
long long int k;
scanf("%d",&n);
k=1;
if(n<13)
    printf("0");
else
{
 i=((n-13)/2);
 k=binomialCoeff(i+6);

 printf("%llu",k);
}

    return 0;
}