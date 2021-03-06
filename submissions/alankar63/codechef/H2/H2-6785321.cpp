#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
 
int Point[100000][2]; // p[x][0] for the wieght and p[1] for the strength
double dist[100000];
int n,i;
 
int IsOk(double m)
{
 
  
  for(i=0;i<n;i++)
   dist[i]=  (Point[i][1] - m*Point[i][0])/(sqrt(1+m*m));  // (y-mx)/sqrt(1+m^2)   > 0 ok < 0 false
  
  sort(dist,dist+n);
  
  for(i=0;i<n;i++)
   if(dist[i]+dist[n-i-1] <0 )
    return 0;
  
  return 1;    
}
 
int main()
{
    double low,mid,high;
    scanf("%d",&n);
     
    for(i=0;i<n;i++)
     {
       scanf("%d%d",&Point[i][0],&Point[i][1]);
       Point[i][0]+=10;
     }
     
     low= 0.4; // (50+50)/(100+100+20); //0.45454
     high= 1.7; //(100+100)/(50+50+20) //1.667
     
      while(high -low > 1e-8)
       {
         mid=(low+high)/2;
         if(IsOk(mid)) low=mid;
         else
           high=mid;
       }
       printf("%f\n",(low+high)/2);
      
       system("PAUSE");
       return 0;
}