#include<stdio.h>
#include<math.h>
int n,s[18][2],a[18];
void comp(int k)
{
	int i,j;
	for(i=0;i<n-k+1;i++)
	{
		int max = a[i],count=1;
		for(j=i+1;j<i+k;j++)
		{
			if( a[j] == max)
			count++;
			else if(a[j]>max)
			{
				max = a[j];
				count=1;
			}
		}
		s[i][0] = max;
		s[i][1] = count;
	}
}
int check(int k,int m)
{
	int i;
	for(i=0;i<n-k+1;i++)
	if(s[i][1]>=m)
	return -1;
	
	return 1;
}
int convertbit(int bit[18],int num)
{
	int mm=-1;
	while(num>0)
	{
		bit[++mm] = num%2;
		num = num/2;
	}
	return mm;
}
int fun(int k,int m)
{
	comp(k);
 
	
	if(check(k,m)==1)
	return 0;
	
	int bit[18],i,l,j,min=100;
	l = (int)pow(2,n);
	
	for(i=1;i<l;i++)
	{
		int mm = convertbit(bit,i),count=0;
		for(j=0;j<=mm;j++)
		if(bit[j]==1)
		{
			a[j]++;
			count++;
		}
		comp(k);
		if(check(k,m)==1)
		{
			if(min>count)
			min = count;
		}
		for(j=0;j<=mm;j++)
		if(bit[j]==1)
			a[j]--;
	}
	if(min==100)
	return -1;
	return min;
}
 
int main()
{
	int t,i,k,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&k,&m);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		printf("%d\n",fun(k,m));
	}
	return 0;
}