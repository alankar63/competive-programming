#include <cstdio>
#include <algorithm>
using namespace std;

#define N 211111
#define A 1001111
#define BLOCK 460 // ~sqrt(N)

long long int  cnt[A], a[N], ans[N], answer = 0;

struct node {
	 int L, R,in;

}q[N];

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		// different blocks, so sort by block.
		return x.L/BLOCK < y.L/BLOCK;
	}
	// same block, so sort by R value
	return x.R < y.R;
}

void add(int position) {
	cnt[a[position]]++;
	int h=cnt[a[position]];
	answer=answer+((2*h-1))*a[position];
	//if(cnt[a[position]] == 1) {
		//answer++;
	//}
}

void remove(int position) {
	cnt[a[position]]--;
    int h=cnt[a[position]];
	answer=answer-((2*h+1))*a[position];//2h+1
	//if(cnt[a[position]] == 0) {
		//answer--;
	//}
}

int main() {
	int n,d;
	//long long ans;
	scanf("%d %d", &n,&d);
	for(int i=0; i<n; i++)
		scanf("%I64d", &a[i]);

	int m;
	//scanf("%d", &m);
	for(int i=0; i<d; i++) {
		scanf("%d%d", &q[i].L, &q[i].R);
		q[i].L--; q[i].R--;
		q[i].in = i;
	}

	sort(q, q + d, cmp);

	int currentL = 0, currentR = 0;
	for(int i=0; i<d; i++) {
		int L = q[i].L, R = q[i].R;

		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].in] = answer;
	}

	for(int i=0; i<d; i++)
		printf("%I64d\n", ans[i]);
}