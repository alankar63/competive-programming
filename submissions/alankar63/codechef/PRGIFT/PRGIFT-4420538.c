#include<stdio.h>
#include<stdlib.h>
#define gc getchar_unlocked
inline int inp(){
	int n=0,sign=1;
	char c;
	c=gc();
	while(c<'0' || c>'9'){
		if(c=='-')	sign=-sign;
		c=gc();
	}
	while(c>='0' && c<='9'){
		n=(n<<3)+(n<<1)+c-'0';
		c=gc();
	}
	n=n*sign;
	return n;
}
int main()
{int a,b[50]={0},c,d,i,count;
a=inp();

    while(a--)
    {c=inp();d=inp();count=0;
        
    
    for(i=0;i<c;i++)
    {
       b[i]=inp();
       if((b[i]&1)==0)count++;
    }
    if(d==0 && count==c)printf("NO\n");
    else{  if(count<d)printf("NO\n");
      else    printf("YES\n");
    }
    }
return 0;
}