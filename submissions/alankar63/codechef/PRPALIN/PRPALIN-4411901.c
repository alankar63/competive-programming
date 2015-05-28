# include <stdio.h>
 
char sieve[1003002]={0};
int st[200];
int r=0;
 
void seiv()
{
	int i,j,z,s;
	for(i=2;i<1003002;i++)
	{
		if(sieve[i]==1)continue;
		j=2;
		while(i*j<1003002) { sieve[i*j]=1; j++; }
		z=i;s=0;
		while(z!=0)
		{ s=s*10+z%10; z=z/10; }
		if(s==i)st[r++]=s;
 
	}
	return ;
}
 
int b(int key)
{
	int l=0; int h=r-1,mid;
	while(l<h-1)
	{
		//printf("%d %d\n",l,h);
		mid=(h+l)/2;
		if(st[mid]>=key)h=mid;
		else l=mid; 
	}
printf("%d\n",st[h]);
 
}
 
 
int main()
{
	int a;
	seiv();
		scanf("%d",&a);
		if(a<2){printf("2\n");return 0;}
		b(a);
	return 0;
}