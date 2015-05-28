#include<stdio.h>
long long int point[100001],val[100001],ans[100001];
void quicksort(long long int [100001],long long int,long long int);
int main()
{long long int n,k,p,i,a,b,x,y,z,j,flag,f=1,o,u,first ,last ,middle;
scanf("%llu %llu %llu",&n,&k,&p);
for(i=1;i<=n;i++)
{ans[i]=f;
  scanf("%llu",&point[i]);
  val[i]=point[i];
}
quicksort(val,1,n);
/*for(j=n;j>1;j--)
{
    for(i=1;i<j;i++)
    {
          if(val[i]>val[i+1])
         {
        x=val[i+1];
        val[i+1]=val[i];
        val[i]=x;
          }
    }
}
*/
for(i=1;i<n;i++)
{
    if(val[i+1]<=val[i]+k)
    {
        ans[i+1]=f;
    }
    else
        {f++;
         ans[i+1]=f;

        }
}

for(i=0;i<p;i++)
{
     scanf("%llu %llu",&a,&b);
     y=point[a];z=point[b];
      first = 1;
   last = n ;
   middle = (first+last)/2;

   while( first <= last )
   {
      if ( val[middle] < y )
         first = middle + 1;
      else if ( val[middle] == y )
      {
         o=ans[middle];
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
    first = 1;
   last = n ;
   middle = (first+last)/2;

   while( first <= last )
   {
      if ( val[middle] < z)
         first = middle + 1;
      else if ( val[middle] == z )
      {
         u=ans[middle];
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
 /*   for(j=1;j<=n;j++)
     {
         if(val[j]==y)
         {
             o=ans[j];
         }
         if(val[j]==z)
         {
             u=ans[j];
         }
     }
*/     if(o==u)
        printf("Yes\n");
     else
        printf("No\n");
}
    return 0;
}
void quicksort(long long int val[10001],long long int first,long long int last){
   long long  int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(val[i]<=val[pivot]&&i<last)
                 i++;
             while(val[j]>val[pivot])
                 j--;
             if(i<j){
                 temp=val[i];
                  val[i]=val[j];
                  val[j]=temp;
             }
         }

         temp=val[pivot];
         val[pivot]=val[j];
         val[j]=temp;
         quicksort(val,first,j-1);
         quicksort(val,j+1,last);

    }
}