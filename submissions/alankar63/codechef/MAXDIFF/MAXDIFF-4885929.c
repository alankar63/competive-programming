#include<stdio.h>
#include<stdlib.h>
 
int main()
{
	int p=0,test,m=0,i,j,size,k,ind=0;
	
	scanf("%d",&test);
	unsigned long long int a=0,b=0,c=0,temp,ans[test];
	ind=0;
	for(m=0;m<test;m++)
	{        
		ans[ind]=0;
		a=0;b=0;
		scanf("%d",&size);
		scanf("%d",&k);
	
		unsigned long long int arr[size];
 
		for(i=0;i<size;i++)
		{
			scanf("%llu",&arr[i]);
		}
 
		for(i=0;i<size;i++)
		{
			for(j=i+1;j<size;j++)
			{
				if(arr[j]<arr[i])
				{
					temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
			}
		}
		if(k<=size-k)
		{
			
			for(i=0;i<k;i++)
			{
				a=a+arr[i];
			}
			for(i=k;i<size;i++)
			{
				b=b+arr[i];
			}
			c=b-a;
			ans[ind]=c;
			ind++;
		}
		else
		{
			for(i=0;i<size-k;i++)
			{
				a=a+arr[i];
			}
			for(i=size-k;i<size;i++)
			{
				b=b+arr[i];
			}
			c=b-a;
			ans[ind]=c;
			ind++;
		}
	}
	for(p=0;p<ind;p++)
	{
		printf("%d\n",ans[p]);
	}
	return 0 ;
}