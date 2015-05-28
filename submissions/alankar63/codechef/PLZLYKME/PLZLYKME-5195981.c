#include <stdio.h>
#include<math.h>
int main(void) {
	int t;
	double l,d,s,c,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&l,&d,&s,&c);
			ans=s*pow(c+1,d-1);
			if(ans>=l)
			printf("ALIVE AND KICKING\n");
			else printf("DEAD AND ROTTING\n");
	}
	return 0;
}