# include <stdio.h>
 
 
#define getcx getchar_unlocked
 
inline void inp(int *n )//fast input function 
{
   *n=0;
   int ch=getcx();
   while(! (ch >= '0' && ch <= '9'))
   ch=getcx();
   while(  ch >= '0' && ch <= '9' )
          *n = (*n<<3)+(*n<<1) + ch-'0', ch=getcx();
} 
 
 
 
 
int main()
{
	int n,i,flag;
	while(1)
	{
	flag=1;
	inp(&n);
	if(n==0)break;
	int a[n+1];
	for(i=1;i<=n;i++)
	{
	inp(&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(a[a[i]]!=i){ flag=0; break; }
	}
	if(flag==0)
	printf("not ambiguous\n");
	else
	printf("ambiguous\n");
	}
	return 0;
}