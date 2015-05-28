#include<stdio.h>
int main()
{
    int t;
    long int n,a[100001],k,i,temp;
    scanf("%d",&t);
    while(t--)
    {
        k=0;
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
            if((a[i]+i)>k)
                {
                    k=a[i]+i;
                }
        }
        printf("%ld\n",k);
    }
    return 0;
}