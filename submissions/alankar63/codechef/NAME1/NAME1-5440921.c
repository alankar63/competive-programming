#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    int t,n,abc1[26],abc2[26],i,j,flag;
    char *a,*b,*c;
    scanf("%d",&t);
    a=(char*)malloc(sizeof(char)*(40001));
    b=(char*)malloc(sizeof(char)*(40001));
    c=(char*)malloc(sizeof(char)*(40001));
    while(t--)
    {
        flag=1;
        for(i=0;i<26;i++)
            abc1[i]=abc2[i]=0;
 
        scanf("%s",a);
        for(j=0;a[j]!='\0';j++)
            abc1[a[j]-97]++;
 
        scanf("%s",b);
        for(j=0;b[j]!='\0';j++)
            abc1[b[j]-97]++;
 
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",c);
            for(j=0;c[j]!='\0';j++)
                abc2[c[j]-97]++;
        }
 
        for(i=0;i<26;i++)
        {
            if(abc2[i]>abc1[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}