#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int N;
long long int tree[10002]={0};
void update(long long int p,long long int v)
 {

    for (; p <= N; p += p&(-p))
        tree[p] += v ;
 }
      long long int  query(long long int b)
  {

   long long int  sum = 0  ;
    for(; b > 0; b -= b&(-b))
        sum += tree[b];
    return sum;
  }

//long long int tree[10002]={0};
int main()
{ long long int i, t,u,l,r,val,q;

scanf("%llu",&t);
while(t--)
{
scanf("%llu",&N);
for(i=1;i<=N;i++)
    tree[i]=0;
 scanf("%llu",&u);
 while(u--)
 {
    scanf("%llu%llu%llu",&l,&r,&val);
     update(l+1, val) ;
    update(r + 2, -val);

 }
  scanf("%llu",&q);
  while(q--)
  {
       scanf("%llu",&u);
       printf("%llu\n",query(u+1));
  }

}
    return 0;
}
