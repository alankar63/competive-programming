#include<stdio.h>
#define MAX 1000000
int main(){
long long int n[3],i,j,t,a[MAX],p=0;a[0]=0;
for(i=1;i<MAX;i++)a[i]=0;
scanf("%lld%lld%lld",&n[0],&n[1],&n[2]);
for(j=0;j<3;j++)
 for(i=0;i<n[j];i++)
  {scanf("%lld",&t);
    a[t]++;
        }
        for(i=1;i<MAX;i++)
        if(a[i]>=2)p++;
    printf("%lld\n",p);
    for(i=1;i<MAX;i++)
    if(a[i]>1)printf("%lld\n",i);
    return 0;
    }