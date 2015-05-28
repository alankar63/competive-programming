//one of the best see fast printing
#include <stdio.h>
#include <string.h>
 
inline int readInt() {
    register int c = getchar_unlocked();
    int x = 0;
    int neg = 0;
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
    if(c == '-'){
        neg = 1;
        c = getchar_unlocked();
    }
    for(; c>47 && c<58 ; c = getchar_unlocked())
    	x = (x<<1) + (x<<3) + c - 48;
    if(neg)
    	x = -x;
    return x;
}
 
inline void printInt(int x){
	int rem = x%10;
	if(x/10)
		printInt(x/10);
	putchar_unlocked(rem+48);
}
 
int getAns(int f, int t){
	int ctr = 0;
	while(f^t){
		if(t>f)
            t=t>>1;
        else
            f=f>>1;
		ctr++;
	}
	return ctr;
}
 
int main(){
	int cases, f, t;
	cases = readInt();
	while(cases--){
		f = readInt();
		t = readInt();	
		printInt(getAns(f,t));
		putchar_unlocked('\n');
	}
	return 0;
}