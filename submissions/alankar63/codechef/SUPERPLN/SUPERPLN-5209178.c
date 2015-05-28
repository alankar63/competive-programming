#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<stdio.h>
 
typedef struct flights
{ int c1,t1,c2,t2;
} flight;
 
flight f[100000];
   
int sort_func(const void *a, const void *b);
 
int sort_func(const void *a, const void *b)
{
    flight c=*(flight*)a,d=*(flight*)b;
    if(c.c1 > d.c1)
    return(1);
    else if((c.c1==d.c1)&&(c.t1>d.t1))
    return(1);
    else
    return(-1);
}
 
int find(int c, int t,int no_of_flights)
{
    int low=0,up=(no_of_flights)-1,mid;
    while(low<=up)
    {    mid=(low+up)/2;
    
            if((f[mid].c1==c)&&(f[mid].t1>=t)&&((mid==0)||(f[mid-1].c1!=c)||(f[mid-1].t1<t)))
            { return(mid);
            }
            else if((f[mid].c1<c)||((f[mid].c1==c)&&(f[mid].t1<t)))
            { low=mid+1;
            }
            else
            { up=mid-1;
            }
    }
    return(-1);
}
                        
    
 
int main()
{
    int tc,no_of_flights,flag,flags[100000],count=0,i,t,c,st,t_st,dest,t_dest,temp;
    scanf("%d",&tc);
    
    while(tc--)
    {
               scanf("%d",&no_of_flights);
               for(i=0;i<no_of_flights;i++)
                scanf("%d%d%d%d",&f[i].c1,&f[i].t1,&f[i].c2,&f[i].t2);
               
               qsort((void*)f,no_of_flights,sizeof(flight),sort_func);
               
               scanf("%d%d%d%d",&st,&t_st,&dest,&t_dest);
               
               c=st;
               t=t_st;
               flag=1,count=0;
               memset((void*)flags,0,sizeof(flags));
               
               while((c!=dest)||((c==dest)&&(t_dest<t)))
               {temp=find(c,t,no_of_flights);
                if((temp==-1)||(flags[temp]))
                { printf("No\n");
                  flag=0;
                  break;
                }
                c=f[temp].c2;
                t=f[temp].t2;
                flags[temp]=1;
                count++;
               }
               if(flag==1)
               { printf("Yes %d\n",count);
               }
               
    }
    
    
    return(0);
}