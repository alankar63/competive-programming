#include <stdio.h>
 
#define true 1
#define false 0
 
typedef int bool;
 
typedef struct CARD {
	int rank;
	char suit;
} CARD;
 
CARD a [5];
 
int get_rank (char ch) {
	if (ch>='0' && ch<='9')
		return ch-'0';
	switch (ch) {
		case 'T':
			return 10;
		case 'J':
			return 11;
		case 'Q':
			return 12;
		case 'K':
			return 13;
		case 'A':
			return 14;
	}
	return 0;
}
 
void sort_rank (void) {
	int i, j;
	CARD tcard;
	for (i=4; i>0; i--) {
		for (j=0; j<i; j++) {
			if (a[j].rank>a[i].rank) {
				tcard = a[i];
				a[i] = a[j];
				a[j] = tcard;
			}
		}
	}
}
 
bool flush (void) {
	int i;
	char suit = a[0].suit;
	for (i=1; i<5; i++)
		if (a[i].suit!=suit)
			return false;
	return true;
}
 
bool straight (void) {
	int i;
	bool ok = true;
	for (i=1; i<5; i++) {
		if (a[i].rank-a[i-1].rank!=1) {
			ok = false;
			break;
		}
	}
	if (!ok && a[4].rank==14) {
		CARD b [5];
		for (i=0; i<5; i++) {
			b[i] = a[i];
			if (a[i].rank==14)
				a[i].rank = 1;
		}
		sort_rank();
		ok = true;
		for (i=1; i<5; i++) {
			if (a[i].rank-a[i-1].rank!=1) {
				ok = false;
				break;
			}
		}
		for (i=0; i<5; i++)
			a[i] = b[i];
	}
	return ok;
}
 
bool straight_flush (void) {
	if (straight() && flush())
		return true;
	return false;
}
 
bool royal_flush (void) {
	if (straight_flush() && a[0].rank==10)
		return true;
	return false;
}
 
bool four_of_a_kind (void) {
	if (a[0].rank==a[3].rank || a[1].rank==a[4].rank)
		return true;
	return false;
}
 
bool full_house (void) {
	if (a[0].rank==a[2].rank && a[3].rank==a[4].rank)
		return true;
	if (a[0].rank==a[1].rank && a[2].rank==a[4].rank)
		return true;
	return false;
}
 
bool three_of_a_kind (void) {
	if (a[0].rank==a[2].rank || a[1].rank==a[3].rank || a[2].rank==a[4].rank)
		return true;
	return false;
}
 
bool two_pairs (void) {
	if (a[0].rank==a[1].rank && a[2].rank==a[3].rank)
		return true;
	if (a[1].rank==a[2].rank && a[3].rank==a[4].rank)
		return true;
	return false;
}
 
bool pair (void) {
	int i;
	for (i=1; i<5; i++)
		if (a[i].rank==a[i-1].rank)
			return true;
	return false;
}
 
int main (void) {
	int tc, i, j;
	char s [3];
	CARD tcard;
	scanf( "%d", &tc );
	while (tc--) {
		for (i=0; i<5; i++) {
			scanf( "%s", s );
			a[i].rank = get_rank( s[0] );
			a[i].suit = s[1];
		}
		sort_rank();
		if (royal_flush())
			puts( "royal flush" );
		else if (straight_flush())
			puts( "straight flush" );
		else if (four_of_a_kind())
			puts( "four of a kind" );
		else if (full_house())
			puts( "full house" );
		else if (flush())
			puts( "flush" );
		else if (straight())
			puts( "straight" );
		else if (three_of_a_kind())
			puts( "three of a kind" );
		else if (two_pairs())
			puts( "two pairs" );
		else if (pair())
			puts( "pair" );
		else
			puts( "high card" );
	}
	return 0;
}