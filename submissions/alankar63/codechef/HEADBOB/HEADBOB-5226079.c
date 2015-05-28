#include<stdio.h>
char str[100000];
int main()
{
int t,a,b,c,n,i;
scanf("%d",&t);
while(t--){
scanf("%d",&n);
scanf("%s",str);
a=b=c=0;
for(i=0;i<n;i++)
{
if(str[i]=='N')
a=1;
else if(str[i]=='Y')
b=1;
else
c=1;
}
if(c==1)
printf("INDIAN\n");
else if(b==1)
printf("NOT INDIAN\n");
else if(a==1 && b==1)
printf("NOT INDIAN\n");
else
printf("NOT SURE\n");
}
return 0;
}