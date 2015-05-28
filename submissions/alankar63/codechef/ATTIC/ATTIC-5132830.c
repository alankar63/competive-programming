#include <stdio.h>
 
int main(void) {
	int t,n,day,len,j;
	scanf("%d\n",&t);
	while(t--)
	{
		char c[1000000];len=0;day=0;j=0;
		gets(c);int i=0;
		while(c[i]!='\0')
		{if(c[i]=='.')
		  {
		  	j=1;
		  	while((c[j+i]=='.'))
		  	{j++;}
		  	i=i+j;
		  	if(j>len)
		  	{day++;len=j;}
		  	
		  }
		
		else i++;	
		}printf("%d\n",day);
		
	}
	return 0;
}