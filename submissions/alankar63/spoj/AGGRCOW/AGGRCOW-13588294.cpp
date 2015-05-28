#include <bits/stdc++.h>
using namespace std;
int n,c;
int rec(int num,int arr[])
{
    int cows=1,pos=arr[0];
    for (int i=1; i<n; i++)
    {
        if (arr[i]-pos>=num)
        {
            pos=arr[i];
            cows++;
            if (cows==c)
                return 1;
        }
    }
    return 0;
}
int bs(int arr[])
{
    int start=0,last=arr[n-1],max=-1;
    while (last>start)
    {
        //cout<<last<<" "<<start<<endl;
        int mid=(start+last)/2;
        if (rec(mid,arr)==1)
        {
            //cout<<mid<<endl;
            if (mid>max)
                max=mid;
            start=mid+1;
        }
        else
            last=mid;
    }
    return max;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&n,&c);
        int arr[n];
        for (int i=0; i<n; i++)
            scanf("%d",&arr[i]);
        sort(arr,arr+n);
        //cout<<" dfsa \n";
        int k=bs(arr);
        printf("%d\n",k);
    }
    return 0;
}
