#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
long long int func(long long int n)
{
    return  ((n*(n+1))/2);
}
long long int s[100002];
int main()
{ long long int t,k,n,min,num,i,sum,l1,l2,flag;
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
        s[i]=num;
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
            flag=0;
         qsort(s,k,sizeof(long long int),compare);
           l1=0;
          i=0,sum=1;
        while(i<k)
        { if(sum<s[i])
           {   flag=1;
               break;}
           sum=sum-func(l1)+func(s[i]-1);
           l1=s[i];
             i++;
        }
        if(!flag)
        {
            sum=sum-func(l1)+func(n);
        }
          if((sum)%2==1)
          printf("Chef\n");
          else
          printf("Mom\n");

         //if((min%4)==0||(min%4)==1)
          // printf("Chef\n");
        // else
          // printf("Mom\n");
     }


 }

}


return 0;
}