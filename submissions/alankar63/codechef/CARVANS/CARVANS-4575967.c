#include<stdio.h>

#include<stdlib.h>
inline int getn(){
	int n=0, c=getchar_unlocked();
	while(c < '0' || c > '9') c = getchar_unlocked();
	while(c >= '0' && c <= '9')
		n = (n<<3) + (n<<1) + c - '0', c = getchar_unlocked();
	return n;
}
int main()
{
    int n,i,c,t,min,speed;
   
    t=getn();
    while(t--)
    {
              c=1;
   
    n=getn();
    min=getn();
    for(i=1;i<n;i++)
    {
            
                  speed=getn();
                    
                                      if(min>=speed)
                                      {
                                      c++;
                                      min=speed;
                                      }
                                      }
                                      printf("%d\n",c);
                                      }//getch();
                                    
                                      return 0;
                                      }