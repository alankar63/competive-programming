#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main()
{
	int t,n,k,a[1001],i,j,o;
	char str[10];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&k,&o);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%s",str);
		if (k==0) 
			printf("%d\n",o);
		else 
		{
			if(str[0]=='A')
			{
				for(j=0;j<n;j++)
				{
					o &= a[j];
				}
			}
			else if(str[0]=='O')
			{
				for(j=0;j<n;j++)
				{
					o |= a[j];
				}
			}
			else
			{
				if (k%2 !=0) 
				{
					for(j=0;j<n;j++)
					{
						o ^= a[j];
					}
				}
			}
			printf("%d\n",o); 
		}
	}
	return 0;
}