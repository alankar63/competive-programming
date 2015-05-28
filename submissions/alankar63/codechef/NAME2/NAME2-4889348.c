#include<stdio.h>
    #include<string.h>
    int main(){
    int t,l1,l2,i,j,flag;
    char m[50005],w[25005];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
    i=0; j=0; gets(m);
    while(m[i]!=' '){++i;}
    m[i]='\0';
    l1=i;
    ++i;
    while(m[i]){
    w[j]=m[i];
    ++j;
    ++i;
    }
    l2=j;
    w[j]='\0';
    flag=0;
    if(l1<l2){
    for(i=0,j=0;i<l1 && j<l2;){
    if(m[i]==w[j]){
    ++i;
    ++j;
    }
    else{
    ++j;
    }
    }
    if(i==l1){
    flag=1;
    }
    }
    else{
    for(i=0,j=0;i<l1 && j<l2;){
    if(m[i]==w[j]){
    ++i;
    ++j;
    }
    else{
    ++i;
    }
    }
    if(j==l2){
    flag=1;
    }
    }
    if(flag)
    printf("YES\n");
    else
    printf("NO\n");
    }
    return 0;
	}