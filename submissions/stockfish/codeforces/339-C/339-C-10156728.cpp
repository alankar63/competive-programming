#include <iostream>
#include <vector>
using namespace std;

int Arr[1001],m;
vector<int>wts;
int findd(int ind,int w1,int w2,int wha,int last){
    if(ind==m){
        cout<<"YES\n";
        for(int i=0;i<m;i++)
            cout<<Arr[i]<<" ";
        return 1;
    }
    if(wha==1)
        for(int i=0;i<wts.size();i++){
            if(i==last) continue;
            if(w1+wts[i]>w2){
                Arr[ind]=wts[i];
                if(findd(ind+1,w1+wts[i],w2,2,i)==1)
                    return 1;
            }
        }
    else
        for(int i=0;i<wts.size();i++){
            if(i==last) continue;
            if(w2+wts[i]>w1){
                Arr[ind]=wts[i];
                if(findd(ind+1,w1,w2+wts[i],1,i)==1)
                    return 1;
            }
        }
    return -1;
}
int main()
{
    string s;
    cin>>s>>m;
    for(int i=0;i<10;i++)
        if(s[i]=='1')
            wts.push_back(i+1);

    if(findd(0,0,0,1,-1)==-1)
        cout<<"NO";
    return 0;
}