#include<stdio.h>
int main()
{
	char s[400],stack[400];
	short int t,len,i,j;
	scanf("%hd",&t);
	while(t--)
	{
		j=0;
		scanf("%s",s);
		for(i=0;s[i]!='\0';i++)
		{
			if(s[i]=='+' || s[i]=='*' || s[i]=='/' || s[i]=='^' || s[i]=='-')
			{
				stack[j]=s[i];
				j++;
			}
			else if(s[i]!=')' && s[i]!='(')
			{
				printf("%c",s[i]);
			}
			else if(s[i]==')')
			{
				j--;
				printf("%c",stack[j]);
			}
		}
		printf("\n");
	}
	return 0;
}