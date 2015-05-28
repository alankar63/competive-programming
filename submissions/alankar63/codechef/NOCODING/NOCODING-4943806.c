#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	for(scanf("%d", &t); t--; )
	{
		char str[1001];
		int len, sum=1, i;
		scanf("%s", str);
		len=strlen(str);
		for(i=0; i<len-1; i++)
		{
			if(str[i]<=str[i+1]){
				sum+=(int)(str[i+1]-str[i]);
			}
			else{
				sum+=26-(int)(str[i]-str[i+1]);
			}
		}
		sum+=len;
		if(sum<=(11*len))
		    printf("YES\n");
		else
		    printf("NO\n");
	}
	return 0;
}