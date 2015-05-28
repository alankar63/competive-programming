#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c,d=0,k=0,lar=0,f=0,e[10000],i;
        scanf("%d%d%d",&a,&b,&c);
        while(d<10000)
        {
            e[d]=(a*100)+b;
            if(a==0 && b<c)
                break;
            else if(b>=c)
                b=b-c;
            else if(a>0 && b<c)
            {
                a=a-1;
                b=100+b-c;
            }
            k=a;
            a=b;
            b=k;
            d++;
        }
        for(i=0;i<d;i++)
        {
            if(e[i]>lar)
            {
                lar=e[i];
                f=i;
            }
        }
        printf("%d\n",f);
    }
    return 0;
}