#include<stdio.h>
int countHoles(char*);
int arr[26]={0};
int main()
{
        int t,i;
        char str[100];
        arr[0]=1;
        arr[1]=2;
        arr[3]=1;
        arr[14]=1;
        arr[15]=1;
        arr[16]=1;
        arr[17]=1;
 
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
               scanf("%s",str);
               printf("%d\n",countHoles(str));
        }
        return 0;
}
 
int countHoles(char*str)
{
        int counter=0,i;
        for(i=0;str[i];i++)
               counter+=arr[str[i]-65];
        return counter;
}