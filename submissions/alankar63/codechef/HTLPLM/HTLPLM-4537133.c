#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,t,n,q,*ts,*te,flag=0;
    long long int num;
    scanf("%d",&t);
    for(i=0;i<t;i++){
            scanf("%d%d",&n,&q);
            long long int ts[n];
            long long int te[n];
            for(j=0;j<n;j++){
                scanf("%llu%llu",&ts[j],&te[j]);
            }
            for(j=0;j<q;j++){
                scanf("%llu",&num);
                flag=0;
                for(k=0;k<n;k++){
                    if(ts[k]<=num && num<=te[k]){
                        printf("NO\n");
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    printf("YES\n");
                }
            }
    }
    return 0;
}