#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main() 
{ long long int t,k,n;
scanf("%llu",&t);
while(t--)
{scanf("%llu",&n);
scanf("%llu",&k);
if(((n*(n+1))/2)%2==1)
printf("Mom\n");
else
printf("Chef\n");
} 


return 0;
}