#include<stdio.h>
int diff(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,i,j,k,n,m,p,ma[10000],r[100],v[101][101];
	long long int total;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&ma[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&v[i][0]);
			for(j=1;j<=v[i][0];j++)
			{
				scanf("%d",&v[i][j]);
			}
			qsort(v[i]+1,v[i][0],sizeof(int),diff);
		}
		total=0;
		for(i=0;i<m;i++)
		{
			total=total+v[ma[i]][v[ma[i]][0]];
			v[ma[i]][0]--;
			if(v[ma[i]][0]<0)
			{
				v[ma[i]][0]=0;
			}
		}
		printf("%lld\n",total);
	}
	return 0;
}