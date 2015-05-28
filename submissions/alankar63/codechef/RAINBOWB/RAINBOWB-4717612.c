#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define mod 1000000007
 //long long int C[500001][7];
// Prototype of a utility function that returns minimum of two integers
int min(int a, int b);

long long int binomialCoeff(int n, int k)
{
    int* C = (int*)calloc(k+1, sizeof(long long int));
    int i, j, res;

    C[0] = 1;

    for(i = 1; i <= n; i++)
    {
        for(j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }

    res = C[k];  // Store the result before freeing memory

    free(C);  // free dynamically allocated memory to avoid memory leak

    return res;
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
 k=binomialCoeff(i+6,6);

 printf("%llu",k);
}

    return 0;
}