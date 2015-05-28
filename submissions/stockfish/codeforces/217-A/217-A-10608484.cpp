#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node {
    int x, y, f;
} a[200];
int f[200];

int getf(int x) {
    while (a[x].f != x) {
        a[x].f = a[a[x].f].f;
        x = a[x].f;
    }
    return a[x].f;
}

void hb(int x, int y) {
    x = getf(x);
    y = getf(y);
    a[x].f = y;
}
bool p[200];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
            a[i].f = i;
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i].x == a[j].x || a[i].y == a[j].y)
                    hb(i, j);
        memset(p, 0, sizeof (p));
        for (int i = 0; i < n; i++)
            p[getf(i)] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (p[i])ans++;
        cout << ans - 1 << endl;
    }
    return 0;
}