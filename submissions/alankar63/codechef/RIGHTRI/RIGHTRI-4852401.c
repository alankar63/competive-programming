#include<stdio.h>
float dis(int x1,int x2,int y1,int y2)
{
    return((x1-x2)*(y1-y2)+(y1-y2)*(y1-y2));
 
}
int main()
{
    int t,n,x1,x2,x3,y1,y2,y3,s=0;
    float a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d",&x1, &y1, &x2 ,&y2 ,&x3 ,&y3 );
        a=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        b=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
        c=(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2);
        if(a==b+c||b==a+c||c==a+b)
            s++;
 
    }printf("%d",s);
    return 0;
}