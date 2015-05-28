#include <bits/stdc++.h>
int p[10000009];
long long ans[10000009];
void cal()
{
 for(int i=2;i<=10000000;i++)
 {
  if(!p[i])
  {
   for(int j=i+i;j<=10000000;j+=i)
    if(!p[j])
     p[j]=i;
   ans[i]=ans[i-1]+i;
  }
  else
   ans[i]=ans[i-1]+p[i];
 }
}
int main()
{
 int t;
 cal();
 scanf("%d",&t);
 while(t--)
 {
  int n;
  scanf("%d",&n);
  printf("%lld\n",ans[n]);
 }
 return 0;
}