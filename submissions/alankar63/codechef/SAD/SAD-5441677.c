#include<stdio.h>
 
int main()
{
	int R, C, i, j, k, flag=0;
	long A[102][102], small[102], chk = 0;
	
	scanf("%d %d", &R, &C);
	
	for(i=0; i<R; i++)
		for(j=0; j<C; j++)
			scanf("%ld", &A[i][j]);
 
	for(i=0; i<R; i++)
	{
		small[i] = A[i][0];
		
		for(j=1; j<C; j++)
			if(A[i][j]<small[i])
				small[i] = A[i][j];
	}
	
	for(i=0; i<R; i++)
	{
		for(j=0; j<C; j++)
		{
			if(A[i][j]==small[i])
			{
				flag = 0;
				
				for(k=0; k<R; k++)
				{
					if(A[i][j]<A[k][j])
						flag = 1;
				}
				
				if(flag==0)
				{
					if(chk==0)
						chk = A[i][j];
						
					else
					{
						if(chk!=A[i][j])
						{
							printf("GUESS\n");
							return 0;
						}
					}
				}
			}
		}
	}
	
	if(chk==0)
		printf("GUESS\n");
	
	else
		printf("%ld\n",chk);
	
	return 0;
}