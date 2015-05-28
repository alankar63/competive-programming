#include <cstdio>
 //use of grundy numbers
using namespace std;
 
const int MAXN = 60;
int a[MAXN];
 
int main()
{
    int te;
    scanf("%d", &te);
    while (te--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
 
        int x = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                scanf("%d", &a[j]);
 
            int ans = 0;
            for (int j = m; j--; )
                ans = a[j] - (int)(a[j] <= ans);
 
            x ^= ans;
        }
        puts(x? "FIRST" : "SECOND");
    }
    return 0;
}