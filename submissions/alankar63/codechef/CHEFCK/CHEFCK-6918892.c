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
maybe I can find a hold.
I run against myself ‘till I find the end.

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
      ll temp=power(a,b/2,mod);
      temp=(temp*temp)%mod;
      if(b&1)
            temp=(temp*a)%mod;
      return temp;
}

 //power without mod........ int
ll pwr(ll a,ll b){
      if(b==0)
            return 1;
      ll temp=pwr(a,b/2);
      temp=(temp*temp);
      if(b&1)
            temp=(temp*a);
      return temp;
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

 //only for int
inline ll min(ll a,ll b) { return a<b? a : b; }
inline ll max(ll a,ll b) { return a>b? a : b; }

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
//not template but how to use ST
//for minimum element

long long tree[40000008];

ll A[10000004];
ll LR[10000005];
ll RL[10000006];
ll ar[10000006];


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

//...........................................END OF TEMPLATE.................................................................
void build_tree(ll node, ll a, ll b) {
    if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = A[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = min(tree[node*2], tree[node*2+1]); // Init root value
}
 ll query_tree(ll node, ll a, ll b, ll i, ll j) {

	if(a > b || a > j || b < i) return 10000000000003; // Out of range

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	ll q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	ll res = min(q1, q2); // Return final result

	return res;
}
void pint(ll n,ll k1)
{
	ll w=k1;
  ll  k = n - w + 1,i,j,l=1;
    for(i = 1,j=n; i <= n; i++,j--){
        {if(i % w == 1)
            LR[i] = A[i];
        else
            LR[i] = min(LR[i - 1], A[i]);  }
            {
            	if(j == n)
            RL[j] = A[j];
        else if(j % w == 0)
            RL[j] = A[j];
        else
            RL[j] = min(RL[j+1], A[j]);
            }
    }
    for(i = 1; i <= k; i++)
        ar[i] =min(RL[i], LR[i + w - 1]);
}
//ll mi[10000004];

int main()
{ ll i,j,k,te,n,q,a,b,c,d,e,f,r,s,t,m,l1,la,lc,lm,d1,da,dm,dc,x,l,am,anss=0,ansp=1,er=0,fe,fin,K;
    sl(n)
    sl(k)
    sl(q)

    sl(a)
    sl(b)
    sl(c)
    sl(d)
    sl(e)
    sl(f)
    sl(r)
    sl(s)
    sl(t)
    sl(m)
    sl(A[1])
    fin=A[1];
   fe=t;
   FOR(x,2,n+1)// for x = 2 to N:
	{  fe=(fe*(t%s))%s;
	   if(fe<=r)
       {
           A[x]=((a*power(A[x-1],2,m))%m+(b*A[x-1])%m+c)%m;
       }
       else
       {
           A[x]=((d*power(A[x-1],2,m))%m+(e*A[x-1])%m+f)%m;
       }
       fin=min(fin,A[x]);

	}//if(t^x mod s  <= r)        // Here t^x signifies "t to the power of x"
		//A[x] = (a*A[x-1]^2 + b*A[x-1] + c) mod m
	//else
		//A[x] = (d*A[x-1]^2 + e*A[x-1] + f) mod m

		//create(0,n-1,0);
		//pl(A[0])
		//pl(A[1])
		//pl(A[2])
		//pl(A[3])
		//build_tree(1, 0, n-1);

	sl(l1)
	sl(la)
	sl(lc)
	sl(lm)
	sl(d1)
	sl(da)
	sl(dc)
	sl(dm)

      pint(n,k);
      K=k-1;
    FOR(i,1,q+1)
    {
      l1 = (((la%lm) * (l1%lm))%lm + lc) % lm;
	d1 = (((da%dm) * (d1%dm))%dm + dc) % dm;
	l = l1 + 1;
	r = min(l + k - 1 + d1, n);
	//pl(l)
	//pl(r)

	//am=min()
	//er=messi(0,n-1,l-1,r-1,l-1);
	//er=query_tree(1, 0, n-1, l-1, r-1);
	//pl(er)
	if(l-1>=0 && l-1<n && r-1>=0 && r-1<n){
		 ll pos=r-l-K;
		ll min2=min(ar[l],ar[l+pos]);
		anss+=min2;
		ansp=(ansp*min2)%MOD;
	}
	//anss=(anss+er);
	//ansp=(ansp*er)%MOD;


    }
    printf("%llu %llu\n",anss,ansp);






    return 0;
}