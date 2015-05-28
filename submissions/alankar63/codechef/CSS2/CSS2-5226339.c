#include <stdio.h>
#define gc getchar_unlocked
#define M 1001
long int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}
int main(void) {
	long int n,m,id[M][M],pr[M][M],i,j,temp,temp1,temp2,temp3,temp4,temp5;
	n=read_int();m=read_int();
	for(i=0;i<n;i++)
	{//printf("%ld",i);
		temp = read_int();
		temp1 = read_int();
		temp2 = read_int();
		temp3 = read_int();//printf("%ld",temp3);
		if(temp3>pr[temp][temp1])
		{
			pr[temp][temp1]=temp3;
			//tempval =id[temp][temp1];
			id[temp][temp1]=temp2;
		}
		else if(temp3==pr[temp][temp1])
		{
			pr[temp][temp1]=temp3;
			id[temp][temp1]=temp2;
		}
	}
	for(i=0;i<m;i++)
	{
		temp4 = read_int();temp5 = read_int();
		printf("%ld\n",id[temp4][temp5]);
	}
	return 0;
}