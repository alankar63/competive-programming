#include<stdio.h>
    int main()
    {
    	int a,b,x,r;
    	int arr[]={1,2,3,4,5,6,7,8,9,1};
    	scanf("%d %d",&a,&b);
    	
	x=a-b;
    	r=x%10;
    	x=(x/10)*10+arr[r];
    	printf("%d\n",x);
    	
    	return 0;
    }