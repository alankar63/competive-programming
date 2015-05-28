#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define gc getchar_unlocked
int laser[18][2];//for counting lasers  ,after last laser we  have -1
int status;//final ans
int n,m;
int g[53][53];
inline int inp()  //for fast input
{
     int h=0,sign=1;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';
    

        c=gc();
    } //n=n*sign;

     return h;
}

int func(int x,int rem)//x starts from 0;rem is total rem enemy and g is full array
{
	if(rem==0)//all enemies killed
	{status=1;return;}
	if(laser[x][0]==-1)//no lasers
		return;

	int c1,c2,c3;// to iterate horizontal and vertical
	c1=c2=c3=0;
	int i,j,k;
	i=laser[x][0];
	j=laser[x][1];
	for(k=j+1;k<m;k++)//horizontally ahead
		if(g[i][k]>=2)
		{
		if(g[i][k]==2)
			c1++;
		g[i][k]++;

		}


	if(c1)
	{	func(x+1,rem-c1);
		if(status)
			return;

	}

	for(k=m-1;k>j;k--)//reverting the changes
			if(g[i][k]>=2)
			g[i][k]--;
 
	for(k=j-1;k>=0;k--)//horizontally behind
		if(g[i][k]>=2)
		{
			if(g[i][k]==2)
			c2++;
		g[i][k]++;

		}


	if(c2)
	{	func(x+1,rem-c2);
		if(status)
			return;

	}

	for(k=0;k<j;k++)//reverting the changes
			if(g[i][k]>=2)
			g[i][k]--;

	for(k=i-1;k>=0;k--)//vertically up
		if(g[k][j]>=2)
		{
		if(g[k][j]==2)
			c3++;
		g[k][j]++;

		}

	if(c3)
	{
		func(x+1,rem-c3);
		if(status)
			return;

	}

	for(k=0;k<i;k++)//reverting the changes
			if(g[k][j]>=2)
			g[k][j]--;
	if(!c1 && !c2 && !c3)
		func(x+1,rem);
}
 int main()
{
	int count,test,i,j,x;
	char c[50];
	test=inp();
	//scanf("%d",&test);
	while(test--)
	{
	status=0;count=0;x=0;
	n=inp();m=inp();
	//scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		for(j=0;j<m;j++)
			if(c[j]=='.')
				g[i][j]=0;
			else if(c[j]=='L')
				{g[i][j]=1;laser[x][0]=i;laser[x++][1]=j;}
			else
				{g[i][j]=2;count++;}
	}
	laser[x][0]=laser[x][1]=-1;
	func(0,count);
	if(status)
		printf("Possible\n");
	else
		printf("Impossible\n");
	}
	return 0;
}