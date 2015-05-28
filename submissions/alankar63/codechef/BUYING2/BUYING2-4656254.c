#include<stdio.h>
 
 
 
int main()
 
{
 
	int t,n,x,a[100],i,cst,w,flag; 
 
	
	scanf("%d",&t);
 
	while(t--)
 
	{
 
		cst = 0;
 
		flag = 0;
 
		scanf("%d %d",&n,&x);
 
		for(i=0;i<n;i++)
 
		{
 
			scanf("%d",&a[i]);
 
			cst += a[i];
 
		}
 
		w = cst % x;
 
		for(i=0;i<n;i++)
 
		{
 
			if(w >= a[i])
 
			{
 
				printf("-1\n");
 
				flag = 1;
 
				break;
 
			}
 
		}
 
		if(flag == 0)
 
			printf("%d\n",cst/x);
 
	}
 
}