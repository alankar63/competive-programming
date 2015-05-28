#include <stdio.h>
int main() 
{
	int t,n,i;
	char c[2014];
	sscanf(gets(c),"%d",&t);
	while(t--)
	{
		gets(c);
		n=(int)strlen(c);
		for(i=n-1;i>=0;i--)
		{
			if(i>=3&&(c[i-3]=='C'||c[i-3]=='?')&&(c[i-2]=='H'||c[i-2]=='?')&&(c[i-1]=='E'||c[i-1]=='?')&&(c[i]=='F'||c[i]=='?'))
			{
				c[i-3]='C',c[i-2]='H',c[i-1]='E',c[i]='F';
				i-=3;
			}
			else if (c[i]=='?')
			c[i]='A';
		}
		puts(c);
	}
	return 0;
}