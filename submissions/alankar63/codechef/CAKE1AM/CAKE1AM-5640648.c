#include<stdio.h>
int mul(int x)
{
	       if(x<0) return -x;
	else return x;
}
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int min(int a,int b)
{
	              if(a<b) return a;
	else return b;
}
int main()
{
	int test;
	     int x1,x2,y1,y2;
	int a1,a2,b1,b2;
	           scanf("%d",&test);
	while(test--)
	         {
		int ans1,ans2,p,q,t,r,ab=0,ans;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		scanf("%d %d %d %d",&a1,&b1,&a2,&b2);
		
		ans1=mul((x2-x1)*(y2-y1));
		ans2=mul((a2-a1)*(b2-b1));
		if(a2>x1 && b2>y1 && a1<x2 && b1<y2 )
		           {
				p=max(x1,a1);
				q=max(y1,b1);
				t=min(x2,a2);
				r=min(y2,b2);
				ab=mul((t-p)*(r-q));
		                  }
			
		ans=ans1+ans2-ab;
		printf("%d\n",ans);
	                            }
	return 0;
}