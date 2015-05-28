#include <stdio.h>
 
int nCr (int a, int b)
{
    int r=1,p=1,q=1,i,j;
    for (i=a;i>0;--i)
        p*=i;
    for (j=b;j>0;--j)
        q*=j;
    for (i=(a-b);i>0;--i)
        r*=i;
    return (p/(q*r));
}
 
int main()
{
    int X,N,i,j,k;
    long long int n=0;
    scanf ("%d %d",&X,&N);
    char s[N][56];
    int x[N][9];
    for (i=0; i<N; ++i)
        scanf ("%s",s[i]);
    for (i=0; i<N; ++i)
    {
        for (j=0; j<9; ++j)
            x[i][j]=0;
        for (j=0; j<54; ++j)
            if (s[i][j]=='0' && (j==0 || j==1 || j==2 || j==3 || j==52 || j==53))
                x[i][0]++;
            else if (s[i][j]=='0' && (j==4 || j==5 || j==6 || j==7 || j==51 || j==50))
                x[i][1]++;
            else if (s[i][j]=='0' && (j==8 || j==9 || j==10 || j==11 || j==49 || j==48))
                x[i][2]++;
            else if (s[i][j]=='0' && (j==12 || j==13 || j==14 || j==15 || j==47 || j==46))
                x[i][3]++;
            else if (s[i][j]=='0' && (j==16 || j==17 || j==18 || j==19 || j==45 || j==44))
                x[i][4]++;
            else if (s[i][j]=='0' && (j==20 || j==21 || j==22 || j==23 || j==43 || j==42))
                x[i][5]++;
            else if (s[i][j]=='0' && (j==24 || j==25 || j==26 || j==27 || j==41 || j==40))
                x[i][6]++;
            else if (s[i][j]=='0' && (j==28 || j==29 || j==30 || j==31 || j==39 || j==38))
                x[i][7]++;
            else if (s[i][j]=='0' && (j==32 || j==33 || j==34 || j==35 || j==36 || j==37))
                x[i][8]++;
    }
    for (i=0;i<N;++i)
        for (j=0;j<9;++j)
            if (x[i][j]>=X)
                n+= nCr(x[i][j],X);
    printf ("%lld\n",n);
    return 0;
}