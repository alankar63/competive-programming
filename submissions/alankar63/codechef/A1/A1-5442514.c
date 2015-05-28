#include<stdio.h>
 
int count(int st,int end,int sum,int m,int a[])
{
 //int i;	
 //for(i=st;i<=end;i++)
 //	  printf("%d ",a[i]);
 //printf("\n");	  
 //printf("st=%d end=%d sum=%d m=%d\n",st,end,sum,m);	
 if((sum + a[st]) == m)
   return 1;
 else if((sum > m) || (st == end))  
   return 0;
 else
   return (count(st+1,end,sum,m,a) || count(st+1,end,sum+a[st],m,a));
}   
   
 
int main()
{
 int m,n,t,i,a[21],ans;
 scanf("%d",&t);
 while(t--){
    scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	ans = count(0,n-1,0,m,a); 
    if(ans)
	printf("Yes\n");
	else
	printf("No\n");
	}
 return 0;
}