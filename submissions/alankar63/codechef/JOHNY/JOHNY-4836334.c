#include<stdio.h>
 int sort(long unsigned int arr[],int n)
{int i,j,x;
 for(i=1;i<n;i++)
  for(j=i;j>0;j--)
   if(arr[j-1]>arr[j])
   { x=arr[j-1];
    arr[j-1]=arr[j];
    arr[j]=x;}
 return 0;
 }
int main()
{ 
 int test,n,i,k;
 scanf("%d",&test);
 while(test--)
{ scanf("%d",&n);
 long unsigned int *arr=(long unsigned int*)malloc(n*sizeof(long unsigned int));
 for(i=0;i<n;i++)
  scanf("%lu",&arr[i]);
  scanf("%d",&k);
 long unsigned int x=arr[k-1];
  sort(arr,n);
 for(i=0;i<n;i++)
  if(x==arr[i])
  { printf("%lu\n",i+1);
    break;
   }}
 return 0; }