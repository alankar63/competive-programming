#include<stdio.h>
#include<stdlib.h>
#define gc getchar()
inline void read(int *i)
{
	*i=0;
	char ch=gc;
	int sign=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
			sign=-1;
		ch=gc;
	}
	while(ch>='0' && ch<='9')
	{
		*i=(*i)*10+ch-'0';
		ch=gc;
	}
	(*i)*=sign;	
}
int cmp(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}
int main()
{
	int n,d,i,ans=0;
	read(&n);read(&d);
	int a[n];
	for(i=0;i<n;i++)
		read(&a[i]);
	qsort(a,n,sizeof(int),cmp);
	for(i=1;i<n;i++)
	{
		if(a[i]-a[i-1]<=d)
		{
			i++;
			ans++;
		}
	}
	printf("%d\n",ans);
}