#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int N;
long long int tree1[100002]={0};
long long int tree2[100002]={0};
void update(long long int arr[],long long int p,long long int v)
 {

    for (; p <= N; p += p&(-p))
        arr[p] += v ;
 }
    long long int  query(long long int arr[],long long int b)
  {

   long long int  sum = 0  ;
    for(; b > 0; b -= b&(-b))
        sum += arr[b];
    return sum;
  }
 long long int  que(long long int b)
   {

    return query(tree1, b) * b - query(tree2, b);
   }
int main()
{long long int i, t,u,l,r,val,q;

scanf("%llu",&t);
while(t--)
{
    scanf("%llu",&N);
for(i=1;i<=N;i++)
    tree1[i]=tree2[i]=0;
    scanf("%llu",&u);
    while(u--)
    {
        scanf("%llu",&q);
        if(q==0)
        {
            scanf("%llu%llu%llu",&l,&r,&val);
             update(tree1, l, val) 	;
    update(tree1, r + 1, -val) ;
    update(tree2, l, val * (l-1));
    update(tree2, r + 1, -val * r);

        }
        else
        {

           scanf("%llu%llu",&l,&r);
            printf("%llu\n",que(r)-que(l-1));

        }
    }
}
    return 0;
}
