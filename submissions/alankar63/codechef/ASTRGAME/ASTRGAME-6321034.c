#include<stdio.h>
    #include<string.h>
    char d[50][50],s[100];
    int t,i,j,k,n,l,g[50][50],temp[100],len[100],le,u,c=0;
    int match(char a[],char b[],int len)
    {
    int i;
    for(i=0;i<len;i++) if(a[i]!=b[i]) return 0;
    return 1;
    }
    int main()
    {
    scanf("%d",&t);
    while(t--)
    {
    scanf("%s",s);
    l=strlen(s);
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%s",d[i]),len[i]=strlen(d[i]);
    for(i=0;i<l;i++) 
     g[i][i]=0;
    for(le=1;le<=l;le++){
    for(i=0;i<=(l-le);i++){
    j=i+le;c++;
    for(k=0;k<n;k++){
    if(len[k]<=le){
    for(u=i;u<=(j-len[k]);u++) if(match(s+u,d[k],len[k])){
    temp[g[i][u]^g[u+len[k]][j]]=c;
    }
    }
    }
    for(k=0;temp[k]==c;k++); g[i][j]=k;
    }
    }
    printf("%s\n",(!g[0][l])?"Tracy":"Teddy");
    }
    return 0;
    }