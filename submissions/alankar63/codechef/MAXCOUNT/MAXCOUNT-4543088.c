/*Count of Maximum*/
 
#include<stdio.h>
#include<string.h>
 
int count[10001];
 
int main()
{
	int i,maxcount,N,num,T;
	scanf("%d",&T);
	while(T--)
	{
		memset(count,0,sizeof(int)*10001);
		scanf("%d",&N);
		maxcount=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",&num);
			count[num]++;
			if(maxcount<count[num])
				maxcount=count[num];
		}
		for(i=1;i<=10000;i++)
			if(count[i]==maxcount)
				break;
		printf("%d %d\n",i,maxcount);
	}
	return 0;
}