#include <stdio.h>
#include <stdlib.h>
int Maxval;
long long int tree[1000001]={0};
inline void input(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}
void update(int idx,int val)
{
    while(idx<=Maxval)
    {
        tree[idx]+=val;
        idx+=(idx&(-idx));
    }
}
long long int read(int idx)
{
    long long int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
int main()
{
    int n,m,c,u,v,k,p,i;
    long long int sum;
    char ch;
    input(&n); input(&m); input(&c);
    //scanf("%d %d %d",&n,&m,&c);
    Maxval=n;
    while(m--)
    {
        ch=getchar();
        while(!(ch=='Q'||ch=='S'))
            ch=getchar();
        if(ch=='S')
        {
            input(&u); input(&v); input(&k);
            //scanf("%d %d %d",&u,&v,&k);
            if(k==0)
            continue;
            update(u,k);
            if(v<n)
            update(v+1,-k);
 
        }
        else if(ch=='Q')
        {
            input(&p);
            //scanf("%d",&p);
            sum=read(p);
            printf("%lld\n",sum+c);
        }
    }
    //printf("Hello world!\n");
    return 0;
}