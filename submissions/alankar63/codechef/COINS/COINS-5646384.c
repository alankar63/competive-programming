#include <stdio.h>
 
long long m[1000000];
 
long long change( int n ) {
    long long res = 0;
    
    if( n < 1000000 && m[n] ) return m[n];
 
    if( n == 0 ) return 0;
    else if( (n / 2) + (n / 3) + (n / 4) >= n )
	res = change(n/2) + change(n/3) + change(n/4);
    else res = n;
 
    if( n < 1000000 ) m[n] = res;
 
    return res;
}
 
int main( void ) {
    int n;
 
    while( scanf("%i", &n) != EOF )
	printf("%lld\n", change(n));
 
    return 0;
}