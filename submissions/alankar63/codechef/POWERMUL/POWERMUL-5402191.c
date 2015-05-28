#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define gc getchar_unlocked
inline long  int inp()
{
   long int h=0,sign=1;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {if(c=='-')	sign=-sign;
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';
 
 
        c=gc();
    } h=h*sign;
 
     return h;
}
 
int pr[96]={0,2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
int prime[501]={0};
int fact[501][96]={{0}};
long int total[96]={0};
 
//prime[1]=prime[0]=0;
/*void seive()
{ int j,i;
    for (i=2;i<=500;i++)
        if (!prime[i])
            for (j=i;i*j<=500;j++)
                prime[i*j]=1;
 
}*/
void calc()
{int i,j,k,l,m,n;
  for(i=2;i<=500;i++)
  {  m=i;
      for(j=1;j<96;j++)
      {
         // if(!prime[j])
          {k=0;
            while((m%pr[j])==0 )
            {
                k++;
                m=m/pr[j];
            }
              fact[i][j]=fact[i-1][j]+k*i;
          }
      }
 
  }
 
}
long long int fastpower(long int base,long int power,long long int M)
{
        long long int result=1;
        while (power>0)
        {
                if ((power&1)==1)
                        result = (result*(base%M))%M;
                base = (((base)*(base%M)))%M;
                power/=2;
        }
        return result;
}
int main()
{long int t,n,q,b,r,i,temp,x;
long long int a,m;
t=inp();
//scanf("%ld",&t);
//seive();
calc();
while(t--)
{//scanf("%ld%llu%ld",&n,&m,&q);
    n=inp();
    scanf("%llu",&m);
    q=inp();
  while(q--)
  {for(i=1;i<=95;i++)
        total[i]=0;
        r=inp();
          //scanf("%ld",&r);
        b=n-r;
        a=1;
         if((n-r)>r)
            {
               temp=n-r;
               b=r;
               r=temp;
            }
            for(x=1;x<=95;x++)
            {
                total[x]=fact[n][x]-fact[r][x];
            }
            for(x=1;x<=95;x++)
                 total[x]=total[x]-fact[n-r][x];
            for(i=1;i<=95;i++)
         {
             if(total[i])
             {
                 a=(a*fastpower(pr[i],total[i],m))%m;
             }
         }
          printf("%llu\n",a);
  }
 
}
    return 0;
}