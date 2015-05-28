#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//flag 0->odd level black
//flag 1->odd level red
long long int level(long long int a)
{long long int t=1,i,j;
    if (a==1)
        return 1;

     while(a>1)
     {
         a=a/2;
         t++;
     }
     return t;


}
//root is black and flag=0;
//black =1;red=0;
int main()
{ int t;
long long int x,y,i,j,conunt;
char p[4],ch;
int flag=0;
scanf("%d",&t);
while(t--)
{scanf("%c",&ch);
     conunt=0;
   scanf("%s",p);
   if(p[1]=='i')
   { // printf("%d",flag);
       if(flag)
        flag=0;
       else
        flag=1;
      // printf("%d",flag);
   }
   else if(p[1]=='r')//case red
   {//printf("red");
       scanf("%llu%llu",&x,&y);
       i=level(x);
       j=level(y);
      // printf("%llu%llu%llu%llu",x,y,i,j);
       if(flag==0)//even level red
       {if((x==y)&&((i&1)==0))
        {
            printf("1\n");
            continue;
        }
        if((x==y)&&((i&1)==1))
        {
            printf("0\n");
            continue;
        }


           while(x!=y)
           {
              if(i>j)
              {
                  x=x/2;
                  if((i&1)==0)
                    conunt++;
                  i=i-1;
              }
              else
              {
                   y=y/2;
                  if((j&1)==0)
                    conunt++;
                  j=j-1;
              }
           }
           if((i&1)==0)conunt++;
           printf("%llu\n",conunt);
       }
       else//odd level red
       {if((x==y)&&((i&1)==0))
        {
            printf("0\n");
            continue;
        }
        if((x==y)&&((i&1)==1))
        {
            printf("1\n");
            continue;
        }

          while(x!=y)
           {
              if(i>j)
              {
                  x=x/2;
                  if((i&1)==1)
                    conunt++;
                  i=i-1;
              }
              else
              {
                   y=y/2;
                  if((j&1)==1)
                    conunt++;
                  j=j-1;
              }
           }
            if((i&1)==1)conunt++;
           printf("%llu\n",conunt);
       }

   }
   else//case black
   {
      scanf("%llu%llu",&x,&y);
      i=level(x);
       j=level(y);
       if(flag==0)//odd level black
       {if((x==y)&&((i&1)==0))
        {
            printf("0\n");
            continue;
        }
        if((x==y)&&((i&1)==1))
        {
            printf("1\n");
            continue;
        }

           while(x!=y)
           {
               if(i>j)
              {
                  x=x/2;
                  if((i&1)==1)
                    conunt++;
                  i=i-1;
              }
              else
              {
                   y=y/2;
                  if((j&1)==1)
                    conunt++;
                  j=j-1;
              }
           }
            if((i&1)==1)conunt++;
           printf("%llu\n",conunt);
       }
       else//even level black
       {if((x==y)&&((i&1)==0))
        {
            printf("1\n");
            continue;
        }
        if((x==y)&&((i&1)==1))
        {
            printf("0\n");
            continue;
        }


           while(x!=y)
           {
              if(i>j)
              {
                  x=x/2;
                  if((i&1)==0)
                    conunt++;
                  i=i-1;
              }
              else
              {
                   y=y/2;
                  if((j&1)==0)
                    conunt++;
                  j=j-1;
              }
           }
            if((i&1)==0)conunt++;
           printf("%llu\n",conunt);
       }
   }
}
    return 0;
}