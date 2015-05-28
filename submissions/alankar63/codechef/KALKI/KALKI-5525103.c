//simple version .try by randomize too
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define tim 100000
struct points{
int x;
int y;
int index;
}point[401];
int compare(struct points *elem1, struct points *elem2)
{ int l=elem1->y;
  int r=elem2->y;
  int a=elem1->x;
  int b=elem2->x;
   if ( ((a+2000)*(a+2000)-(l+2000)*(l+2000)) <((b+2000)*(b+2000)-(r+2000)*(r+2000)) )
      return -1;

   else
      return 1;



}
int main()
{
    int t,n,i,b[401],k,j,l;
    // int a[401][2],ans[401][2];
    scanf("%d",&t);
   // k=tim/t;
    while(t--)
    {scanf("%d",&n);
        for(i=0;i<n;i++)
       {

        scanf("%d%d",&point[i].x,&point[i].y);
        point[i].index=i+1;
       }
       qsort(point,n,sizeof(struct points),(int)compare );
       for(i=0;i<n-1;i++)
       {
           printf("%d %d\n",point[i].index,point[i+1].index);
       }


    }
    return 0;
}