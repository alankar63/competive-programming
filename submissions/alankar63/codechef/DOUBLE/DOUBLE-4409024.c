#include<stdio.h>
int main()
{
long len,trial;
scanf("%ld",&trial);
while(trial--)
{
 scanf("%ld",&len);
 if(len%2==0)
 printf("%d\n",len);
 else
  printf("%d\n",len-1);
}
return 0;
}