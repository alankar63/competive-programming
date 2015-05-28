#include<stdio.h>
#include<stdlib.h>

long long int facto(long long int a){
    int i,j;
    if(a==0){
        return 1;
    }
    else{
        return a*facto(a-1);
    }
}
int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}
int main(){
   long long  int a,i,j,k;
   long long  int s[12],temp,mini=0;
    // printf("number of test cases\n");
    scanf("%lld",&a);
    while(a--){
        //        printf("number of batsmen to be selected\n");
        for(i=0;i<11;i++){
            //  printf("enter runs\n");
            scanf("%lld",&s[i]);
            //   printf("%d\t",s[i]);
            
        }
        
        scanf("%d",&k);
        
        qsort(s, 11, sizeof(long long int), compare_ints);
        

        long long   int c=0,d=0;
        long long int result=0;
        for(i=0;i<=10;i++){
            if (s[i]==s[11-k]) {
                d++;
            }
        }
        int arr[12];
        
        for(j=0;j<k;j++){
            arr[j]=s[10-j];
        }
        
        
        for(j=0;j<k;j++){
            if(arr[j]==arr[k-1])
                c++;
        }
        result=((facto(d))/((facto(c))*(facto(d-c))));
        printf("%lld\n",result);
    }
    return 0;
}