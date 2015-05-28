#include<stdio.h>
int ar[500][500];
int ans[500];
inline void fill(int temp[],int n,int k)
{
	int i,j;
	for(i=0;i<=n;i++)
		temp[i]=0;
	for(i=1;i<=n;i++)
		temp[ar[i][k]]++;
	
}
inline int getnext(int temp[],int n,int k)
{
	int i,v1=0,v2=0,x,nx,x1,nx1;
	x=x1=ans[k]-1;
	nx=nx1=n-ans[k];
	for(i=1;i<k;i++)
		if(ans[i]<ans[k])
			x1--;
		else
			nx1--;
	temp[x]-=x1;
	temp[ans[k]]-=nx1;
	
	for(i=1;i<=n;i++)
		if(temp[i])
		{	v2=v1;
		v1=i;
		}
	
	if(v2!=0)
		return v1;
	else if(v1>=ans[k])
		return v1+1;
	else
		return v1;		
			
}
int main()
{
	int test,n,i,j,x,nx;
	int temp[500];
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<n;j++)
				scanf("%d",&ar[i][j]);
		fill(temp,n,1);
		
		for(i=1;i<=n;i++)
				{
					x=i-1;
					nx=n-i;
					if(temp[i]>=nx && temp[x]>=i-1)
					{
						ans[1]=i;
						break;
					}
					
				}
		
		for(i=1;i<n;i++)
		{
			fill(temp,n,i);
			ans[i+1]=getnext(temp,n,i);
		}
		for(i=1;i<=n;i++)
			printf("%d ",ans[i]);
			printf("\n");	
	}
	return 0;
}