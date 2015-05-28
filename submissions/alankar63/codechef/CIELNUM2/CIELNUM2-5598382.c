#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
int main(){
	int n,count=0,len,i,b,n8,n5,n3;
	char s[1000000];
	scanf("%d",&n);
	gets(s);
	while(n--){
		gets(s);
		n8=n5=n3=0;b=1;
		
		len=strlen(s);
		for(i=len-1; b&&i>=0 && s[i]!=' ';i--){
			if(s[i]=='8')
				n8++;
			else if(s[i]=='5')
				n5++;	
			else if(s[i]=='3')
				n3++;
			else if(s[i]>='0' && s[i]<='9')
				b=0;	
		}
		if(n8>=n5 && n5>=n3 && b){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}