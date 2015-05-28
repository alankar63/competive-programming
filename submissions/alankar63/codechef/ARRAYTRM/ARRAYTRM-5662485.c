#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,n,k,i;
    scanf("%d",&t);
 
    while(t--)
    {
        scanf("%d%d",&n,&k);
        int arr[n];
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
 
        int count=0;
        for(i=0;i<n;i++)
        {
            if(abs(arr[i]-arr[0])%(k+1)!=0)
            {
                count++;
                if(count>1)
                break;
 
            }
        }
        if(count<2)
        {
            printf("YES\n");
            continue;
        }
        count=0;
        for(i=0;i<n;i++)
        {
            if(abs(arr[i]-arr[1])%(k+1)!=0)
            {
                count++;
                if(count>1)
                break;
 
            }
        }
        if(count<2)
        {
            printf("YES\n");
            //continue;
        }
 
 
        else printf("NO\n");
 
    }
}