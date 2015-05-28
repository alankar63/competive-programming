#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<algorithm>
#include<utility>
#include<vector>
#define gc getchar_unlocked
inline int inp()
{
    int h=0,sign=1,count=0;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {if(c=='-')	sign=-sign;
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';


        c=gc();
    } h=h*sign;

     return h;
}

using namespace std;

#define ll long long int
int main()
{
    vector<pair<int,int> > point;//check for int too
    
    int xcor,ycor,poiX,poiY,rotX,rotY,X,Y,_X,_Y,_poiX,_poiY;
    int n,i,j,flag1 = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   xcor=inp();
        ycor=inp();
       // scanf("%d %d",&xcor,&ycor);
        //see fastread too
        point.push_back( make_pair(xcor,ycor));
    }
    /*
     int search(int a,int b,int first ,int last)
 {
   int  middle = (first+last)/2;
     while( first <= last )
   {
      if ( x[middle][1] < a )
         first = middle + 1;
      else if ( x[middle][1] == a )
      {int k,t;
      k=a;t=middle;
          while(x[t][1]==a&&t<=n)
          {
             if(x[t][2]==b)
             {
                 return 1;
             }t++;
          }
          t=middle;
            while(x[t][1]==a&&t>=1)
            {
               if(x[t][2]==b)
             {
                 return 1;
             }t--;
            }
        // printf("%d found at location %d.\n", search, middle+1);
         return 0;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if ( first > last )
      return 0;
 }*/
    sort(point.begin(),point.end());
    if(n==0)
        printf("4");
    else if(n==1)
        printf("3");
    else if(n==2)
        printf("2");
    else{
        int ans = 2;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {

                _poiX = poiX = (point[i]).first;
                _poiY = poiY = (point[i]).second;
                _X =X = (point[j]).first;
                _Y =Y = (point[j]).second;

                rotX = -(Y-poiY) + poiX;
                rotY = (X-poiX) + poiY;
                if(binary_search(point.begin(),point.end(),make_pair(rotX,rotY)))
                {
                    if(ans>1)
                        ans = 1;
                        xcor = X;
                        ycor =Y;
                        X = poiX;
                        Y = poiY;
                        poiX = xcor;
                        poiY = ycor;

                    rotX = (Y-poiY) + poiX;
                    rotY = -(X-poiX) + poiY;

                    if(binary_search(point.begin(),point.end(),make_pair(rotX,rotY)))
                    {
                        ans =0;
                        flag1 =1;
                    }
                }
                X = _X;
                Y= _Y;
                poiX = _poiX;
                poiY = _poiY;

                    rotX = (Y-poiY) + poiX;
                    rotY = -(X-poiX) + poiY;
                if(binary_search(point.begin(),point.end(),make_pair(rotX,rotY)))
                {
                    if(ans>1)
                        ans = 1;
                        xcor = X;
                        ycor =Y;
                        X = poiX;
                        Y = poiY;
                        poiX = xcor;
                        poiY = ycor;

                    rotX = -(Y-poiY) + poiX;
                    rotY = (X-poiX) + poiY;

                    if(binary_search(point.begin(),point.end(),make_pair(rotX,rotY)))
                    {
                        ans =0;
                        flag1 =1;
                    }
                }

                if(flag1==1)
                    break;
            }
            if(flag1 == 1)
                break;
        }
        //check these with goto too
        printf("%d\n",ans);
    }

    return 0;
}