#include <cassert>
#include<stdio.h>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <numeric>
#include <algorithm>
using namespace std;
 
 
 
int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int primefrq[100002][25];
 
void store(int num,int index){
for(int j=0;j<25;j++) primefrq[index][j]=primefrq[index-1][j];
 
for(int j=0;j<25;j++){
while(num%prime[j]==0) {primefrq[index][j]++;num=num/prime[j];}
 
}
 
}
 
 
long long power(long long b,long long p,long long m)
{
if(b==0)
return 1;
long long int x = 1, y = b;
while(p > 0) {
if(p%2 == 1) {
x=(x*y);
if(x>m) x%=m;
}
y = (y*y);
if(y>m) y%=m;
p/= 2;
}
return x;
}
 
 
void fastread(int *a)
{ char c=0;
while(c<33)
{c=getchar();}
*a=0;
while(c>33)
{
*a=*a*10+c-'0';
c=getchar();
}
}
 
 
int main(){
int n,c;
//freopen("input5.txt","r",stdin);
fastread(&n);
for(int i=1;i<=n;i++){
fastread(&c);
 
store(c,i);
 
}
int t,l,r,m,dif;fastread(&t);
long long int ans=1;
while(t--){
fastread(&l);fastread(&r);fastread(&m);
for(int i=0;i<25;i++){
dif=(primefrq[r][i]-primefrq[l-1][i]);
 
if(dif>0)ans=(ans*power(prime[i],dif,m)%m);
}
 
printf("%lld\n",ans%m);
ans=1;
}
return 0;
}