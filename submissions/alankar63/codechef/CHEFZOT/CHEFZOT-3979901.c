#include<stdio.h>
int main()
{long long int i,j,k=0,best=0;
scanf("%llu",&i);
int  *a=malloc(i*sizeof(int));
for(j=0;j<i;j++)
{
scanf("%d",&a[j]);
}
for(j=0;j<i;j++)
{
 if(a[j]!=0)
 k=k+1;
 else
   {if(k>best)
     {best=k;}
     
   k=0;
   }
 
}if(k>best)
     {best=k;}
printf("%llu",best);
 
return 0;
}