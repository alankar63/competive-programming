#include<stdio.h>
#include<stdlib.h>
int a;
int main()
{
for(;;)
{
scanf("%d",&a);
if(a==42)
exit(0);
else
printf("%d\n",a);


}


return 0;
}
