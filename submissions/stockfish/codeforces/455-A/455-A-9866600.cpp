#include <stdio.h>

#define LOCAL 0
#define VMAX 100001

int cnt[VMAX + 1];
long long pmax[VMAX + 1], tmp;
int N, i, x;

int main() {
//  freopen("x.txt", "r", stdin);
    if (LOCAL) N = 100000;
    else scanf("%d", &N);
    for (i = 0; i < N; i++) {
        if (LOCAL) {
            x = 100000;
        } else scanf("%d", &x);
        cnt[x]++;
    }

    pmax[0] = 0;
    pmax[1] = cnt[1];
    
    for (i = 2; i <= VMAX; i++) {
        pmax[i] = pmax[i - 1];
        tmp = (long long) i * (long long) cnt[i] + pmax[i - 2];
        if (tmp > pmax[i]) pmax[i] = tmp;
    }

    printf("%I64d\n", pmax[VMAX]);
    return 0;
}