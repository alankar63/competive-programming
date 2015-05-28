#include<stdio.h>
#include<math.h>
int main()
{
    int t,s;
     int a,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        s=sqrt(n);
        a=n-1;
        for(i=s;i>=1;i--)
        {
            if(n%i==0)
               {a=n/i-i; break;}
        }
 
        printf("%d\n",a);
    }return 0;
}