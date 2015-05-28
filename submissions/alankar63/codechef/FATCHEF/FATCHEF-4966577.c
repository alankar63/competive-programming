#include<stdio.h>
#include<stdlib.h>
#define mod 1000000009
int col[100001];
char c[100001];

void quicksort(int first,int last){
    int pivot,j,d1,i,temp;
    char h1;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(col[i]<=col[pivot]&&i<last)
                 i++;
             while(col[j]>col[pivot])
                 j--;
             if(i<j){
               //  temp=x[i];
                 // x[i]=x[j];
                 // x[j]=temp;
                   d1=col[j];
              h1=c[j];
              col[j]=col[i];
              c[j]=c[i];
              col[i]=d1;
              c[i]=h1;

             }
         }

         temp=col[pivot];
         h1=c[pivot];
         col[pivot]=col[j];
         c[pivot]=c[j];
         col[j]=temp;
         c[j]=h1;
         quicksort(first,j-1);
         quicksort(j+1,last);

    }
}
int main()
{ int t,i,j,n,m,max,d1;
char h1;
long long int ans;
scanf("%d",&t);
while(t--)
{ans=1;
scanf("%d%d",&n,&m);
for(i=1;i<=m;i++)
{
    scanf("%c%c%d",&d1,&c[i],&col[i]);
}
 /*for (i = 1; i < m; i++)
       for (j = 1; j < m-i+1; j++) //Last i elements are already in place
         {if (col[j] > col[j+1])
            {

              d1=col[j+1];
              h1=c[j+1];
              col[j+1]=col[j];
              c[j+1]=c[j];
              col[j]=d1;
              c[j]=h1;
            }
         }
*/
 quicksort(1,m);
for(i=1;i<m;i++)
{
    if(c[i]!=c[i+1])
    {
        ans=(ans*(col[i+1]-col[i])%mod)%mod;
    }
}
  printf("%llu\n",ans);
}

    return 0;
}