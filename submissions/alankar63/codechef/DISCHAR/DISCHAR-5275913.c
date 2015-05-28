#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[200];
char b[100004];
int main()
{int t,i,n,count;
    scanf("%d",&t);
    while(t--)
    {// scanf("%d",&n);
        count=0;
       for(i=0;i<200;i++)
            a[i]=0;
             scanf("%s",b);
             i=0;
             while(b[i]!='\0')
             {
                 a[b[i]-20]++;
                 i++;
             }
             for(i=0;i<200;i++)
                if(a[i])
                    count++;

             printf("%d\n",count) ;

    }

    return 0;
}