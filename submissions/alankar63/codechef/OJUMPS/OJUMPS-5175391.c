#include<stdio.h>
 
int main(void)
{
	unsigned long long a;
	
	scanf("%llu",&a);
	
	if(a%3==0||a==0)
    printf("yes");
	
	else if(a%6==1)
	printf("yes");
	
	else
	printf("no");
	
	return 0;
}