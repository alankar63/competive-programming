#include<stdio.h>
unsigned long long int cmp(const void *a,const void *b)
{
    return *(unsigned long long int *)a - *(unsigned long long int *)b;
}
main()
{
    int test,n,i,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        unsigned long long int a[n];
        for(i=0;i<n;i++)
            scanf("%ulld",&a[i]);
        qsort(a,n,sizeof(unsigned long long int),cmp);
        j=a[1]-a[0];
        for(i=2;i<n;i++)
        {
            if((a[i]-a[i-1])<j)
                j=a[i]-a[i-1];
        }
        printf("%d\n",j);
     }
     return 0;
}