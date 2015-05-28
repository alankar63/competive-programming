#include<stdio.h>
#include<math.h> 
void primeFactors(int a);
int a[1000000]={0};
int main(){
    int t,n,temp,prod,i,ans,count;
	scanf("%d",&t);
	while(t--){
		for(i=0;i<1000000;i++)
			a[i]=0;
		prod=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
        {
			scanf("%d",&temp);
			primeFactors(temp);
		}
		ans=1;
		count=1;
	for(i=0;i<1000000;i++)
		ans=ans*(a[i]+1);
		printf("%d\n",ans);
	}	
	return 0;
}
void primeFactors(int n)
{
    int ind=0,i;
    while (n%2 == 0)
    {
        a[2]+=1;
        n = n/2;
    }
    for (i = 3; i <= (n); i = i+2)
    {
   while (n%i == 0){
        	a[i]+=1;
            n = n/i;
        }}   
    if (n > 2)
        a[n]+=1;
}