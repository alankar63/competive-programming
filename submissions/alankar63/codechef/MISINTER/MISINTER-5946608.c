#include<stdio.h>
#define MOD 1000000007
int main(){
       int t;
       scanf("%d",&t);
       while(t--){
                  int n;
                  long long int p=1;
                  scanf("%d",&n);
                  int i,j=1,a[n],x,c=0;
                  for(i=2;i<=n;i=i+2)
                  a[j++]=i;
                  for(i=1;i<=n;i=i+2)
                  a[j++]=i;
                  
                  i=1;
                  sos:
                           while(a[i]>0)
                           {
                                         x=a[i];
                                         a[i]=0;
                                         i=x;
                                         }
                                         c++;
                                         for(j=1;j<=n;j++){
                                         if(a[j]!=0){
                                                     i=j;
                                                     break;
                                                     }}
                                                     if(j<=n)
                                                     goto sos;
                                                     else {
                                                          for(i=0;i<c;i++){
                                                          p=p*26;
                                                          p=p%MOD;
                                                          }
                                                     printf("%lld\n",p);}
                                                     }return 0;
                                                     }