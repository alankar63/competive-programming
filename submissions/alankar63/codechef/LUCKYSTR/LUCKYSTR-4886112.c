#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i, K, N, val, j;
	char **str, **pattern;
	scanf("%d%d",&K,&N);
	pattern = (char**)malloc(K*sizeof(char*));
	for(i=0;i<K;i++) 
	{ 
		pattern[i] = (char*)malloc(60*sizeof(char));
		scanf("%s",pattern[i]);
	}	
	str = (char**)malloc(N*sizeof(char*));
	for(i=0;i<N;i++) 
	{
		val = 0;
		str[i] = (char*)malloc(60*sizeof(char));
		scanf("%s",str[i]);
		for(j=0;j<K;j++) if(strstr(str[i], pattern[j])) val = 1;
		
		j=0;
		while(str[i][j] != '\0') j++;
		if(j>= 47) val = 1;
		
		if(val) printf("Good\n");
		else printf("Bad\n");
		
	}
	
	return 0;
	
}