#include<stdio.h>
#include<string.h>
int main()
{
    int t,i;
    char a[27],test[101],ch;
    scanf("%d",&t);
    scanf("%s",&a);
    while(t--)
    {
        i=0;
        scanf("%s",&test);
        ch=test[i];
        while(ch!='\0')
        {
            if(ch=='_') printf(" ");
            else if(ch>=97&&ch<=122) printf("%c",a[ch%97]);
            else if(ch>=65&&ch<=90) printf("%c",a[(ch%65)]-32);
            else printf("%c",ch);
            ch=test[++i];
        }
        printf("\n");
    }
    return 0;
}