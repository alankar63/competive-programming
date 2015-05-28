#include<stdio.h>
int main()
{int t,i,a[101];
a[1]=1;
for(i=2;i<101;i++)
    a[i]=a[i-1]+(i*i);

while(1)
{ scanf("%d",&t);
    if (t==0)break;
    printf("%d\n",a[t]);
}

    return 0;
}
