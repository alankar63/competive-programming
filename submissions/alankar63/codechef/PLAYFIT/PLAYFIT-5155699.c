#include<stdio.h>
#include<string.h>
inline int input( )
{
	int n=0;
	int ch=getchar_unlocked();
	while(ch<'0')
		ch=getchar_unlocked();
	while( ch >47 )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return n;
}
 
int main(){
	int t,n,temp,temp1,diff;
	t=input();
	while(t--){
		int max=0;
		n=input();
		temp1=input();
		while(--n){
			temp=input();
			if(temp<temp1)
				temp1=temp;
			else{
				diff=temp-temp1;
				if(diff>max)
					max=diff;
			}
		}
		max>0 ? printf("%d\n",max) : puts("UNFIT");
	}	
	return 0;
}