#include <iostream>
#include <cmath>
using namespace std;
long long n,m;
int main()
{
    cin>>n>>m;
    cout<<min(n,m)+1<<'\n';
    int s=min(n,m);
    for(int i=0;i<=s;i++)
    cout<<i<<" "<<s-i<<'\n';
}