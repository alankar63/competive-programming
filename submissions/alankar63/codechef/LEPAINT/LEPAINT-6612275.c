#include <stdio.h>
 
int t,n,c,k,l1,l2,i,j,k;
 
int main(void) {
scanf("%d",&t);
while(t--)
{
int r[55]={0};
double a[55][105]={0};
int maxr=0;
double ans=0;
scanf("%d",&n);
scanf("%d",&c);
scanf("%d",&k);
while(k--)
{
scanf("%d",&l1);
scanf("%d",&l2);
for(i=l1-1;i<l2;i++)
{
r[i]++;
if(r[i]>maxr)
maxr=r[i];
}
}
a[0][1]=1;
for(i=0;i<maxr;i++)
{
for(j=0;j<c;j++)
{
a[i+1][j]+=a[i][j]/2;
for(k=0;k<c;k++)
{
a[i+1][(j*k)%c]+=a[i][j]/(2*c);
}
}
}
for(i=0;i<n;i++)
{
for(j=0;j<c;j++)
{
ans+=a[r[i]][j]*j;
}
}
printf("%.9f\n",ans);
}
return 0;
}