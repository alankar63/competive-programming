#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define mod 1000000007
int main()
{char str[100001];
long long int a,len,i,ans;
    scanf("%llu",&a);
    while(a--)
    {ans=1;
        scanf("%s",str);
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            if((i&1)==0)
            {
                if(str[i]=='l')
                    ans=(ans*2)%mod;
                else
                    ans=((ans*2)+2)%mod;
            }
            else
            {
              if(str[i]=='l')
                    ans=((ans*2)-1)%mod;
                else
                    ans=((ans*2)+1)%mod;
            }
            }
            printf("%llu\n",ans);
        }


    return 0;
}