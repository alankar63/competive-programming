#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>



 long long int a[24];
 using namespace std;
 int recur(int ,int ,int mark[],int ,long long int  ,int,long long int );



int main()
{
	int test,mark[25],n,k,i,p,ans,valid,bc,d;
	long long int t,sum;

	scanf("%d",&test);
	while(test--){
valid=0;
ans=0;
		scanf("%d%d",&n,&k);

		for(i=0;i<n;i++)
		{	scanf("%llu",&t);
			if(t==0)
				continue;

		a[valid]=t;
		valid++;
		}
		
		if(valid==0)
			{   if(n<k)
			       printf("no\n");
			       else
			    printf("yes\n");
			continue;}
		sum=0;
		for(i=0;i<=23;i++)
            mark[i]=0;
		
         sort(a,a+valid);
		for(i=0;i<valid;i++)
		{
		sum+=a[i];
		}
		{//if(t==0)
			//i=1;
        if((sum%k) || valid<k)
			ans=0;
		else
			ans=recur(valid,k,mark,0,0,valid,sum/k);}//sum/k is average
		if(ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

int recur(int n,int k,int mark[],int j,long long int sum,int pn,long long int t)
{
	int i,l;
	if(k==0)
	{
			if(pn==0)
				return 1;
			else
				return 0;
	}
	if(pn==0)
		return 0;


	for( i=j;i<n;i++){

		if(mark[i]==0){

		if(sum+a[i]<t )
		{
			mark[i]=1;
			if(recur(n,k,mark,i+1,sum+a[i],pn-1,t)==1)
				return 1;
			mark[i]=0;
		}
		else if(sum+a[i]==t)
		{
			mark[i]=1;
			if(recur(n,k-1,mark,0,0,pn-1,t)==1)
				return 1;
			mark[i]=0;
		}
		}
		if(sum+a[i]>t)
			return 0;
	}
	return 0;
}