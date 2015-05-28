#include <stdio.h>
 
int D (int x) {
	int res = 0;
	int t;
	while (x>0) {
		t = x%10;
		if (t%2==0)
			res += t*2;
		else
			res += t;
		x /= 10;
	}
	return res%10;
}
 
int C (int x) {
	if (x%10==0)
		return (x/10)*45;
	return C(x-1)+D(x-1);
}
 
int a, b;
 
int main (void) {
	int tc;
	scanf( "%d", &tc );
	while (tc--) {
		scanf( "%d%d", &a, &b );
		printf( "%d\n", C(b+1)-C(a) );
	}
	return 0;
}