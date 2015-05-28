#include<stdio.h>
#define MAX 50
 
     void partition(int arr[],int low,int high){
 
    int mid;
 
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
 
void mergeSort(int arr[],int low,int mid,int high){
 
    int i,m,k,l,temp[MAX];
 
    l=low;
    i=low;
    m=mid+1;
 
    while((l<=mid)&&(m<=high)){
 
         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }
 
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
 
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
 
int main()
{
    int i,j,n,cake_weight[MAX],wight[MAX],t=0,count1=0,m;
    scanf("%d",&m);
    while(m!=0)
    {
        count1=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&cake_weight[i]);
    }
    partition(cake_weight,0,n-1);
 
    for(i=0;i<n;i++)
    {
        scanf("%d",&wight[i]);
    }
    partition(wight,0,n-1);
   t=0;
   for(i=0;i<n;i++)
   {
 
    for(j=t;j<n;j++)
        {
            if(cake_weight[i]<=wight[j])
           {
                count1++;
            break;
           }
 
        }
        t=++j;
    }
    printf("%d\n",count1);
   m--;
 }
}