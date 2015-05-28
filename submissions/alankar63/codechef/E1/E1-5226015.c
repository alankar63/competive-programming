//top down approach

#include<stdio.h>
#define MAX(a,b) (a>b?a:b)
int t,a,b,n,i,j;
char board[1001][1001];
int memo[1001][1001];
 
int main()
{
scanf("%d",&t);
while(t--)
{
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%s",board[i]);
for(j=0;j<n;j++)
{
memo[i][j]=-1;
if(board[i][j]=='K')
{
a=i;b=j;
}
}
}
printf("%d\n",calc(a,b));
}
return 0;
}
 
int calc(int i, int j)
{
int count=0;
if(i<0 || i>n-1 || j>n-1) return 0;
if(memo[i][j]!=-1) return memo[i][j];
count=calc(i-2,j+1);
count=MAX(count,calc(i-1,j+2));
count=MAX(count,calc(i+1,j+2));
count=MAX(count,calc(i+2,j+1));
if(board[i][j]=='P') memo[i][j]=count+1;
else memo[i][j]=count;
return memo[i][j];
}