#include <stdio.h>
 
int main()
 {
  int N;
  int i=1;
  int a[1000+1]={0};
  int in[1001];
  int out[4000];
  int j=0;
  scanf("%d",&N);
  while(i<=N)
   {
    scanf("%d",&in[i]);
    i++;
   }
   int k;
   int count=0;
  for(i=1;i<=N;i++)
   {
     if(!a[i])
      {
        count++;
        k=i;
        out[j++]=k;
        a[i]=1;
         do
         {
          out[j++]=in[k];
          a[in[k]]=1;
          k=in[k]; 
         }while(k!=i); 
        out[j++]=0;
      }
   }
   printf("\n%d\n",count);
   for(i=0;count;i++)
     {
      if(out[i])
       printf("%d ",out[i]);
      else
       {
        printf("\n");
        count--;
       }
     }
 return 0;
 }