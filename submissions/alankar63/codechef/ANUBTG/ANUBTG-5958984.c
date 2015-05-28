#include<stdio.h>	
    #include<stdlib.h>
   
    
    inline int scan()
{
int t=0;
char c;
c=getchar_unlocked();
while(c<'0' || c>'9')
c=getchar_unlocked();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getchar_unlocked();
}
return(t);
}
inline void print(int a)
{
char num[20];
int i=0;
do
{
num[i++]=a%10+48;
a=a/10;
}while(a!=0);
i=i-1;
while(i>=0)
putchar_unlocked(num[i--]);
putchar_unlocked('\n');
}
    
    int main()
    {
    int t;
    t=scan();
  
    while(t--)
    {
    int n,i,sum=0,x,big,count=0;
    
   n=scan();
    int a[1001]={};
    x=scan();
    
    a[x]++;
    big=x;
   
    for(i=1;i<n;i++)
    {
    x=scan();
    a[x]++;
    
    if(x>big)
    big=x;
    }
    
    for(i=big;i>=0;i--)
    {
    	
    	
    while(a[i]>0)
    {
    count++;
    a[i]--;
    
    if(count<=2)
     sum+=i;
    
    if(count==4)
    count=0;
    
    }
    
    }
    
    print(sum);
    }
    return 0;
    }