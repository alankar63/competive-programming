#include<math.h>
#include<stdio.h>
#define max 100000
#define logmax 17
 
int s[logmax][max];
 
void compute(int M[logmax][max], int N)
{
	int i, j;
	for (i = 0; i < N; i++)
		scanf("%d",&M[0][i]);
	for (j = 1; 1 << j <= N; j++)
	{
		for (i = 0; i + (1 << j) - 1 < N; i++)
		{			
            if (M[j-1][i] > M[j - 1][i + (1 << (j - 1))])
				M[j][i] = M[j - 1][i];
            else
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
        }
    }
}  
 
int main() 
{
	int n;
	scanf("%d",&n);
	int i,m,x1,y1,xi,yi,k,x,y,xmod,ymod;
	long long sum=0,temp;
	compute(s,n);
	scanf("%d %d %d",&m,&xi,&yi);
	x=xi;
	y=yi;
 
	xmod=7%(n-1);
	ymod=11%n;
	x1=xi;
	y1=yi;
	if(xi>yi)
	{
		x1=yi;
		y1=xi;
	}
	
	k=log2(y1-x1+1);
	if(s[k][x1]>s[k][y1-(1 << (k))+1])
		temp=s[k][x1];
	else
		temp=s[k][y1-(1 << (k))+1];
	sum+=(long long)temp;
	long long back=(long long)temp;
	int flag=0;
	int Log2[110000];
	for (i=2;i<=n;i++) 
		Log2[i]=Log2[i>>1]+1;
	for(i=2;i<=m;i++)
	{
		xi=(xi+xmod);
		if(xi>=n-1)
			xi-=(n-1);
		yi=(yi+ymod);
		if(yi>=n)
			yi-=n;
		x1=xi;
		y1=yi;
		if(xi>yi)
		{
			x1=yi;
			y1=xi;
		}
		if(xi==x&&yi==y&&flag==0)
		{
			int temp2=m/(i-1);
			i=temp2*(i-1);
			i++;
			flag=1;
			sum*=temp2;
			if(i<=m)
				sum+=back;
			continue;
		}
		k=Log2[y1-x1+1];
		if(s[k][x1]>s[k][y1-(1 << (k))+1])
			temp=s[k][x1];
		else
			temp=s[k][y1-(1 << (k))+1];
		sum+=(long long)temp;
	}
	printf("%lld\n",sum);
	
	return 0;
}