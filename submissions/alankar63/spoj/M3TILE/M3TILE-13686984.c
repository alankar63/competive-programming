#include<stdio.h>
//using namespace std;
int main()
{   int x,y;
    long long ar[31]={0};
    ar[0]=1;
    ar[1]=0;
    ar[2]=3;
    ar[4]=11;
    for( x=6;x<=30;x+=2)
    {
        ar[x]=ar[x]+3*ar[x-2];
        for( y=x-4;y>=0;y-=2)
        {
            ar[x]=ar[x]+2*ar[y];
        }
    }
    int n;
    scanf("%d",&n);
    
    while(n!=-1)
    {
        printf("%lld\n",ar[n]);
        //cout<<ar[n]<<endl;
        scanf("%d",&n);
    }
   return 0;
}
