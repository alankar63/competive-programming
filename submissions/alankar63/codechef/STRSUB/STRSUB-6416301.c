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
int pwr(int a,int b){
      if(b==0)
            return 1;
      int temp=pwr(a,b/2);
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
inline int min(int a,int b) { return a<b? a : b; }
inline int max(int a,int b) { return a>b? a : b; }

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

//...........................................END OF TEMPLATE.................................................................
ll b[100002];
ll bs(ll l,ll r,ll target)
{
    ll low = l; ll high = r+1;
while (low != high) {
    ll mid = low+(high-low ) / 2; // Or a fancy way to avoid int overflow
    if (b[mid] <= target) {
        /* This index, and everything below it, must not be the first element
         * greater than what we're looking for because this element is no greater
         * than the element.
         */
        low = mid + 1;
    }
    else {
        /* This element is at least as large as the element, so anything after it can't
         * be the first element that's at least as large.
         */
        high = mid;
    }
}
return low;
/* Now, low and high both point to the element in question. */
}
char a[100005];

ll we[100002];
int main()
{ ll i,j,k,t,n,q,l,r,m,c0,c1,f1;
ll ans;
    sl(t)
   while(t--)
   {
            sl(n)
            sl(k)
            sl(q)
            scanf("%s",a);
            FOR(i,n-k,n)
            b[i]=n;
            c0=c1=j=0;
            FOR(i,0,n)
            {


                    if((c0>k)||(c1>k))
                   {
                       b[j]=i-1;
                       if(a[j]=='1')
                        c1--;
                       else
                        c0--;
                       j++;
                       i--;
                       continue;

                   }

                   if(a[i]=='1')
                    c1++;
                   if(a[i]=='0')
                    c0++;
                    if(i==n-1)
                    {
                        while(c0>k||c1>k)
                   {
                       b[j]=n-1;
                       if(a[j]=='1')
                        c1--;
                       else
                        c0--;
                       j++;




                   }
                    }


            }
            while(j<n)
                b[j++]=n;
                we[0]=b[0];
                //FOR(i,0,n)
                //p(b[i])
            FOR(i,1,n)
            {
               we[i]=we[i-1] +b[i]-i;

            }
            while(q--)
            {  ans=0;
                sl(l)
                sl(r)
                m=bs(l-1,r-1,r-1);
               // p(m)
                ans=(r-m+1)*(r-m)/2;
                //pl(ans)
                if(l==1)
                {
                    ans=ans+we[m-1];
                }
                else
                {
                    ans=ans-we[l-2]+we[m-1];
                }
                pl(ans)

            }
   }


    return 0;
}