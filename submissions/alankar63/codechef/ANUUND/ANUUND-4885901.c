#include<stdio.h>
long int a[100000];
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    int T,N,i,j,temp;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        scanf("%ld",&a[i]);
        qsort(a, N, sizeof(int), cmpfunc);
 
        if(N%2==0)
        {
            j=N/2;
            for(i=0;i<N/2;i++)
            {
                printf("%ld ",a[i]);
                printf("%ld ",a[j]);
                j++;
            }
            printf("\n");
        }
        else
        {
            j=N/2+1;
            for(i=0;i<=N/2;i++)
            {
                printf("%ld ",a[i]);
                if(j<N)
                printf("%ld ",a[j]);
                j++;
            }
            printf("\n");
        }
    }
    return 0;
}