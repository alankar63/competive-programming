#include <stdio.h>
#include<string.h>
int main(void) {
	// your code goes here
    int t,i,j,count,len1,len2;
	char a[10001];
	char b[10001];
	int mem[150]={0};
	int temp;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<150;i++)
		{
			mem[i]=0;
		}
		scanf(" %s",a);
		scanf(" %s",b);
		count=0;
		len1 = strlen(a);
		len2 = strlen(b);
		for(i=0;i<len1;i++)
		{
			temp = (int)a[i];
			mem[temp]++;
		}
		for(i=0;i<len2;i++)
		{
			temp = (int)b[i];
			if(mem[temp]>0)
			{
				mem[temp]--;
				count++;
			}
		}
 
		printf("%d\n",count);
	}
	return 0;
}