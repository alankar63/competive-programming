#include <stdio.h>
 
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    scanf("%lld\n", &n);
    printf("%lld\n", n*(n - 1)/2);
    if (T == 0) break;
    char c;
    do {
      c = getchar_unlocked();
    } while (c != '\n');
  }
  return 0;
}