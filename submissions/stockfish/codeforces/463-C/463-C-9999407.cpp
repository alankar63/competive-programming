#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2345

long long n, a[N][N], di1[2*N], di2[2*N], ans[2], x[2], y[2];
int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        scanf("%lld", a[i]+j);
        di1[i+j] += a[i][j]; di2[i-j+N] += a[i][j];
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        int id = (i+j)%2;
        long long sum = di1[i+j] + di2[i-j+N] - a[i][j];
        if (sum >= ans[id]) {
            ans[id] = sum;
            x[id] = j; y[id] = i;
        }
    }
    printf("%lld\n%lld %lld %lld %lld\n", ans[0] + ans[1], y[0]+1, x[0]+1, y[1]+1, x[1]+1);

    return 0;
}