#include<stdio.h>
 #include<stdlib.h>
 int main()
 {
     int tc,n,i,c,j,min,count;
     scanf("%d",&tc);
     while(tc--)
     {
         count=0;
         scanf("%d",&n);
         int a[n],s[n];
         for(i=0;i<n;i++)
         {
             scanf("%d",&a[i]);
             if(i==0)
             {
                 min=a[i];
             }
             else
             {
                 if(a[i]<min)
                    min=a[i];
             }
         }
         for(i=min;i>0;i--)
         {
             for(j=0;j<n;j++)
             {
                 if(a[j]%i==0)
                 {
                    s[j]=a[j]/i;
                    count++;
                 }
                 else
                 {
                    count=0;
                    break;
                 }
             }
             if(count==n)
                break;
         }
         if(count==n)
         {
            for(i=0;i<n;i++)
               printf("%d ",s[i]);
               printf("\n");
         }
         else
         {
            for(i=0;i<n;i++)
               printf("%d ",a[i]);
               printf("\n");
         }
     }
     return 0;
 }