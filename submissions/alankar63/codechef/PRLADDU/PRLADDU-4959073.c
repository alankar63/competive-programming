#include<stdio.h>
#include<stdlib.h>
int a[100001],d[100001],h[100001];
int abs(int c)
    {
        if(c<0) return (-c);
            return c;
    }
int main()
{ int t,i,j,n,m,max,d1,h1;
long long int ans;
scanf("%d",&t);
while(t--)
{ans=0;
d1=1;h1=1;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    if(a[i]>=0)
        h[h1++]=i;
    else
       d[d1++]=i;

}
i=j=1;
while(i<h1)
{
  if(a[h[i]]>(-a[d[j]]))
   {
   ans=ans+(-a[d[j]])*abs(d[j]-h[i]);

   a[h[i]]=a[h[i]]+(a[d[j]]);
      a[d[j]]=0;
   j++;
   }
   else if(a[h[i]]==(-a[d[j]]))
   {
      ans=ans+(-a[d[j]])*abs(d[j]-h[i]);
        a[h[i]]=0;
      a[d[j]]=0;
   j++; i++;
   }
   else
   {
       ans=ans+(a[h[i]])*abs(d[j]-h[i]);

   a[d[j]]=a[h[i]]+(a[d[j]]);
      a[h[i]]=0;
   i++;
   }




}

  printf("%llu\n",ans);
}
    return 0;
}