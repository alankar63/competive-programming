#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int A[2][100002];
int min(int a,int b)
{
    if (a>b)
        return b;
    return a;
}
 
int max(int a,int b)
{
    if (a>b)
        return a;
    return b;
}
 
int main()
{
    int t;
    scanf ("%d",&t);
    int l;
    for(l=0;l<t;++l)
    {
        char S[100005],W[100005];
        scanf ("%s",S);
        scanf ("%s",W);
        int l1=strlen(S)+1;
        int l2=strlen(W)+1;
        int a,b,k;
        int ans;
        scanf ("%d %d %d",&a,&b,&k);
        if (a==0)
        {
            printf("0\n");
            continue;
        }
        if (b==0)
        {
            ans=abs(l1-l2)*a;
            if (ans>k)
                printf("-1\n");
            else
                printf("%d\n",ans);
            continue;
        }
        int i;
        for (i=0;i<100002;++i)
            A[0][i]=A[1][i]=999999999;
        for (i=0;i<l2;++i)
            A[0][i]=i*a;
        int p,q;
        int j;
        int c1,c2,c3;
        int up;
        for (i=1;i<l1;++i)
        {
            p=i%2;
            q=(i+1)%2;
            j=max(i-k,1);
            A[p][j-1]=999999999;
            if (j==1)
                A[p][j-1]=i*a;
            up=min(i+k+1,l2);
            for (j;j<up;++j)
            {
                if (S[i-1]==W[j-1])
                    c1=A[q][j-1];
                else
                    c1=b+A[q][j-1];
                c2=a+A[q][j];
                c3=a+A[p][j-1];
                A[p][j]=min(min(c1,c2),c3);
                //printf("%d ",A[p][j]);
            }
            //printf("\n");
        }
        ans=A[(l1-1)%2][l2-1];
        //printf("%d\n",ans);
        if (ans>k)
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}