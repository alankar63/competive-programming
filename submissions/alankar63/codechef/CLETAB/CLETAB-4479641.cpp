#include<stdio.h>
#include<stdlib.h>
#define gc getchar_unlocked


inline int inp(){
	int h=0,sign=1;
	char c;
	c=gc();

	while(c<'0' || c>'9'){
		c=gc();
	}
	while(c>='0' && c<='9'){
		h=(h<<3)+(h<<1)+c-'0';
		c=gc();
	}
	//n=n*sign;
	return h;
}


int main()
{int test,n,m,table[201],per[401],total=0,emp_tab=1,ord_com[401],already[401],tab[201],j,min,tabne,i,d,k,l;
//n=no of tables
//m=total orders
//table[]=occupied or not
//per[]=priority order
//total=answer
//emptab=next empty table
//ordcom[]=order of coming
//already[]=person seated or  not
//tab[]=who is seating on table
//min=min priority
//tabne=which table is now empty
//scanf("%d",&test);
  test=inp();
  while(test--)
  {total=0;
  emp_tab=1;//next empty seat
     n=inp();
     m=inp();
   //scanf("%d",&n);scanf("%d",&m);
      for(i=1;i<=400;i++)
   {
       per[i]=0;already[i]=0;
   }
 for(i=1;i<=200;i++)
 {table[i]=0;
 tab[i]=0;

 }
      for(i=1;i<=m;i++)
      {//scanf("%d",&d);
          d=inp();
          ord_com[i]=d;//order of entry
          per[d]=per[d]+1;
      }


      for(i=1;i<=m;i++)
      {
          if(already[ord_com[i]]==0)//person is not seated already
          {if(emp_tab!=(n+1))//table is empty
            {
               tab[emp_tab] =ord_com[i];//who is sitting on that table
               per[ord_com[i]]=per[ord_com[i]]-1;//priority order subtracted
               total=total+1;//actual ans
               table[emp_tab]=1;//this table is now occupied
               already[ord_com[i]]=1;//person occupies this 400
               emp_tab=emp_tab+1;
             //  for(l=1;l<=n;l++)
             //  printf("%d ",tab[l]);
             //  printf("\n");
            }
            else  //table not empty
            {min=-1;tabne=1;
            for(j=1;j<=n;j++)
            {
                if(per[tab[j]]==0)
                {
                    tabne=j;break;
                }

            else
                {
                    for(k=i;k<=m;k++)
                    {    if(ord_com[k]==tab[j])
                             {
                                 if(k>=min)
                                 {
                                     min=k;tabne=j;
                                 }break;
                             }
                    }

            //this seat is empty
                }
            }
             per[ord_com[i]]--;//priority subtracted
              already[ord_com[i]]=1;//this person sits
              already[tab[tabne]]=0;//person removed
              total=total+1;
              tab[tabne]=ord_com[i];
           //    for(l=1;l<=n;l++)
            //   printf("%d ",tab[l]);
            //   printf("\n");

            }

          }
          else   //person seated already
          {
              per[ord_com[i]]=per[ord_com[i]]-1;//priority order subtracted
            //   for(l=1;l<=n;l++)
             //  printf("%d ",tab[l]);
             //  printf("\n");

          }
      }
     printf("%d\n",total) ;
  }
    return 0;
}