#include<stdio.h>
int main ()
{
	int t;
	float ds, dt, d;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%f%f%f", &ds, &dt, &d);
		if(d>=ds+dt)
		printf("%.100f\n", d-(ds+dt));
		else if(dt>=ds+d)
		printf("%.100f\n", dt-(ds+d));
		else if(ds>=dt+d)
		printf("%.100f\n", ds-(d+dt));
		else
		printf("0\n");
	}
	return 0;
}