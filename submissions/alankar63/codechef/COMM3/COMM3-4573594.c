#include <stdio.h>
#include <math.h>
 
 
int main()
{
  int T;
  long int R;
  long int x1,y1;
  long int x2,y2;
  long int x3,y3;
  long int d1,d2,d3;
 
  scanf("%d",&T);
  while(T > 0) {
    scanf("%d",&R);
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    scanf("%d %d",&x3,&y3);
    R = pow(R,2);
    d1 = pow((x1-x2),2) + pow((y1-y2),2);
    d2 = pow((x1-x3),2) + pow((y1-y3),2);
    d3 = pow((x2-x3),2) + pow((y2-y3),2);
    if((d1 <= R && d2 <= R) || (d2 <= R && d3 <= R) || (d1 <= R && d3 <= R)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
 
    T--;
  }  /* while */
  return 0;
}