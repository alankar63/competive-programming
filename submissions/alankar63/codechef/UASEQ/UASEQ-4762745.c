#include<stdio.h>
    #include<stdlib.h>
    #define mod 1000000000
    int main()
    {
    long long int n,k,i,array[200000],d=0,j,count,count1,flag=0,a,x,y,z;
    float d1;
    long long int s,l,ans=mod+1,diff=1;
    scanf("%lld%lld",&n,&k);
    x=10000000000;//chage it
    y=0;//change x and y
    for(i=1;i<=n;i++)
    scanf("%llu",&array[i]);
    //for(i=0;i<n;i++)
    // printf("%llu",array[i]);
    if(n>25){
    for(i=1;i<n;i++){
    flag=0;
    count=0;
    count1=0;
    d=array[i+1]-array[i];
    count1=array[i+1];
    for(j=i+1;j<n;j++){
    if(array[j+1]!=count1+d){
    count++;
    count1=count1+d;
    }
    if(count>k){
    flag=1;
    break;
    }
    }
    if(flag==1)
    continue;
    else{
    count1=array[i];
    for(j=i-1;j>=1;j--){
    if(array[j]!=count1-d)
    count++;
    count1=count1-d;
    if(count>k){
    flag=1;
    break;
    }
    }
    }
    if(flag==1)
    continue;
    a=array[i]-(i-1)*d;
    if(a<x){
    x=a;
    y=d;
    }
    else if(a==x){
    if(d<y)
    y=d;
    }
    }
    for(i=1;i<=n;i++){
    printf("%lld ",x);
    x=x+y;
    }
    }

    else{
    for(i=1;i<n;i++)
    {
    for(j=i+1;j<=n;j++)
    { flag=0;
    d=(array[j]-array[i])/(j-i);
    d1=(array[j]-array[i])/(j-i);
    s=array[i]+(1-i)*d;
    if(d1-d>0.001||d-d1>0.001)
    continue;

    else if((s>ans)||(s==ans&&d>diff))
    continue;
    else
    {for(z=1;z<=n;z++)
    {
    if(flag>k)
    break;
    else
    if(array[z]!=array[i]+(z-i)*d)
    flag++;
    }
    if(flag<=k)
    {
    ans=s;diff=d;
    }


    }
    }
    }
    for(i=1;i<=n;i++)
    printf("%lld ",(ans+((i-1)*diff)));


    }
    return 0;
    }