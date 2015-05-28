#include<stdio.h>
 
int  inline scan()
{
    int N = 0;
    char C;
    C=getchar_unlocked();
    while (C < '0' || C>'9') C=getchar_unlocked();
    while (C >= '0' && C <= '9')
    {
        N = (N<<3) + (N<<1) + C - '0';
        C=getchar_unlocked();
    }
 
    return N;
}
 
int main()
{
int t,n,i;
long long int c,cte=0,total=0;
 
t=scan();
	while(t--)
	{
	
		total=0;
 
		n=scan();
		c=scan();
		for(i=0;i<n;i++)
		{
			cte=scan();
			
			total=total+cte;
		}
		
		if(total<=c)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;	
}