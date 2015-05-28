#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define mod 1000000007
#define gc getchar_unlocked
inline int inp(){
	int  n=0;
	char c;
	c=gc();
	while(c<'0' || c>'9'){
		c=gc();
	}
	while(c>='0' && c<='9'){
		n=(n<<3)+(n<<1)+c-'0';
		c=gc();
	}
	return n;
}
long long int powr(long long int a, int b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2 == 0)
    {
        long long int temp = powr(a,b/2);
        return (temp*temp);
    }
    else
    {
        long long int temp = powr(a,b/2);
        temp = (temp*temp);
        return (temp*a);
    }
}

bool mark[100002],primes[100001];

int main()
{int test,flag,max,bs[100001];
long long int mn[100002],ar[100002];
long long int n,i,count,j=1,k,ans;
for(i=0;i<100001;i++)
    primes[i]=1;

test=inp();
for(i=2;i<100000;i++)
{if (primes[i])
      {
        for (j=i;i*j<100001;j++)
            primes[i*j]=0;
      }
}

while(test--)
{ans=1;


    n=inp();
for(i=0;i<=n;i++)
    bs[i]=0;
    for(i=1;i<=n;i++)
    {
        mn[i]=inp();
       // mn[i]=getchar_unlocked();
        mark[i]=0;
    }

    flag=0;j=1;

/*    while(flag==0)
  {

    i=1;
    while(mark[i]==1)
    {
        i=i+1;
        if(i==n+1){flag=1;break;}
    }

    count=0;

    while(mark[i]!=1&&(flag==0))
    {mark[i]=1;
      i=mn[i];
      count=count+1;
    }

    if(flag==0)
   {

    ar[j]=count;
    j=j+1;}

  }*/  for( i=1;i<=n;i++)
        {

            if(!mark[i])
            {

                count = 1;
                k=i;
                mark[i]=1;
                while ( mn[k] != i ){
                    k = mn[k];
                    count++;
                    mark[k]=1;
                }ar[j]=count;j++;
            }
        }
j=j-1;
for(i=1;i<=j;i++)
{
    for(k=2;k<=n-j+1;k++)
   {if(primes[k])
   {count=0;
       while(ar[i]%k==0)
       {
           count=count+1;
           ar[i]=ar[i]/k;
       }
        if(count>bs[k])bs[k]=count;
        if(ar[i]==1)break;
   }
   }
}
for(i=2;i<=n;i++)
{   if(primes[i])
    ans=(ans*(powr(i,bs[i]))%mod)%mod;
}

    printf("%llu\n",ans);
}
    return 0;
}