#include<bits/stdc++.h>
using namespace std;
int A[200005];
int Hash[100005][2];
int main(){
int t,len,s,n,max,dif,m,i,l,r,j,k,t2,t1;
cin>>n>>m>>k;
for(i=0;i<n;i++){
    cin>>A[i];
}
len=k;
for(k=1;k<=len;k++){
    cin>>l>>r;
    max=0;
    dif=0;
    for(i=l-1,j=r-1;i<=j;i++,j--){
       t2=A[i];t1=A[j];
       if(Hash[t2][0]==k){
           dif=abs(i-Hash[t2][1]);
           if(max<dif)max=dif;
           //cout<<max<<"max2 \t";
       }
       else{
           Hash[t2][1]=i;
           Hash[t2][0]=k;
           //cout<<"i "<<i<<endl;
       }
       if(Hash[t1][0]==k){
 dif=abs(j-Hash[t1][1]);
           if(max<dif)max=dif;
       //cout<<max<<"max1 \t";
           
       }
        else{
             Hash[t1][1]=j;
           Hash[t1][0]=k;
        }
        if(r-i<max)break;
    }
    cout<<max<<"\n";
}
return 0;}