#include<stdio.h>
int ala(int,int);
int main()
{
int T,i,j,k,A;
char v[251];
scanf("%d",&T);
while(T--)
{
scanf("%d %s",&A,v);
if(A)
{
for(i=0,j=0;v[i];i++)
j=(j*10+v[i]-48)%A;
printf("%d\n",ala(j,A));
}
else
printf("%s\n",v);
}
}
int ala(int A,int B)
{
if(B==0)
return A;
else
return(ala(B,A%B));
}