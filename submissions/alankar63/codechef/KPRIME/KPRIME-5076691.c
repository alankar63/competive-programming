#include<stdio.h>
 
int main()
{
    int i,j,temp[5]={0,0,0,0,0};
    int sieve[100001]={0};
    int memo[5][100001];
    sieve[1]=0;
    memo[0][1]=memo[1][1]=memo[2][1]=memo[3][1]=memo[4][1]=0;
    for(i=2;i<=100000;i++)
    {
        if(sieve[i]==0)
        {
            for(j=2*i;j<=100000;j+=i) sieve[j]+=1;
            sieve[i]=1;
        }
        if(sieve[i]<6)
        temp[sieve[i]-1]+=1;
        memo[0][i]=temp[0];
        memo[1][i]=temp[1];
        memo[2][i]=temp[2];
        memo[3][i]=temp[3];
        memo[4][i]=temp[4];
    }
    int t,a,b,k,sol;
    scanf("%d",&t);
    while(t--)
    {
        sol=0;
        scanf("%d %d %d",&a,&b,&k);
        sol=memo[k-1][b]-memo[k-1][a-1];
        printf("%d \n",sol);
    }
    return 0;
}