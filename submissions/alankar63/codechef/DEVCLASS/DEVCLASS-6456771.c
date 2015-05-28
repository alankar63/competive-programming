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
 ll min(ll a,ll b) { return a<b? a : b; }
 int max(int a,int b) { return a>b? a : b; }

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
ll b[100004],c[100004];
char ar[200008],ch;
int main()
{ ll i,j,k,t,n,ty,len,c1,c2,ans,ans1,ala,lal;
    sl(t)
  fo: while(t--)
   {    j=c1=c2=ans=ans1=ala=lal=0;
       sl(ty)
       scanf("%c",&ch);
       while(ch!='\n')
        scanf("%c",&ch);
       scanf("%s",ar);
       len=(ll)strlen(ar);

       FOR(i,0,len)
       {
           if(ar[i]=='B')
            c1++;
           if(ar[i]=='G')
            c2++;
       }

       if((c1-c2)>1)
       {
           printf("-1\n");
         goto fo;
       }

        if((c2-c1)>1)
       {
           printf("-1\n");
         goto fo;
       }

      {

       if(ty==0)
       { if(len%2==0)
       {
             FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='B'))
              {
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='B'))
              {
                  ans++;
              }

           }
            ans=(ans)/2;
           FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='G'))
              {
                  ans1++;
              }
              if(((i%2)==1)&&(ar[i]=='G'))
              {
                  ans1++;
              }

           }
           ans1=(ans1)/2;
          n= min(ans1,ans);
           pl(n)
          // puts("df");
       }

           else
           {
               if(c2>c1)
               {
                   FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='G'))
              {
                  ans1++;
              }
              if(((i%2)==1)&&(ar[i]=='G'))
              {
                  ans1++;
              }

           }
           ans1=(ans1)/2;
           pl(ans1)
               }
               else
               {
                    FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='B'))
              {
                  ans1++;
              }
              if(((i%2)==1)&&(ar[i]=='B'))
              {
                  ans1++;
              }

           }
           ans1=(ans1)/2;
           pl(ans1)
               }
           }


       }


    else if(ty==1)
       {
          if(len%2==0)
          {
                FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='B'))
              {   b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='B'))
              {    c[ans1]=i;
                  ans1++;
              }

           }
             FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    ala=ala+b[i]-c[i];
                 else
                    ala=ala+c[i]-b[i];
             }

             ans=ans1=0;
                FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='G'))
              {   b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='G'))
              {    c[ans1]=i;
                  ans1++;
              }

           }
             FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    lal=lal+b[i]-c[i];
                 else
                    lal=lal+c[i]-b[i];
             }
             n=min(ala,lal);
             pl(n)
          }
          else
          {
                  if(c2>c1)
               {
                   FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='G'))
              {  b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='G'))
              {   c[ans1]=i;
                  ans1++;
              }

           }
           lal=0;
            FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    lal=lal+b[i]-c[i];
                 else
                    lal=lal+c[i]-b[i];
             }

           pl(lal)
               }
               else
               {
                   FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='B'))
              {  b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='B'))
              {   c[ans1]=i;
                  ans1++;
              }

           }
           lal=0;
            FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    lal=lal+b[i]-c[i];
                 else
                    lal=lal+c[i]-b[i];
             }

           pl(lal)
               }
          }
       }

          else
          {
          if(len%2==0)
          {
                FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='B'))
              {   b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='B'))
              {    c[ans1]=i;
                  ans1++;
              }

           }
             FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    ala=ala+b[i]-c[i];
                 else
                    ala=ala+c[i]-b[i];
             }

             ans=ans1=0;
                FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='G'))
              {   b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='G'))
              {    c[ans1]=i;
                  ans1++;
              }

           }
             FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    lal=lal+b[i]-c[i];
                 else
                    lal=lal+c[i]-b[i];
             }
             n=min(ala,lal);
             pl(n)
          }
          else
          {
                  if(c2>c1)
               {
                   FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='G'))
              {  b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='G'))
              {   c[ans1]=i;
                  ans1++;
              }

           }
           lal=0;
            FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    lal=lal+b[i]-c[i];
                 else
                    lal=lal+c[i]-b[i];
             }

           pl(lal)
               }
               else
               {
                   FOR(i,0,len)
           {
              if(((i%2)==0)&&(ar[i]!='B'))
              {  b[ans]=i;
                  ans++;
              }
              if(((i%2)==1)&&(ar[i]=='B'))
              {   c[ans1]=i;
                  ans1++;
              }

           }
           lal=0;
            FOR(i,0,ans)
             {
                 if(b[i]>c[i])
                    lal=lal+b[i]-c[i];
                 else
                    lal=lal+c[i]-b[i];
             }

           pl(lal)
               }
          }
          }
       }
   }




    return 0;
}