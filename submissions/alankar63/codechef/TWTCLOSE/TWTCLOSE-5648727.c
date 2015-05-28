#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
bool open[1010];
char cmd[80];
 
int main( void ) {
    int n, k, i;
    scanf("%i %i", &n, &k);
    
    int no = 0, twt;
    for( i = 0; i < k; i++ ) {
	scanf("%s", cmd);
 
	if( !strcmp(cmd, "CLOSEALL") ) {
	    no = 0;
	    memset(open, 0, sizeof(open));
	}
	else {
	    scanf("%i", &twt);
	    open[twt] ^= 1;
	    no += (open[twt] == 1) ? 1 : -1;
	}
 
	printf("%i\n", no);
    }
 
    return 0;
}