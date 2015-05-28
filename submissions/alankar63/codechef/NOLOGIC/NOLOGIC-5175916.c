#include <stdio.h>
 
int main(void) {
	int i,t,flag;
	char c;
	int refer[127];
	char s[315];
	scanf("%d",&t);
	c=getchar();
	while(t--)
	{
		flag=0;
		gets(s);
		for(i=32;i<=126;i++)refer[i]=0;
		for(i=0;s[i];i++)
		{
			if(s[i]>=97)refer[s[i]-32]=1;
			else refer[s[i]]=1;
		}
		for(i=65;i<=90;i++)
		{
			if(refer[i]==0)
			{
				printf("%c\n",i);
				flag=1;
				break;
			}
		}
		if(flag==0)printf("~\n");
	}
	return 0;
}