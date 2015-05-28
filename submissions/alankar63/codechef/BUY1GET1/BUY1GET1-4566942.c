#include<stdio.h>
int main()
{
    int t,i,cost;
    char str[201];
    int hash[60]={0};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        
        for(i=0;i<60;i++)
        hash[i]=0;
        i=0;
 
        while(str[i]!='\0')
        {
        
            hash[str[i]-65]++;
            i++;
        }
        
       cost=0;
        for(i=0;i<60;i++)
        {
            if(hash[i]!=0)
            {
                if(hash[i]%2==0)
                cost+=hash[i]/2;
                else
                cost=cost+hash[i]/2+1;
            }
        }
        printf("%d\n",cost);
        
    }
    return 0;
}