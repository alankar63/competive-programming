//fenwick tree avoided
#include<stdio.h>
#define ll long long
 
ll give[51111], total[1111111], change;
int index[51111];
char s[11];
 
int main() {
	int n, q, i, j, updates = 0;
 
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", total + i);
		total[i] += total[i - 1];
	}
 
	while (q--) {
 
		scanf("%s", s);
		if (*s == 'G' || *s == 'T') {
			
			scanf("%d%lld", &i, &change);
 
			if (*s == 'T') change = -change;
			index[updates] = i;
			give[updates++] = change;
 
		} else {
 
			scanf("%d%d", &i, &j);
 
			ll s = total[++j] - total[i];
			for(int k = 0; k < updates; k++)
				if (i <= index[k] && index[k] < j)
					s += give[k];
 
			printf("%lld\n", s);
 
		}
	}
}