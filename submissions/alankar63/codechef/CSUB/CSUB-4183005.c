#include<stdio.h>
#include<string.h>
char a[1000001];
int main()
{long long int ans;
long long int test,n,count,i;
scanf("%llu",&test);
while(test--)
{scanf("%llu",&n);
count=0;
scanf("%s",a);
for(i=0;i<n;i++)
{if(a[i]=='1')count++;}
ans=(count*(count+1))/2;
printf("%llu\n",ans);
}
return 0;
}