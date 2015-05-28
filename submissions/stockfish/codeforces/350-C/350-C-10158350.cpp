#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int NMax=100000;
int N;
pair<int,int> A[NMax];
bool comp(pair<int,int> a,pair<int,int> b){
    return abs(a.first)+abs(a.second)<abs(b.first)+abs(b.second);
}
int main()
{
    scanf("%d",&N);
    for (int i=0;i<N;i++)
        scanf("%d%d",&(A[i].first),&(A[i].second));
    sort(A,A+N,comp);
    int c=0;
    for (int i=0;i<N;i++){
        if (A[i].first==0 || A[i].second==0)
            c+=4;
        else
            c+=6;
    }
    printf("%d\n",c);
    for (int i=0;i<N;i++){
        if (A[i].first>0)
            printf("1 %d R\n",A[i].first);
        if (A[i].first<0)
            printf("1 %d L\n",-A[i].first);
        if (A[i].second>0)
            printf("1 %d U\n",A[i].second);
        if (A[i].second<0)
            printf("1 %d D\n",-A[i].second);
        printf("2\n");
        if (A[i].first>0)
            printf("1 %d L\n",A[i].first);
        if (A[i].first<0)
            printf("1 %d R\n",-A[i].first);
        if (A[i].second>0)
            printf("1 %d D\n",A[i].second);
        if (A[i].second<0)
            printf("1 %d U\n",-A[i].second);
        printf("3\n");
    }
    return 0;
}