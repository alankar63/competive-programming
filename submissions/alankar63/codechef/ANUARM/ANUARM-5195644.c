#include<stdio.h>
 
int main()
{
    int t,n,k,m,i,j,min,max;
    int a[100001],b[100001];
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		a[i]=0;
		for(i=0;i<m;i++)
		scanf("%d",&b[i]);
		max=b[0];
		for(i=1;i<m;i++)
		{
			if(b[i]>=max)
			max=b[i];
		}
			min=b[0];
		for(i=1;i<m;i++)
		{
		    if(b[i]<=min)
			min=b[i];
		}
		
			j=0;
			for(i=min;i<n;i++)
			{
				a[i]=j;
				j++;
	        }
	        j=0;
	        for(i=max;i>=0;i--)
			{
				if(j>=a[i])
				a[i]=j;
				j++;
			}
		for(i=0;i<n;i++)
		printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}