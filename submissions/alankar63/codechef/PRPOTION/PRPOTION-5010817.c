#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main() {
      int t,i,n,j,r,g,b,m,te;
    scanf("%d",&t);
    long long int a[4],max,count;
    while(t--)
     {

        scanf("%d%d%d%d",&r,&g,&b,&m);
        max=0;count=0;
        for(i=1;i<=r;i++)//max from red bottle
        {scanf("%llu",&a[1]);
            if(a[1]>max)
            max=a[1];

        }
        a[1]=max;
         max=0;
        for(i=1;i<=g;i++)//for green
        {scanf("%llu",&a[2]);
            if(a[2]>max)
            max=a[2];

        }
         a[2]=max;
         max=0;
        for(i=1;i<=b;i++)
        {scanf("%llu",&a[3]);
            if(a[3]>max)
            max=a[3];

        }
         a[3]=max;
         for(j=1;j<4;j++)
            {
              if(a[j]>count)
              {

                count=a[j];
              }
            }
        for(i=1;i<=m;i++)
        {max=0,te=0;
            for(j=1;j<4;j++)
            {
              if(a[j]>max)
              {
                  te=j;
                max=a[j];
              }
            }
           a[te]=a[te]/2;
          max=0;
            for(j=1;j<4;j++)
            {
              if(a[j]>max)
              {
                max=a[j];
              }
            }
         //   if(max<count)
           //     count=max;
        }count =0;
         for(j=1;j<4;j++)
            {
              if(a[j]>count)
              {

                count=a[j];
              }
            }

        printf("%llu\n",count);
     }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}