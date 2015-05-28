#include<stdio.h>
#include<string.h>
#define mod 10000009
int main()
{
	long long int test,i,j,f;
	char str[1000006];
	scanf("%lld",&test);
	while(test--)
	{
		f=1;
		scanf("%s",str);
		int l=strlen(str);
		if(l==1 && str[0]=='?')
		{
			f=(f*26)%mod;
		}
		else if(l==1 && str[0]!='?')
		{
			f=(f*1)%mod;
		}
		else
		{
			if(l%2==1&&str[l/2]=='?')
    		{
	    		f=(f*26)%mod;
    		}
    		for(i=0,j=l-1;i<l/2;i++,j--)
		    {
               if(str[i]=='?'&&str[j]=='?')
	    	   {
	    			f=(f*26)%mod;
    		   }
    		   else if((str[i]=='?'&&(str[j]<=122&&str[j]>=97))||(str[j]=='?'&&(str[i]<=122&&str[i]>=97)))
    		   {
        	        f=(f*1)%mod;
      		   }
      		   else if(str[i]==str[j])
      		   {
   		           f=(f*1)%mod;	
   		       }
     		   else
      		   {
   	    	   	    f=(f*0)%mod;;
   		       }
		    }
		}
 		printf("%lld\n",f);
	}
}