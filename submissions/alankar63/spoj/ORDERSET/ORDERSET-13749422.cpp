#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAX 200010
 
static long in[MAX]; char C[MAX];
static int BIT[MAX+1], N, x=0, I=0, s, e;
struct el{long v; int c;} A[MAX], tmp[MAX];
 
int cmp(el const& l, el const& r){return l.v<r.v;}
int bsearch(long v){
    s=1; e=I;
    while(s<=e){
        int m=(s+e)>>1;
        if(A[m].v>=v)e=m-1;
        else s=m+1;
    }
    return s;
}
inline void update(int i, int v){
    for(; i<=MAX; i+=(i&-i))BIT[i]+=v;
}

//segment tree
//not template but how to use ST
//for minimum element
/*
long long s[400000];
long long a[1000000];
int create(long long b,long long e,long long n)
{
    if(b==e)
    {
        s[n]=a[b];
    }
    else
        {
            create(b,(b+e)/2,2*n+1);
            create((b+e)/2+1,e,2*n+2);
            s[n]=s[2*n+1]<s[2*n+2]?s[2*n+1]:s[2*n+2];
        }
    return 0;
}


//for finding minimum element b/w l and r
long long messi(long long b,long long e,long long l,long long r,long long n)
{
    long long i,j;
    if(e<l||b>r)
    {
        return 100000001;
    }
    if(b>=l&&e<=r)
    {
        return s[n];
    }
    i=messi(b,(b+e)/2,l,r,2*n+1);
    j=messi((b+e)/2+1,e,l,r,2*n+2);
    return i<j?i:j;
}
*/
//............................................................................
//range minimam query
//for mim and max number
/*

//preprocess create the min array

long min[SQRTMAX], max[SQRTMAX], b[MAX];
int size, n;

void preProcess(int n){
	int i=0, j=0, k=0;
	long minimum, maximum;

	size = sqrt(n);
	//printf("size = %d\n",size);
	while(j<size){
		minimum = maximum = b[i];
		for(k=0 ; k<size ; k++){
			if(minimum>b[i])
				minimum = b[i];
			if(maximum<b[i])
				maximum = b[i];
			i++;
		}
		min[j] = minimum;
		max[j] = maximum;
		j++;
	}
}

long findMin(int l, int r){
	int j, j2;
	long minimum = b[l];

	j = l/size + 1;
	j2 = r/size - 1;

	//printf("j= %d and j2 = %d\n", j,j2);
	while(l<j*size && l<=r){
		if(minimum > b[l]){
			minimum = b[l];

		}
		//printf("Checked for %d\n", l);
		l++;
	}
	while(j<=j2 && l<=r && j<size){
		if(minimum > min[j])
			minimum = min[j];
		l = (j+1)*size;
		//printf("Checked for %d  <-->  %d\n", j*size, l-1);
		j++;
	}
	while(l<=r){
		if(minimum > b[l]){
			minimum = b[l];
		}
		//printf("Checked for %d\n", l);
		l++;
	}
	return minimum;
}

//finding max value
long findMax(int l, int r){
	int j, j2;
	long maximum = b[l];

	j = l/size + 1;
	j2 = r/size - 1;

	//printf("j= %d and j2 = %d\n", j,j2);
	while(l<j*size && l<=r){
		if(maximum < b[l]){
			maximum = b[l];

		}
		//printf("Checked for %d\n", l);
		l++;
	}
	while(j<=j2 && l<=r && j<size){
		if(maximum < max[j])
			maximum = max[j];
		l = (j+1)*size;
		//printf("Checked for %d  <-->  %d\n", j*size, l-1);
		j++;
	}
	while(l<=r){
		if(maximum < b[l]){
			maximum = b[l];
		}
		//printf("Checked for %d\n", l);
		l++;
	}
	return maximum;
}
*/

inline int query(int i){
    int ans=0;
    for(; i>0; i-=(i&-i)) ans+=BIT[i];
    return ans;
}
 
int main()
{
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin>>C[i] >> in[i];
        if(C[i]=='I') tmp[++x].v=in[i];
    }
    sort(tmp+1, tmp+x+1, cmp);
    for(int i=1; i<=x; ++i){
        if(tmp[i-1].v!=tmp[i].v) {A[++I].v=tmp[i].v; A[I].c=0;}
    }
    for(int i=1; i<=N; ++i){
        if(C[i]=='I'){
            int y=bsearch(in[i]); A[y].c+=1;
            if (A[y].c==1) update(y, 1);
        }
        else if(C[i]=='D'){
            int y=bsearch(in[i]);
            if(A[y].c>0 && A[y].v==in[i]){update(y, -1); A[y].c=0;}
        }
        else if(C[i]=='C'){
            int y=bsearch(in[i]);
            int ans=query(y-1);
            cout << ans << '\n';
        }
        else if(C[i]=='K'){
            s=1; e=I;
            while(s<=e){
                int m=(s+e)>>1;
                if(query(m)>=in[i])e=m-1;
                else s=m+1;
            }
            if(s>I) cout << "invalid\n";
            else cout << A[s].v << '\n';
        }
    }
    return 0;
}