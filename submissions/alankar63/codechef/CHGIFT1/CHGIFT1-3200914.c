#include<stdio.h>
 
int main()
{
long long int t,n,count,min,sol,max,temp,tmax,tmin,num,i,j,k;
scanf("%lld",&t);
while(t--)
	{
	scanf("%lld",&n);
	scanf("%lld",&num);
	min=num;
	for(i=1;i<n;i++)
	{scanf("%lld",&num);
	   if((min-num)>min*num)
	      min=min*num;
	   else
	   min=min-num;   
	
		}			
	printf("%lld\n",min);
	} 
return 0;
}