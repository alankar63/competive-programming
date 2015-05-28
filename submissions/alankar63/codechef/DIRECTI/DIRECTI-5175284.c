#include<stdio.h>
#include<string.h>
int main()
{
	int test;
	scanf("%d",&test);
	char arr[50][51];
	char s[50][10];
	while(test--)
	{
		int i,n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			gets(arr[i]);
		}
          i=n-1;
          printf("Begin");
          puts(arr[i]);
          for(i=n-2;i>=0;i--)
          {
          	if(strcmp(s[i+1],"Left")==0)
          	{
          		printf("Right");
          		puts(arr[i]);
          	}
          	else if(strcmp(s[i+1],"Right")==0)
          	{
          		printf("Left");
          		puts(arr[i]);
          	}
          }
          printf("\n");
	}
	return 0;
}