#include<stdio.h>
void swap(long long int *a,long long int *b)
{
   long long int t=*a;
   *a=*b;
   *b=t;
}
long long int part(long long int a[],long long int l,long long int h)
{
    long long int x=a[h];
    long long int i=l-1,j;
    for(j=l;j<=h-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    return i+1;
}
void quick(long long int a[],long long int l,long long int h)
{
    if(h>=l)
    {
        long long int p=part(a,l,h);
        quick(a,l,p-1);
        quick(a,p+1,h);
    }
}
int main()
{
    long long int n,m,h,i,j,ans=0,tot,remain,x,y,sum=0,max1=0;
    long long int t[100000];
    long long int c[100002]={0};
    scanf("%lld%lld%lld",&n,&m,&h);
    for(i=0;i<h;i++)
    {
        scanf("%lld%lld",&x,&y);
        sum +=x;
        c[y] +=x;
        if(max1<y)
            max1=y;
    }
    //quick(c,0,h-1);
    tot=n*m;
    if(sum<tot)
    printf("Impossible");
    else
    {
        for(i=0;i<=max1;i++)
        {
            if(c[i])
            {
                if(c[i]<=tot)
                {
                    ans +=c[i]*i;
                    tot -=c[i];
                }
                else
                {
                    ans +=tot*i;
                    break;
                }
            }
        }
        printf("%lld",ans);
    }
    return 0;
}