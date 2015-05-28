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
#define sl(x) scanf("%llu",&x);
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
ll n;
long long int tree[100004]={0};
ll tree0[100004]={0};
ll tree1[100004]={0};
ll tree2[100004]={0};
char a[100002];
ll b[100002];
ll f[100002][3]={{0}};
ll l[100002];
void update(long long int p,long long int v)
 {

    for (; p <= n; p += p&(-p))
        tree[p] += v ;
 }
      long long int  query(long long int b)
  {

   long long int  sum = 0  ;
    for(; b > 0; b -= b&(-b))
        sum += tree[b];
    return sum;
  }

void update0(long long int p,long long int v)
 {

    for (; p <= n; p += p&(-p))
        tree0[p] += v ;
 }
      long long int  query0(long long int b)
  {

   long long int  sum = 0  ;
    for(; b > 0; b -= b&(-b))
        sum += tree0[b];
    return sum;
  }


void update1(long long int p,long long int v)
 {

    for (; p <= n; p += p&(-p))
        tree1[p] += v ;
 }
      long long int  query1(long long int b)
  {

   long long int  sum = 0  ;
    for(; b > 0; b -= b&(-b))
        sum += tree1[b];
    return sum;
  }


void update2(long long int p,long long int v)
 {

    for (; p <= n; p += p&(-p))
        tree2[p] += v ;
 }
      long long int  query2(long long int b)
  {

   long long int  sum = 0  ;
    for(; b > 0; b -= b&(-b))
        sum += tree2[b];
    return sum;
  }


int main()
{ ll i,j,k,t,m,c,d,ans,hu,ho,div,div1,val,sac,seh;
//pl(tree2[1000]);
char ch;
   sl(n)
   sl(m)
   scanf("%c",&ch);
    l[0]=0;
     FOR(i,1,n+1)
    {scanf("%c",&a[i]);
     b[i]=a[i]-48;
    // p(b[i])

    l[i]=l[i-1]+b[i];
    f[i][0]=f[i-1][0];
    f[i][1]=f[i-1][1];
    f[i][2]=f[i-1][2];
    t=l[i]%3;
    f[i][t]++;
    }

FOR(i,1,m+1)
{ans=0;
       sl(t)
       sl(c)
       sl(d)
       if(t==1)
       {   val=d-b[c];
        // pl(val)
           div=(l[c]+query(c))%3;
        // pl(div)
            b[c]=d;
            //pl(b[c])

             update(c, val) ;
            // update(n + 1, -(val));
              div1=(l[c]+query(c))%3;
             // pl(div1)
             if(div==0)
             {
               update0(c, -1) ;
            // update0(n + 1, 1);
             }
             if(div==1)
             {
               update1(c, -1) ;
            // update1(n + 1, 1);
             }
             if(div==2)
             {
                update2(c, -1) ;
            // update2(n + 1, 1);
             }
              if(div1==0)
             {
                 update0(c, 1) ;
            // update0(n + 1, -1);
             }
             if(div1==1)
             {
                update1(c, 1) ;
            // update1(n + 1, -1);
             }
             if(div1==2)
             {
                 update2(c, 1) ;
            // update2(n + 1, -1);
             }


       }
       if(t==2)
       {
            FOR(j,0,3)
            {
               if(j==0)
               {sac=query0(d);
               seh=query0(c-1);
              // pl(sac)
              // pl(seh)
                  hu=f[d][j]-f[c-1][j]+sac-seh;
                 // pl(hu)
               }
               if(j==1)
               {
                   sac=query1(d);
               seh=query1(c-1);
               //pl(sac)
               //pl(seh)
                  hu=f[d][j]-f[c-1][j]+sac-seh;
                 // pl(hu)
               }
               if(j==2)
               {
                   sac=query2(d);
               seh=query2(c-1);
              // pl(sac)
              // pl(seh)
                  hu=f[d][j]-f[c-1][j]+sac-seh;
                 // pl(hu)
               }
                if(((l[c-1]+query(c-1))%3)==j)
                hu=hu+1;

             if(hu>1)
              ans=ans+(hu*(hu-1))/2;
             }
              pl(ans)
         }

}


    return 0;
}