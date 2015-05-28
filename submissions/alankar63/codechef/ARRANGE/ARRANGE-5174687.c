#include<stdio.h>
#include<math.h>
#define x 65540
char jp[x];
int mylove(int a,int n)
{
	int i,hc[16],k=0,temp;
	for(i=0;i<n;i++)
	{
		hc[i]=0;
	}
	while(a>0)
	{
		if(a%2==1)
		{
			hc[k]=1;
			k++;
		}
		else
			k++;
		a=a/2;
		
	}
	for(i=0,temp=0;i<n;i++)
	{
		temp=temp+pow(2,(n-1-i))*hc[i];
	}
	return temp;
}
int main()
{
	int i,t,k,j;
	char a[x];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %s",&k,a);
		for(i=0;a[i]!='\0';i++)
		{
			jp[mylove(i,k)]=a[i];
		}
		for(i=0;a[i]!='\0';i++)
		{
			printf("%c",jp[i]);
		}
		printf("\n");
	}
	return 0;
}