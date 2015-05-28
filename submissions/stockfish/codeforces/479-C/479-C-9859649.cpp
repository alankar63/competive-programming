#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int D[100010], C, n, k, limit, M[100010], cnt;
pair<int,int> p[100010];

#define MAKE(a,b) make_pair(a,b)
int main()
{
    scanf("%d",&n);
    for (int i = 1, A, B;i <= n;i ++)
        scanf("%d%d",&A,&B), p[i] = MAKE(A,B);

    sort(p + 1, p + n + 1);
    for (int i = 1;i <= n;i ++)
        if (p[i].second >= C) C = p[i].second; else C = p[i].first;
    printf("%d",C);
    return 0;
}