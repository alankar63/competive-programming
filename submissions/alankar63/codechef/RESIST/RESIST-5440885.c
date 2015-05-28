#include<stdio.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n,m,i;
		int p=1;
		int q=1;
		scanf("%d %d",&n,&m);
        for(i=1;i<n;i++)
        {
           p=(p+q)%m;
           q=(p+q)%m;
        } 
        printf("%d/%d\n",p,q);     
	}
	return 0;
}