#include <stdio.h>
#include<math.h>
int main(void) {
	int n,x1[100],x2[100],x3[100],y1[100],y2[100],y3[100],i,maxindex,minindex;
	float a,b,c,s,area[100],max,min;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i],&x3[i],&y3[i]);
		a=sqrt(((x2[i]-x1[i])*(x2[i]-x1[i]))+((y2[i]-y1[i])*(y2[i]-y1[i])));
		b=sqrt(((x2[i]-x3[i])*(x2[i]-x3[i]))+((y2[i]-y3[i])*(y2[i]-y3[i])));
		c=sqrt(((x3[i]-x1[i])*(x3[i]-x1[i]))+((y3[i]-y1[i])*(y3[i]-y1[i])));
	//	printf("%d %d %d ",a,b,c);
		s=(a+b+c)/2;
	//	printf("%d ",s);
		area[i]=sqrt(s*(s-a)*(s-b)*(s-c));
		max=area[0];
		min=area[0];
	}
	//	printf("%d ",area[i]);
	//	printf("%d ",max);
	for(i=0;i<n;i++)
	{
		if(area[i]>=max)
		{
		max=area[i];
		maxindex=i+1;
		}
		if(area[i]<=min)
		{
		min=area[i];
		minindex=i+1;	
		}
	}
	printf("%d %d ",minindex,maxindex);
	// your code goes here
	return 0;
}