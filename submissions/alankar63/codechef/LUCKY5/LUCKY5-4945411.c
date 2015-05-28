#include <stdio.h>
#include <string.h>
 
int main() 
{
	int T;
	int i;
	scanf("%d\n",&T);
	while(T--)
	{
		char A[100005];
		int cnt = 0;
		gets(A);
		for (i = 0; A[i]>=48 ; i++)
		{
			if(A[i]== 52 || A[i] == 55)
			cnt++;
		}
		printf("%d\n", i - cnt);
	}
	return 0;
}