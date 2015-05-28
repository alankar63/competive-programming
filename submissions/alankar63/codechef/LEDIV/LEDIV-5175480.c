#include <stdio.h>
#include<math.h>
int gcd(int a,int b)
{
	if(b==0)
      return a;
      else return gcd(b,(a%b));
}
int b[100001]={0};
int a[100000];
int main(void) {
	
	int j,t,n,flag,g,i;
	scanf("%d",&t);
	b[1]=-1;
	for(i=2;i<=100000;i++)
	{
		for(j=i;j<=100000;j+=i)
		{
			if(b[j]==0)
			b[j]=i;
		}
	}
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		scanf("%d",&a[0]);
		g=a[0];
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			g=gcd(g,a[i]);
		}
		printf("%d\n",b[g]);
		
		/*for(i=2;i<=sqrt(g);i++)
		{
			if(g%i==0)
			{
				flag=1;
				printf("%d\n",i);
				break;
			}
		}
		if(flag==0&&g>100000)
		{
			printf("-1\n");
		}
		else if(flag==1) continue;
		else printf("%d\n",g);*/
	}
	return 0;
}