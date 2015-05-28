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
char a[1000002],ch,y,z;
ll b[1000002][4];
ll c[1000002][12]={{0}};
ll ans;
int main()
{ int i,j,k,t,l,r,len,co;
scanf("%s",a);
len=strlen(a);
i=0;
if(a[i]=='c')
 b[i][0]=1;
 if(a[i]=='h')
 b[i][1]=1;
 if(a[i]=='e')
 b[i][2]=1;
 if(a[i]=='f')
  b[i][3]=1;


 FOR(i,1,len)
 {
     b[i][0]=b[i-1][0];
     b[i][1]=b[i-1][1];
     b[i][2]=b[i-1][2];
     b[i][3]=b[i-1][3];
     if(a[i]=='c')
 b[i][0]++;
 if(a[i]=='h')
 b[i][1]++;
 if(a[i]=='e')
 b[i][2]++;
 if(a[i]=='f')
  b[i][3]++;

  FOR(j,0,12)
  {
      c[i][j]=c[i-1][j];
  }

      if(a[i]=='c')
    {
        c[i][3]=c[i][3]+b[i][1];
        c[i][6]=c[i][6]+b[i][2];
        c[i][9]=c[i][9]+b[i][3];
    }
 if(a[i]=='h')
    {
         c[i][0]=c[i][0]+b[i][0];
        c[i][7]=c[i][7]+b[i][2];
        c[i][10]=c[i][10]+b[i][3];
    }
 if(a[i]=='e')
    {
         c[i][1]=c[i][1]+b[i][0];
        c[i][4]=c[i][4]+b[i][1];
        c[i][11]=c[i][11]+b[i][3];
    }
 if(a[i]=='f')
   {
        c[i][2]=c[i][2]+b[i][0];
        c[i][5]=c[i][5]+b[i][1];
        c[i][8]=c[i][8]+b[i][2];
   }


 }
    s(t)
   while(t--)
   {  ans=0;
      scanf("%c",&ch);
      scanf("%c",&y);
      scanf("%c",&ch);
      scanf("%c",&z);
      s(l)
      s(r)
      if(y=='c'&&z=='h')
      {
          ans=c[r-1][0];
          if(l-2>=0)
          { ans=ans-c[l-2][0];
             ans=ans-(b[l-2][0]*(b[r-1][1]-b[l-2][1]));
          }

          pl(ans)

      }
      else if(y=='c'&&z=='e')
      {
          ans=c[r-1][1];
          if(l-2>=0)
          { ans=ans-c[l-2][1];
             ans=ans-(b[l-2][0]*(b[r-1][2]-b[l-2][2]));
          }

          pl(ans)
      }
      else if(y=='c'&&z=='f')
      { ans=c[r-1][2];
          if(l-2>=0)
          { ans=ans-c[l-2][2];
             ans=ans-(b[l-2][0]*(b[r-1][3]-b[l-2][3]));
          }

          pl(ans)

      }
      else if(y=='h'&&z=='c')
      {
           ans=c[r-1][3];
          if(l-2>=0)
          { ans=ans-c[l-2][3];
             ans=ans-(b[l-2][1]*(b[r-1][0]-b[l-2][0]));
          }

          pl(ans)
      }
      else if(y=='h'&&z=='e')
      {
           ans=c[r-1][4];
          if(l-2>=0)
          { ans=ans-c[l-2][4];
             ans=ans-(b[l-2][1]*(b[r-1][2]-b[l-2][2]));
          }

          pl(ans)
      }
      else if(y=='h'&&z=='f')
      {
           ans=c[r-1][5];
          if(l-2>=0)
          { ans=ans-c[l-2][5];
             ans=ans-(b[l-2][1]*(b[r-1][3]-b[l-2][3]));
          }

          pl(ans)
      }
      else if(y=='e'&&z=='c')
      { ans=c[r-1][6];
          if(l-2>=0)
          { ans=ans-c[l-2][6];
             ans=ans-(b[l-2][2]*(b[r-1][0]-b[l-2][0]));
          }

          pl(ans)

      }
      else if(y=='e'&&z=='h')
      {
           ans=c[r-1][7];
          if(l-2>=0)
          { ans=ans-c[l-2][7];
             ans=ans-(b[l-2][2]*(b[r-1][1]-b[l-2][1]));
          }

          pl(ans)
      }
      else if(y=='e'&&z=='f')
      {
           ans=c[r-1][8];
          if(l-2>=0)
          { ans=ans-c[l-2][8];
             ans=ans-(b[l-2][2]*(b[r-1][3]-b[l-2][3]));
          }

          pl(ans)
      }
      else if(y=='f'&&z=='c')
      {
           ans=c[r-1][9];
          if(l-2>=0)
          { ans=ans-c[l-2][9];
             ans=ans-(b[l-2][3]*(b[r-1][0]-b[l-2][0]));
          }

          pl(ans)
      }
      else if(y=='f'&&z=='h')
      {
           ans=c[r-1][10];
          if(l-2>=0)
          { ans=ans-c[l-2][10];
             ans=ans-(b[l-2][3]*(b[r-1][1]-b[l-2][1]));
          }

          pl(ans)
      }
      else
      {
           ans=c[r-1][11];
          if(l-2>=0)
          { ans=ans-c[l-2][11];
             ans=ans-(b[l-2][3]*(b[r-1][2]-b[l-2][2]));
          }

          pl(ans)
      }

     // ans=rec(l-1,r-1,0,len-1,0,)

   }


    return 0;
}