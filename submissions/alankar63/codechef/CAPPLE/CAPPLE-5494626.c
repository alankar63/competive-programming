#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{int a,b,c,t,n,count,i;
scanf("%d",&t);
while(t--)
{c=10000001;
count=1;
    int f[100001]={0};
    scanf("%d",&n);
    for(a=1;a<=n;a++)
    {
        scanf("%d",&b);
        if(b<c)
            c=b;
        f[b]++;
    }
     for(i=c+1;i<=100000;i++)
     {
         if(f[i])
            count++;
     }
     printf("%d\n",count);
}

    return 0;
}