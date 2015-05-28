#include<stdio.h>
 int main()
{ int test,n,i;
 scanf("%d",&test);
 while(test--) {
 scanf("%d",&n);
 char *arr=(char*)malloc(n*sizeof(char));
  scanf("%s",arr);
 for(i=1;i<n-1;i++)
  if(arr[i]=='1')
    if(arr[i+1]!='1')
      arr[i]=arr[i-1]=arr[i+1]='2';
    else
      arr[i]=arr[i-1]=2;
 if(arr[0]=='1')
    arr[0]=arr[1]='2';
 if(arr[n-1]=='1')
   arr[n-1]=arr[n-2]='2';
 int count=0;
  for(i=0;i<n;i++)
  if(arr[i]=='0')
   count++;
 printf("%d\n",count);}
 return 0; }