#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
 
void merge(int a[][2],int b[][2],int c[][2],int q,int r)
{
    int i=0,j=0,k=0;
    while(j<q&&k<r)
    {
        if(a[j][0]<b[k][0])
        {
            c[i][0]=a[j][0];
            c[i++][1]=a[j++][1];
        }
        else if(b[k][0]==a[j][0])
        {
 
            if(b[k][1]<a[j][1])
            {
                 c[i][0]=a[j][0];
            c[i++][1]=a[j++][1];
            }
            else if(b[k][1]>=a[j][1])
            {
                c[i][0]=b[k][0];
            c[i++][1]=b[k++][1];
            }
        }
        else
        {
            c[i][0]=b[k][0];
            c[i++][1]=b[k++][1];
        }
 
 
 }
 while(j<q)
 {
      c[i][0]=a[j][0];
            c[i++][1]=a[j++][1];
 }
 
    while(k<r)
    {
       c[i][0]=b[k][0];
            c[i++][1]=b[k++][1];
    }
}
 
 
void mergesort(int a[][2],int n)
{
    if(n>1)
       {
           int b[n][2];
           int i=n/2,j;
           mergesort(a,i);
           mergesort(a+i,n-i);
           merge(a,a+i,b,i,n-i);
           for(j=0;j<n;j++)
           {
               a[j][0]=b[j][0];
               a[j][1]=b[j][1];
           }
       }
}
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
     printf("\n");
     int n,i,j;
     scanf("%d",&n);
     int a[n][2];
     for(i=0;i<n;i++)
        scanf("%d %d",&a[i][0],&a[i][1]);
     /*for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
     {
         if(a[j][0]>a[j+1][0])
         {
             int temp;
             temp=a[j][0];
             a[j][0]=a[j+1][0];
             a[j+1][0]=temp;
             temp=a[j][1];
             a[j][1]=a[j+1][1];
             a[j+1][1]=temp;
         }
         if(a[j][0]==a[j+1][0])
            if(a[j][1]<a[j+1][1])
          {
             int temp;
             temp=a[j][0];
             a[j][0]=a[j+1][0];
             a[j+1][0]=temp;
             temp=a[j][1];
             a[j][1]=a[j+1][1];
             a[j+1][1]=temp;
         }
     }*/
     mergesort(a,n);
         double dis=0;
 
         /*for(i=0;i<n;i++)
            printf("%d %d\n",a[i][0],a[i][1]);*/
         for(i=0;i<n-1;i++)
            dis=dis+sqrt((a[i][0]-a[i+1][0])*(a[i][0]-a[i+1][0])+(a[i][1]-a[i+1][1])*(a[i][1]-a[i+1][1]));
         printf("%.2lf\n",dis);
 
    }
 
}