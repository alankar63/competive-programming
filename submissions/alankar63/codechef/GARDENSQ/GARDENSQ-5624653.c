//les_ime), 2011-08-09 01:57:58.
#include<stdio.h>
 
char GAR[100][100];
 
int main()
{
   int T,N,M,i,j,k,l,d,sum;
   char a;
   scanf("%d",&T);
   for(i=0;i<T;i++)
   {
      scanf("%d%d",&N,&M);
      for(j=0;j<N;j++)
      {
         scanf("%s",GAR[j]);                
      }
      d=((M<N)?M:N); //d recebe o mínimo(M,N)
      sum=0;
      for(j=2;j<=(d);j++)
      {
         for(k=0;k<=(M-j);k++)
         {
            for(l=0;l<=(N-j);l++)
            {
               a=GAR[l][k];
               if((a==GAR[l][k+j-1])&&a==(GAR[l+j-1][k])&&a==(GAR[l+j-1][k+j-1]))
               {
                  sum++;
               }
            }
         }
      }
      printf("%d\n",sum);
   }
   //GARDENSQ
   //system("pause");
   return 0;
}