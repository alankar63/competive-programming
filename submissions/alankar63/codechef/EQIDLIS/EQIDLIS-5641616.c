#include<stdio.h>
int a[3001],t,d,cnt,i,j,n,sum,x;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<3001;i++)
            a[i]=0;
        cnt=0;
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[x]++;
            sum+=x;
            if(j<x)
                j=x;
        }
        if(sum%n!=0)
        {
            printf("-1\n");
            continue;
        }
        else
        {
            i=0;
            while(i<sum/n)
            {
                if(a[i]>0)
                {
                    d=j-i;
                    d=d/2;
                    a[i]--;
                    a[j]--;
                    a[i+d]++;
                    a[j-d]++;
                    cnt++;
                }
                {
                    while(a[i]==0)
                        i++;
                    while(a[j]==0)
                        j--;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}