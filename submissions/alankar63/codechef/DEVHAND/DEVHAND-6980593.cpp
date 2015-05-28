#include<bits/stdc++.h>
 
using namespace std;
 
//Never in my whole life have I been so frustrated.
 
typedef long long ll;
#define mod 1000000007
 
ll modex(ll a,ll b)
{
	if(b==0) return 1;
	if(b==1) return a%mod;
	ll temp;
	temp=modex(a,b/2);
	if(b%2==0)
	{
		return (temp*temp)%mod;
	}
	else
	{
		return (((temp*temp)%mod)*(a%mod))%mod;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	ll t,n,k;
	ll ans,t1,t2,t3,t4,tt1,tt2,tt3,tt4,tt5,tt6,tt7,tt8,it1,it2,iit1,iit2,temp;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		//x=y=z
		tt1=(((modex(k,3*n+3)-modex(k,3)+mod)%mod)*modex((pow(k,3)-1),mod-2))%mod;
		tt2=(((3*((modex(k,2*n+2))-modex(k,2)))%mod)*modex((pow(k,2)-1),mod-2))%mod;
		tt3=(((2*(modex(k,n+1)-k))%mod)*modex((k-1),mod-2))%mod;
		t1=(((tt1-tt2+mod)%mod)+(tt3))%mod;
		//x=y!=z
		tt1=(((modex(k,3*n+3)-modex(k,6)+mod)%mod)*modex(pow(k,5)+1-pow(k,2)-pow(k,3),mod-2))%mod;
		tt2=(((modex(k,n+3)-modex(k,4)+mod)%mod)*modex(pow(k,3)-pow(k,2)-k+1,mod-2))%mod;
		it1=(2*k+((n*modex(k,n+1))%mod))%mod;
		it2=(((((n*modex(k,n))%mod)+(modex(k,n)))%mod)+(k*k))%mod;
		tt3=(((((it1-it2+mod)%mod)*(2*k))%mod)*(modex(k*k+1-2*k,mod-2)))%mod;
		tt4=((2*((modex(k,n+1)-(k*k)+mod)%mod))*modex(k-1,mod-2))%mod;
		tt5=((3*((modex(k,2*n+2)-modex(k,4)+mod)%mod))*(modex(pow(k,3)+1-pow(k,2)-k,mod-2)))%mod;
		tt6=((3*((modex(k,n+2)-modex(k,3)+mod)%mod))*(modex(k*k+1-2*k,mod-2)))%mod;
		t2=(((((((((tt1-tt2+mod)%mod)+tt3)%mod)-tt4+mod)%mod)-tt5+mod)%mod)+tt6)%mod;
		//x!=y=z
		tt1=(((modex(k,3*n+3)-modex(k,6)+mod)%mod)*(modex(pow(k,4)+1-k-pow(k,3),mod-2)))%mod;
		tt2=(((modex(k,2*n+3)-modex(k,5)+mod)%mod)*(modex(pow(k,3)+1-pow(k,2)-k,mod-2)))%mod;
		it1=(((((modex(k,n+2)*n)%mod))%mod)+(2*k*k))%mod;
		it2=((((n+1)*modex(k,n+1))%mod)+modex(k,3))%mod;
		tt3=(((it1-it2+mod)%mod)*(modex(k*k+1-2*k,mod-2)))%mod;
		tt4=(((2*((modex(k,2*n+2)-modex(k,4)+mod)%mod))%mod)*(modex(k*k-1,mod-2)))%mod;
		tt5=(((modex(k,n+1)-(k*k)+mod)%mod)*(modex(k-1,mod-2)))%mod;
		it1=(((((n*modex(k,2*n+2))%mod)+(modex(k,2*n+2)))%mod)+(modex(k,6)))%mod;
		it2=(((n*modex(k,2*n+4))%mod)+(2*modex(k,4)))%mod;
		tt6=(((2*((it1-it2+mod)%mod))%mod)*(modex(pow(k,4)+1-2*k*k,mod-2)))%mod;
		t3=(((((((((tt1-tt2+mod)%mod)+tt3)%mod)+tt4)%mod)-tt5+mod)%mod)+tt6)%mod;
		//x!=y!=z
		iit1=(((modex(k,3*n+3)-modex(k,9)+mod)%mod)*modex(pow(k,3)-1,mod-2))%mod;
		iit2=(((modex(k,n+5)-modex(k,7)+mod)%mod)*modex(k-1,mod-2))%mod;
		tt1=(((iit1-iit2+mod)%mod)*(modex(pow(k,3)+1-pow(k,2)-k,mod-2)))%mod;
		//tt1 OKAY
 
		iit1=(((modex(k,2*n+3)-modex(k,7)+mod)%mod)*modex(k*k-1,mod-2))%mod;
		iit2=(((modex(k,n+4)-modex(k,6)+mod)%mod)*modex(k-1,mod-2))%mod;
		tt2=(iit1-iit2+mod)%mod;
		tt2=(tt2*modex(pow(k-1,2),mod-2))%mod;
		//tt2 OKAY
 
		temp=((n%mod)*(n%mod))%mod;
		iit1=(temp*modex(k,n+3))%mod;
		iit1=(modex(k,n+2)+iit1)%mod;
		iit1=(((temp*modex(k,n+1))%mod)+iit1)%mod;
		temp=(2*((n*modex(k,n+1))%mod))%mod;
		iit1=(iit1+temp)%mod;
		iit1=(iit1+modex(k,n+1))%mod;
		temp=(11*modex(k,4))%mod;
		iit1=(temp+iit1)%mod;
		temp=((n%mod)*(n%mod))%mod;
		iit2=(2*((temp*modex(k,n+2))%mod))%mod;
		iit2=(((2*((n*modex(k,n+2))%mod))%mod)+iit2)%mod;
		iit2=(((4*modex(k,5))%mod)+iit2)%mod;
		iit2=((((modex(k,3)*9))%mod)+iit2)%mod;
		tt3=(iit1-iit2+mod)%mod;
		tt3=(tt3*modex(2*pow(k-1,3),mod-2))%mod;
		//tt3 OKAY
 
		iit1=(modex(k,n+2)*n)%mod;
		iit1=(((3*modex(k,3))%mod)+iit1)%mod;
		iit2=((n+1)*modex(k,n+1))%mod;
		iit2=(((2*modex(k,4))%mod)+iit2)%mod;
		tt4=(iit1-iit2+mod)%mod;
		tt4=(tt4*3)%mod;
		tt4=(tt4*modex(2*pow(k-1,2),mod-2))%mod;
		//tt4 OKAY
 
		tt5=(modex(k,n+1)-modex(k,3)+mod)%mod;
		tt5=(tt5*modex(k-1,mod-2))%mod;
		//tt5 OKAY
 
		iit1=(n*modex(k,2*n+4))%mod;
		iit1=(((3*modex(k,6))%mod)+iit1)%mod;
		iit2=((n+1)*modex(k,2*n+2))%mod;
		iit2=(((2*modex(k,8))%mod)+iit2)%mod;
		tt6=(iit1-iit2+mod)%mod;
		tt6=(2*tt6)%mod;
		tt6=(tt6*modex(k-1,mod-2))%mod;
		tt6=(tt6*modex(pow(k*k-1,2),mod-2))%mod;
		//tt6 OKAY
 
		iit1=(modex(k,2*n+2)-modex(k,6)+mod)%mod;
		iit1=(iit1*modex(k*k-1,mod-2))%mod;
		iit2=(modex(k,n+3)-modex(k,5)+mod)%mod;
		iit2=(iit2*modex(k-1,mod-2))%mod;
		tt7=(iit1+iit2)%mod;
		tt7=(2*tt7)%mod;
		tt7=(tt7*modex(pow(k-1,2),mod-2))%mod;
		//tt7 OKAY
 
		tt8=(modex(k,2*n+3)-modex(k,7)+mod)%mod;
		tt8=(tt8*modex(k*k-1,mod-2))%mod;
		tt8=(4*tt8)%mod;
		tt8=(tt8*modex(pow(k-1,2),mod-2))%mod;
		//tt8 OKAY
 
		it1=(tt1+tt3)%mod;
		it1=(it1+tt5)%mod;
		it1=(it1+tt8)%mod;
		it2=(tt2+tt4)%mod;
		it2=(it2+tt6)%mod;
		it2=(it2+tt7)%mod;
		t4=(it1-it2+mod)%mod;
		// cout<<"8 components :\n";
		// cout<<tt1<<" "<<tt2<<" "<<tt3<<" "<<tt4<<" "<<tt5<<" "<<tt6<<" "<<tt7<<" "<<tt8<<"\n";
 
		if(n<3) t4=0;
		if(n<2) t2=t3=0;
		// cout<<t1<<" "<<((t2*3)%mod)<<" "<<((3*t3)%mod)<<" "<<((t4*6)%mod)<<"\n";
		ans=((((3*((t2+t3)%mod))+t1)%mod)+(6*t4))%mod;
		//Answer:
		cout<<ans<<"\n";
	}
	return 0;	
}