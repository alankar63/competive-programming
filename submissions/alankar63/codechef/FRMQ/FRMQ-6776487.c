#include<stdio.h>
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
long long premax[100002][18], arr[100001], nextgreater[100001], stck[100001];
 
int main(){
	int n, m, x, y, nminus1, start, end, diff, i, j, spoint = 0, mxin, nxin, ans2 = 0;
	long long skip;
	long long ans = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for(i = 0; i < n; i += 1) {
		nextgreater[i] = n;
		while(spoint > 0 && arr[i] > arr[stck[spoint - 1]]) {
			nextgreater[stck[--spoint]] = i;
		}
		stck[spoint++] = i;
	}
	for (i = 0; i < n; i++)
		premax[i][0] = i;
	for (j = 1; 1 << j <= n; j++){
		for (i = 0; i + (1 << (j - 1)) < n; i++){
			if (arr[premax[i][j - 1]] > arr[premax[i + (1 << (j - 1))][j - 1]])
				premax[i][j] = premax[i][j - 1];
			else
				premax[i][j] = premax[i + (1 << (j - 1))][j - 1];
		}
	}
	scanf("%d%d%d", &m, &x, &y);
	nminus1 =  n - 1;
	if(n < 50000 && m >= 50000000) {
		while(m--) {
			start = min(x, y);
			end = max(x, y);
			diff = end - start;
			diff = 31 - __builtin_clz(diff + 1);
			i = premax[start][diff];
			j = premax[end - (1 << diff) + 1][diff];
			x += 7;
			y += 11;
			if (arr[i] > arr[j]) {
				mxin = i;
			} else {
				mxin = j;
			}
			ans += arr[mxin];
			while (x >= nminus1) x -= nminus1;
			while (y >= n) y -= n;
		}
	} else {
		while(m--) {
			ans2 += 1;
			start = min(x, y);
			end = max(x, y);
			diff = end - start;
			diff = 31 - __builtin_clz(diff + 1);
			i = premax[start][diff];
			j = premax[end - (1 << diff) + 1][diff];
			if (arr[i] > arr[j]) {
				mxin = i;
			} else {
				mxin = j;
			}
			nxin = nextgreater[mxin];
			if (x != y) {
				if(start == x)
					skip = (mxin - x)/7;
				else
					skip = (mxin - y)/11;
				skip = min(skip, (nxin - y - 1)/11);
				skip = min(skip, (nxin - x - 1)/7);
			}
			skip = min(m + 1, max(1, skip));
			x += 7 * skip;
			y += 11 * skip;
			m -= (skip - 1);
			ans += arr[mxin] * skip;
			while (x >= nminus1) x -= nminus1;
			while (y >= n) y -= n;
		}
	}
	printf("%lld", ans);
	return 0;
}