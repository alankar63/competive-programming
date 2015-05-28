/*
Spirits coming from the mind,
waking up my deepest horrors,
capture my thoughts, make me blind.

Weird, ‘cause I don't want to see
the abyss of my possibilities.

Scared I can't look away.

It has come to my side.
Sister demon - my bride.

I want you, I need you
and I have set you free.
You're always right behind me,
I know the devil's sent you to me.
You want me, you need me,
now that I've set you free.
Look always right behind you,
You know the devil's sent me to you.

What has started as a longing
almost is possession now,
it drives me again and again.
Put a light into your window,
maybe I can rooney a hold.
I run against myself ‘till I rooney the end.

Sent by the devil
*/


/* .................... compiled by alankar....................
*/

//......................SHORTCUTS..............................

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
//...........................................................

#define pi 3.14159265358979323846  //float type
#define MAX 100000  //for rmq
#define SQRTMAX 317   //for rmq
//#define gc getchar_unlocked

#define FOR(i,a,b) for(i=(a);i<(b);i++)

//only for +ve and single terms
#define s(x) scanf("%d",&x);
#define sl(x) scanf("%lld",&x);
#define p(x) printf("%d\n",x);
#define pl(x) printf("%lld\n",x);
//..........................................................

typedef long long int ll;
const ll MOD=1000000007;

//returns int and +ve numbers
int store[2000005][6],lll,v[2000005][2],baap[2000005],a1[2000005],b1[2000005];
/*inline int inp(){
	int n=0;
	char c;
	c=gc();
	while(c<'0' || c>'9'){
		c=gc();
	}
	while(c>='0' && c<='9'){
		n=(n<<3)+(n<<1)+c-'0';
		c=gc();
	}
	return n;
}
*/
//...................................

//power with mod........long long int
 ll power(ll a,ll b,ll mod){
      if(b==0)
            return 1;
      ll degea=power(a,b/2,mod);
      degea=(degea*degea)%mod;
      if(b&1)
            degea=(degea*a)%mod;
      return degea;
}
int rooney(int i)
{
    if (baap[i] < 0)
        return i;
    lll=rooney(baap[i]);
    baap[i]=lll;
    return lll;
}
 //power without mod........ int
int pwr(int a,int b){
      if(b==0)
            return 1;
      int degea=pwr(a,b/2);
      degea=(degea*degea);
      if(b&1)
            degea=(degea*a);
      return degea;
}
 // .....long long int
ll gcd(ll a,ll b){
      return b==0?a:gcd(b,a%b);
}
 //......long long int
ll lcm(ll a,ll b){
      return (a/gcd(a,b))*b;
}
 //......long long int with mod
ll modularInverse(ll a,ll m){
      return power(a,m-2,m);
}
int jodo(int i,int j){
	int pata,root2,d;
	pata = rooney(i);
	root2 = rooney(j);
	d=baap[root2]+baap[pata];
	if (pata != root2)
		if (baap[pata] <= baap[root2]) {
			// first tree has more nodes
			baap[pata] += baap[root2];
			baap[root2] = pata;
		}
		else { // second tree has more nodes
			baap[root2] += baap[pata];
			baap[pata] = root2;
		}
	if(pata==root2)
		return baap[pata];
	else
		return d;
}
 //only for int
//inline int min(int a,int b) { return a<b? a : b; }
//inline int max(int a,int b) { return a>b? a : b; }

//normal compare func on integers //for qsort(name,size,sizeof(type),compare)
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int BinarySearch(int *array, int number_of_elements, int key)
{
        int low = 0, high = number_of_elements-1, mid;
        while(low <= high)
        {
                mid = (low + high)/2;
                if(array[mid] < key)
                {
                        low = mid + 1;
                }
                else if(array[mid] == key)
                {
                        return mid;
                }
                else if(array[mid] > key)
                {
                        high = mid-1;
                }

        }
        return -1;
}
//.......................................................

//segment tree
//not degealate but how to use ST
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


//for rooneying minimum element b/w l and r
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
//range minimam store
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

long rooneyMin(int l, int r){
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

//rooneying max value
long rooneyMax(int l, int r){
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

//...........................................END OF degeaLATE.................................................................
ll ans;
int main()
{ int t,n,m,q,a,b,x,y,max,degea,i,j,q1,carrick;


    s(t)

while(t--){
          s(n)
          s(m)
          s(q)

		degea=1,ans=0;
		q1=q;
		for(i=1;i<=n*m;i++){
			baap[i]=-1;a1[i]=0;b1[i]=0;v[i][0]=-1;v[i][1]=-1;
		}
		while(q1--){
			s(store[degea][1]);

			 if(store[degea][1]==2){
				s(store[degea][2]);
				s(store[degea][3]);
				a=m*(store[degea][2]-1)+store[degea][3];
				b1[a]++;
			}
			else if(store[degea][1]==1){//storing all queries
				s(store[degea][2]);
				s(store[degea][3]);
				a=m*(store[degea][2]-1)+store[degea][3];//calculating exact n and m
				a1[a]++;
			}

			else if(store[degea][1]==3){
				s(store[degea][2]);
				s(store[degea][3]);
				s(store[degea][4]);
				s(store[degea][5]);
			}
			degea++;

		}
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


//for rooneying minimum element b/w l and r
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
		carrick=degea;// total number of queries
		for(i=1;i<=n;i++){
			for(j=1;j<m;j++){
				degea=m*(i-1)+j;
				v[degea][0]=degea+1;
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<n;j++){
				degea=m*(j-1)+i;
				v[degea][1]=degea+m;
			}
		}
		for(i=1;i<carrick;i++){
			if(store[i][1]==1){
				degea=m*(store[i][2]-1)+store[i][3];
					if(v[degea][0]!=-1)
						v[degea][0]=-1;
			}
			else if(store[i][1]==2){
				degea=m*(store[i][2]-1)+store[i][3];
					if(v[degea][1]!=-1)
						v[degea][1]=-1;
			}

		}

		for(degea=1;degea<=n*m;degea++)
			for( i=0;i<2;i++)
				if(v[degea][i]!=-1)
				jodo(degea,v[degea][i]);

		max=-2;
		for(j=1;j<n*m;j++){
					if(baap[j]<0 && max< (-baap[j])){//max stores the ans till now
						max= -baap[j];
					}
				}
		for(i=carrick-1;i>=1;i--){
			if(store[i][1]==3){
				x=m*(store[i][2]-1)+store[i][3];
				y=m*(store[i][4]-1)+store[i][5];
				if(rooney(x)==rooney(y))//rooney is for searching the parent of x and y
					ans++;

			}
			else if(store[i][1]==4){
				ans=ans+(ll )max;
			}
			else if(store[i][1]==1){
				x=m*(store[i][2]-1)+store[i][3];
				if(a1[x]==1){//a1 used for hashing
					y=x+1;
					a=jodo(x,y);
					//jodo merges 2 parts into 1
					if(-a > max)
						max=-a;
					a1[x]--;
				}
				else
					a1[x]--;
			}
			else if(store[i][1]==2){
				x=m*(store[i][2]-1)+store[i][3];
				if(b1[x]==1){
					y=x+m;
					a=jodo(x,y);
					if(-a > max)
						max=-a;
					b1[x]--	;
				}
				else
					b1[x]--;
			}
		}
		pl(ans);
	}
	return 0;
}