#include<stdio.h>
int main()
{
	int t,n,c,q,l,r,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&c,&q);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			if(l<=c && c<=r)
			{
				i = c - l;
				c = r - i;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}