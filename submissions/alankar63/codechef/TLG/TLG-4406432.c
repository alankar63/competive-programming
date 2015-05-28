#include<stdio.h>
int main()
   {
   int p1, p2, s1=0,s2=0, n, lead=0, win, i;
   scanf("%d", &n);
   for(i=0; i<n; i++){
      scanf("%d", &p1);
      scanf("%d", &p2);
      s1+=p1;
      s2+=p2;
      if(s1-s2>0 && lead<s1-s2)
          {
           lead=s1-s2;
           win=1;
           }
      if(s2-s1>0 && lead<s2-s1)
           {
            lead=s2-s1;
            win=2;
            }
      }
      printf("%d %d", win, lead);
   return 0;
   }