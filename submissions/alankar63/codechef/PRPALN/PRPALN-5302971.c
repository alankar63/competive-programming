#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char a[100002];
int main()
{long long int i, t,u,l,r,val,q,len,flag,j,m;
scanf("%llu",&t);
while(t--)
{flag=1;
    scanf("%s",a);
    len=strlen(a);
   // printf("%llu\n",len);
    i=0;j=len-1;
   // printf("%c\n",a[1]);
    if(a[i]!=a[j])
    {i=0;j=len-2;
    while(i<j)
    {
        if(a[i]!=a[j])
        {

         flag=0;break;
        }
        i++;j--;
    }
    if(flag)
    {printf("YES\n");continue;}
    flag=1;
    i=1;j=len-1;
     while(i<j)
    {
        if(a[i]!=a[j])
        {

         flag=0;break;
        }i++;j--;
    }
    if(flag)
    {printf("YES\n");continue;}

    printf("NO\n");
    }
    else
    {i=0;j=len-1;
      flag=0;
      while(i<j)
      {
          if(a[i]!=a[j])
          {
              flag=1;break;
          }
          i++;j--;
      }
      if(flag==0)
      {
         printf("YES\n");continue;
      }
      l=i;m=j-1;
       while(l<m)
    {
        if(a[l]!=a[m])
        {

         flag=0;break;
        }
        l++;m--;
    }
    if(flag)
    {printf("YES\n");continue;}


      flag=1;
      l=i+1;m=j;
       while(l<m)
    {
        if(a[l]!=a[m])
        {

         flag=0;break;
        }
        l++;m--;
    }
    if(flag)
    {printf("YES\n");continue;}
        printf("NO\n");
    }

}
    return 0;
}