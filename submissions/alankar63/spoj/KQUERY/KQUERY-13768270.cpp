#include <stdio.h>
/*
Spirits coming from the mind,
waking up my deepest horrors,
capture my thoughts, make me blind.

Weird, ‘cause I don't want to see
the abyss of my possibilities.

Scared I can't look away.

It has come to my side.
Sister demon - my bride.

I want you, I need you
and I have set you free.
You're always right behind me,
I know the devil's sent you to me.
You want me, you need me,
now that I've set you free.
Look always right behind you,
You know the devil's sent me to you.

What has started as a longing
almost is possession now,
it drives me again and again.
Put a light into your window,
maybe I can find a hold.
I run against myself ‘till I find the end.

Sent by the devil
*/
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <iterator>
 
 
using namespace std;
 
struct node{
    int v;
    int i;
    int j;
    int q;
};
 
typedef node node;
 
int tree[30001];
node inp[230000];
int n;
int maxVal;
 
bool operator <( node a, node b ) {
    if ( a.v == b.v ) {
        return a.j > b.j;
    }
    return a.v > b.v;
}
 
 
 
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(int idx, int val){
    while(idx <= maxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
 /*
Spirits coming from the mind,
waking up my deepest horrors,
capture my thoughts, make me blind.

Weird, ‘cause I don't want to see
the abyss of my possibilities.

Scared I can't look away.

It has come to my side.
Sister demon - my bride.

I want you, I need you
and I have set you free.
You're always right behind me,
I know the devil's sent you to me.
You want me, you need me,
now that I've set you free.
Look always right behind you,
You know the devil's sent me to you.

What has started as a longing
almost is possession now,
it drives me again and again.
Put a light into your window,
maybe I can find a hold.
I run against myself ‘till I find the end.

Sent by the devil
*/
int main()
{
    int m;
    scanf("%d", &n);
    maxVal = n;
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &inp[i].v);
        inp[i].i = i + 1;
        inp[i].j = -1;
        tree[i] = 0;
    }
    scanf("%d", &m);
    int res[m];
 
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d", &inp[i + n].i , &inp[i + n].j, &inp[i + n].v);
        inp[i + n].q = i;
    }
 /*
Spirits coming from the mind,
waking up my deepest horrors,
capture my thoughts, make me blind.

Weird, ‘cause I don't want to see
the abyss of my possibilities.

Scared I can't look away.

It has come to my side.
Sister demon - my bride.

I want you, I need you
and I have set you free.
You're always right behind me,
I know the devil's sent you to me.
You want me, you need me,
now that I've set you free.
Look always right behind you,
You know the devil's sent me to you.

What has started as a longing
almost is possession now,
it drives me again and again.
Put a light into your window,
maybe I can find a hold.
I run against myself ‘till I find the end.

Sent by the devil
*/
    sort( inp, inp + n + m );
 
 
    for(int i = 0 ; i < n + m ; i++){
        if(inp[i].j == -1){
            update(inp[i].i, 1);
        }else{
            int result = read(inp[i].j) - read(inp[i].i - 1);
            res[inp[i].q] = result;
        }
    }
 
    for(int i = 0 ; i < m ; i++)
        printf("%d\n", res[i]);
    return 0;
}