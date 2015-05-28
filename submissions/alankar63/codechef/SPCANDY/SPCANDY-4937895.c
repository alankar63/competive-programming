#include<stdio.h>
int main(){//gggggggggggggggggggggg
	long long can,stu;
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%lld %lld",&can,&stu);
		if(stu==0){
			printf("0 %lld\n",can);
			continue;
		}
		printf("%lld %lld\n",can/stu,can%stu);
	}
	return 0;
}