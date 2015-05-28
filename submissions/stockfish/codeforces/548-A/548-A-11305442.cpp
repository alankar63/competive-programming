#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
int main()
{
    using namespace std;
    char str[1010];
    int len,i,j,p,q,k,sublen;
    cin>>str;
    //scanf("%s",str);
    cin>>k;
    //scanf("%d",&k);
    int flag=0;
    len = strlen(str);
    sublen = len/k;
    if(sublen==0 || len%k!=0)
    {

        flag = 1;
    }
    for(i=0;i<k;i++)
    {
        if(flag==1)
            break;
        j= i*sublen;
        p=j+sublen-1;
        while(j<p)
        {
            if(flag==1)
                break;
            if(str[j]==str[p])
            {
                j++;p--;
            }
            else if(str[j]!=str[p])
            {
                flag = 1;

            }
        }
    }
    if(flag==1)
    {
        printf("NO\n");
    }
    else{
    printf("YES\n");
    }
    return 0;

}