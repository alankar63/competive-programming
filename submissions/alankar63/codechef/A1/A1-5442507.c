#include <stdio.h>
 
int main(void) {
	int j,t,n,i,flag,m;
	long long int sum;
	scanf("%d",&t);
	while(t--)
	{
	    flag=0;
	    scanf("%d%d",&n,&m);
	    int a[n];
	    for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	    for(i=1;i<(1<<n);i++)
		{
			sum=0;
			for(j=0;j<n;j++)
			{
				if((i&(1<<j))>0)
				{
					sum+=a[j];
				}
			}
			if(sum==m)
			{
				flag=1;
				break;
			}
		}
		if(flag==1){printf("Yes\n");}
		if(flag==0)printf("No\n");
	}
	
	
	return 0;
}