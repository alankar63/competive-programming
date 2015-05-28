#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{   long double val,val1,ans;
   long double t,b,x;
    long double y;
    long long int a,c,d,k;
    scanf("%Lf",&t);
    while(t--)
    {
        scanf("%Lf",&x);
       //  printf("%Lf\n",x);
        scanf("%llu",&k);
        // printf("%llu\n",k);
         a=0;
         d=1;
         while(d<=k)
         {
           d=d*2;a++;
         }
         // printf("%llu\n",a);
 
      //  val=(long double)x/(long double)pow(2,a);
       c=1;
       val=x;
      // printf("%Lf",val);
       while(c<=a)
       {//printf("%Lf\n",val);
           c=c+1;
        val=val/(double)2;
        //printf("%Lf\n",val);
       }
         //printf("%Lf\n",val);
        val1=(long double)x/(long double)pow(2,a-1);
        // printf("%Lf\n",val1);
        y=k-pow(2,a-1);
       // printf("%Lf\n",y);
        ans=val+val1*y;
        printf("%Lf\n",ans);
 
    }
    return 0;
}