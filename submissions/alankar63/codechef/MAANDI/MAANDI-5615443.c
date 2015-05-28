#include<stdio.h>
#include<math.h>
#define ll long long int
int main()
{
    int t,c;
    int n,i,p;
    scanf("%d",&t);
    while(t--)
    {  c=0;
        scanf("%d",&n);
        for(i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                p=i;
                while(p)
                {
                    if(p%10==4||p%10==7)
                    {c++;
                    break;}
                    p=p/10;
                }
                 p=(n/i)==i?0:(n/i);
              while(p)
              {
                   if(p%10==4||p%10==7)
                    {
                      c++;
                      break;
                    }
                    p=p/10;
               }
 
            }
 
        }
        printf("%d\n",c);
    }
    return 0;
}