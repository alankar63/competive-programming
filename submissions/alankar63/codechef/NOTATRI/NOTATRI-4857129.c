#include<stdio.h>
#include<stdlib.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int n,i,count;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
		break;
 
		long size[n];
		for(i=0;i<n;i++)
		scanf("%ld",&size[i]);
 
		qsort(size, n, sizeof(int), cmpfunc);
 
		int first,end;
		count =0;
		for(i=n-1;i>=2;i--)
		{
			end=i-1;
			first=0;
			while(first<end)
			{
				if(size[first]+size[end]<size[i])
				{
					count = count + end - first;
					first++;
				}
				else
				end--;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}