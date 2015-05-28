#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,j,l;
    char str[1002];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        l=strlen(str);
        int c=0;
        if(l%2==0)
        {
            for(i=0;i<l/2;i++)
                for(j=l/2;j<l;j++)
            {
                if(str[i]==str[j])
                {c++;
                str[j]=0;
                break;
                }
            }
        }
        else
        for(i=0;i<l/2;i++)
            for(j=l/2+1;j<l;j++)
            {
                if(str[i]==str[j])
                {c++;
                str[j]=0;
                break;
                }
            }
        printf("%s\n",(c==l/2)?"YES":"NO");
 
    }
    return 0;
}