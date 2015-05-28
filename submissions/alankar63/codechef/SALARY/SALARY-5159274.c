#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,n,t;
	scanf("%d",&t);
	while(t--){
		int sum,min=-1,i,*a;
		scanf("%d",&n);
		a=(int *)malloc(n*sizeof(int));
		if(n==1){
			scanf("%d",&a[0]);
			printf("0\n");
		}
		else{
			sum=0;
			min=10001;
			for(i=0;i<n;i++){
				scanf("%d",&a[i]);
				sum+=a[i];
				if(min>a[i])
					min=a[i];
			}
			sum=sum-n*min;
			printf("%d\n",sum);
		}
	}
}