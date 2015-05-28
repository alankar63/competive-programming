//simple version .try by randomize too
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define tim 100000
struct points{
long long int x;
long long int y;
long long int index;
}point[500];
int compare(struct points *elem1, struct points *elem2)
{ int l=elem1->y;
  int r=elem2->y;
  int a=elem1->x;
  int b=elem2->x;
   if ( ((a-2000)*(a-2000)-(l-2000)*(l-2000)) <((b-2000)*(b-2000)-(r-2000)*(r-2000)) )
      return 1;

   else
      return -1;



}
int main()
{
  long long   int t,n,i,b[500],k,j,l,min,minindex,ans[500],maxd;
    // int a[401][2],ans[401][2];
    scanf("%llu",&t);
   // k=tim/t;
    while(t--)
    {scanf("%llu",&n);
    min=3000;
        for(i=0;i<n;i++)
       {

        scanf("%llu%llu",&point[i].x,&point[i].y);
        point[i].index=i+1;
        b[i]=0;
        if(point[i].x<min)
        {
            min=point[i].x;
            minindex=point[i].index;
        }
       }
       ans[0]=minindex;
       b[minindex-1]=1;
       for(i=0;i<(n-1);i++)
       {maxd=100000000;
       //printf("%d",maxd);
           for(j=0;j<n;j++)
           {
               if((b[j]==0)&&((ans[i]-1)!=j))
               {
                   if(maxd>(((point[j].x-point[ans[i]-1].x)*(point[j].x-point[ans[i]-1].x))+((point[j].y-point[ans[i]-1].y)*(point[j].y-point[ans[i]-1].y))))//x2-x1
                   {
                       minindex=j;
                       maxd=(((point[j].x-point[ans[i]-1].x)*(point[j].x-point[ans[i]-1].x))+((point[j].y-point[ans[i]-1].y)*(point[j].y-point[ans[i]-1].y)));
                   }
               }

           }
            ans[i+1]=minindex+1;
               b[minindex]=1;
       }
      // qsort(point,n,sizeof(struct points),(int)compare );

       for(i=0;i<n-1;i++)
       {
           printf("%llu %llu\n",ans[i],ans[i+1]);
       }


    }
    return 0;
}