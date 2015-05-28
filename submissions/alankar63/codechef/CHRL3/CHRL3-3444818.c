#include<stdio.h>
#define SIZE 100001
int main()
{
    int n,i,j,a;
    int arr[SIZE];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        arr[i]=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        j=0;
        while(arr[j]>a)
            j++;
        arr[j++]=a;
    }
    /*printf("\ncheck:");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);*/
    j=0;
    while(arr[j++]!=0);
    printf("%d\n",j-1);
	return 0;
}