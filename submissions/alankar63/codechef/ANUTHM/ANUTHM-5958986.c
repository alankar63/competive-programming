#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double n,m;
		scanf("%lf%lf",&n,&m);
		n = n+m-1;
		printf("%f\n",n);
	}
	return 0;
}