#include<stdio.h>
#include<stdlib.h>
//#include<time.h>
int comp(const void *a,const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;
    return *y-*x;
}
int count(int arr[],int c,int k)
{
    int i;c++;
    for(i=k-1; i>=1; i--)
    {
        if(arr[i]==arr[i-1])
            c++;
        else
            break;
    }
    return c;
}
int fact(int n)
{
    int i,f=1;
    for(i=2;i<=n; i++)
        f=f*i;
    return f;
}
int form(int n, int r)
{
    return fact(n)/((fact(n-r))*fact(r));
}
int main()
{
    int t,i,arr[11],k,m,r=0,n=0;
    //srand(time(NULL));
    scanf("%d",&t);
    while(t--)
    {
        //for(i=0; i<11; i++)
        //    arr[i]=rand()%20;
        for(i=0; i<11; i++)
            scanf("%d ",&arr[i]);
        qsort(arr,11,sizeof(*arr),comp);
        //for(i=0; i<11; i++)
        //    printf("%d ",arr[i]);
        //printf("\n");
        scanf("%d",&k);
        m=k-1;
        r=0;
        while(1)
        {
            if(arr[m]==arr[m+1]){
                r++;m++;}
            else
                break;
        }
        n=count(arr,r,k);
        //printf("n-->%d\n",n);
        //printf("r-->%d\n",r);
        printf("%d\n",form(n,r));
    }
    return 0;
}