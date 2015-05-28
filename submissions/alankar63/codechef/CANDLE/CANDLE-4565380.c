#include<stdio.h>
int main()
{
    int i,j,k,l,n,arr[10],min,pos;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
                    min=10;
                    scanf("%d",&arr[0]);
                    for(j=1;j<10;j++)
                    {
                                     scanf("%d",&arr[j]);
                                     if(arr[j]<min)
                                    { min=arr[j];
                                      pos=j;
                                      }
                          }
                      if(arr[0]<min)
                      {
                         printf("1");
                         for(j=0;j<=arr[0];j++)
                         printf("0");
                         printf("\n");
                         }
                        else
                        {
                            for(j=0;j<=min;j++)
                            printf("%d",pos);
                            printf("\n");
                            }
                            }
         return 0;
         }