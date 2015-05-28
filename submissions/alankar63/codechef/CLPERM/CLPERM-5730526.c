#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main() 
{ long long int t,k,n,min,num,i;
scanf("%llu",&t);
while(t--)
{scanf("%llu",&n);
min=n+1;
scanf("%llu",&k);
for(i=0;i<k;i++)
{
    scanf("%llu",&num);
    if(num<min)
        min=num;
}
 if(k==0) {
    if(((n*(n+1))/2)%2==1)
printf("Mom\n");
else
printf("Chef\n");
    
 } 
 else 
 {
     if(min==1)
     printf("Chef\n");
     else if(min==2)
     printf("Mom\n");
     else
     {
         if(min%2)
           printf("Chef\n"); 
         else
           printf("Mom\n"); 
     }
        
        
 }

} 
 
 
return 0;
}