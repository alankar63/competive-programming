#include <stdio.h>
#include<string.h>
int main(void) {
	int t,r,c,i,j,flag;
	char ch;
    char s[100][100];
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d%d",&r,&c);
		ch=getchar();
		for(i=0;i<r;i++){gets(s[i]);}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if((s[i][j]=='s'||s[i][j]=='S')&&((j+4)<c))
				{
				    if((s[i][j+1]=='P'||s[i][j+1]=='p')&&(s[i][j+2]=='O'||s[i][j+2]=='o')&&(s[i][j+3]=='O'||s[i][j+3]=='o')&&(s[i][j+4]=='N'||s[i][j+4]=='n'))
				    {
				    	flag=1;
				    	break;
				    }
				}
				if((s[i][j]=='s'||s[i][j]=='S')&&((i+4)<r))
				{
				    if((s[i+1][j]=='P'||s[i+1][j]=='p')&&(s[i+2][j]=='O'||s[i+2][j]=='o')&&(s[i+3][j]=='O'||s[i+3][j]=='o')&&(s[i+4][j]=='N'||s[i+4][j]=='n'))
				    {
				    	flag=1;
				    	break;
				    }
				}
			}
			if(flag==1)break;
		}
		if(flag==1)printf("There is a spoon!\n");
		else if(flag==0)printf("There is indeed no spoon!\n");
	}
	return 0;
}