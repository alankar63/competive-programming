#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int Move[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m;
bool inside(int x,int y)
{
    if(x >= 1 && x <= n && y >= 1 && y <= m)return true;
    else return false;
}
int num[310*310];
bool vis[310][310];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int k;
    while(scanf("%d%d%d",&n,&m,&k) == 3)
    {
        for(int i = 0;i < k-1;i++)num[i] = 2;
        num[k-1] = n*m - 2*(k-1);
        int x = 1, y = 1;
        int now = 0;
        memset(vis,false,sizeof(vis));
        for(int i = 0;i < k;i++)
        {
            printf("%d",num[i]);
            for(int j = 0;j < num[i];j++)
            {
                printf(" %d %d",x,y);
                vis[x][y] = true;
                if(i == k-1 && j == num[i]-1)break;
                while((!inside(x+Move[now][0],y+Move[now][1])) || vis[x+Move[now][0]][y+Move[now][1]])now = (now+1)%4;
                x += Move[now][0];
                y += Move[now][1];
            }
            printf("\n");
        }
    }
    return 0;
}