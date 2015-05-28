#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		char s[100005];
		scanf("%s",s);
		char a[4]={'1','0','1'};
		char b[4]={'0','1','0'};
		if(strstr(s,a))
			printf("Good\n");
			else if(strstr(s,b))
			printf("Good\n");
		else printf("Bad\n");
	}
	return 0;
}