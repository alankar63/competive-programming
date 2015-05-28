#include <stdio.h>
int a[1000001];
int main(void) {
	int t,k;
	scanf("%d",&t);
	int r,i,q=33102;
	r=103993%33102;
	for(i=0;i<1000001;i++)
	{
		a[i]=(r*10)/q;
		r=(r*10)%q;
	}
	while(t--)
	{
		scanf("%d",&k);
		if(k==0)printf("3\n");
		else
		{
			printf("3.");
			for(i=0;i<k;i++)printf("%d",a[i]);
		}
		if(k!=0)printf("\n");
	}
	return 0;
}