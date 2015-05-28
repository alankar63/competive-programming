#include<stdio.h>
#include<stdlib.h>
int main() {
 
int test,n1,n2,n3,n4;
 
scanf("%d",&test);
while(test--) {
scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
printf("%lf\n",(double)n1/(n1+n2));
}
return 0;
}