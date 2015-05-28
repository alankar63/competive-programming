#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{   double val,val1,ans;
    int t,a,b,c,d;
    double x,k,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&x);
        scanf("%lf",&k);
        // printf("%20.18f\n",k);
         a=((double)log10(k)/(double)log10(2.000000000))+1;
         // printf("%d\n",a);

        val=x/pow(2,a);
         //printf("%20.18f\n",val);
        val1=x/pow(2,a-1);
         //printf("%20.18f\n",val1);
        y=k-pow(2,a-1);
         //printf("%20.18f\n",y);
        ans=val+val1*y;
        printf("%20.18f\n",ans);

    }
    return 0;
}