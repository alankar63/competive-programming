#include <stdio.h>
long long int p,a,i,n;
int main(void) {
	int t;
	scanf("%d",&t);
	while(t--)  {
		p=0;
		int count[100001]={0};
		scanf("%lld",&n);
		for(i=1;i<=n;i++) {
		scanf("%lld",&a);
		count[a]=1;;
		}
		for(i=1;i<=n;i++) {
			if(count[i]!=0)
			p+=count[i];
		}
		printf("%lld\n",p);
	}
	return 0;
}