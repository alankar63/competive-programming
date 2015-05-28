#include<stdio.h>
#include<math.h>
int main()
{
	long int a,b,c,n,i;
	//printf("%.0f",log(a)/log(2));
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
		fflush(stdin);
		scanf("%ld",&a);
		b=(int)(log(a)/log(2));
		printf("%.0f\n",pow(2,b));
	}
	return 0;
 
}