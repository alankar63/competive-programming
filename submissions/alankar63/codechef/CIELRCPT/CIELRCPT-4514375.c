#include<stdio.h>
#include<math.h>
 
int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int sum=0,p,i;
		scanf("%d",&p);
		
		for(i=11;i>=0;i--)
		{
			sum=sum+p/(int)pow(2,i);
			p=p%(int)pow(2,i);
		}
		printf("%d\n",sum);
	}
	return 0;
}