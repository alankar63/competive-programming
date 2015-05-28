#include<stdio.h>
#include<string.h>
 
char str[101][21];
char vote[101];
 
int search(char *p,int j){
    while(j>=0){
        if(strcmp(p,str[j])==0){
            return j;
        }
        j--;
    }
    return -1;
}
 
int main(){
    int t,i,count=0,found=0;
    char x[2];
    scanf("%d",&t);
    while(t--){
        count=0;
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
            scanf("%s",x);
            if(x[0]=='+')
                vote[i]=1;
            else
                vote[i]=-1;
 
            found=search(str[i],i-1);
            if(found>=0){
                count=count-vote[found];
            }
            count=count+vote[i];
        }
        printf("%d\n",count);
    }
    return 0;
}