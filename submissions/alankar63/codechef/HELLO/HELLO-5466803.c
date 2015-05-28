#include<stdio.h>
int main()
{
	int t,u,n,m,i,flag;
	float d,r,a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%f%d%d",&d,&u,&n);
		a=d*u;
		for(i=0;i<n;i++)
		{
		scanf("%d%f%f",&m,&r,&c);
		
		b=r*u + c/m;
		if(b<a)
		{
		a=b;
		flag=i+1;
     	}
	    }
	    printf("\n%d",flag);
		
	}
return 0;	
}