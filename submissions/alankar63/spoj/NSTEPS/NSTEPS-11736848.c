#include<stdio.h>
#include<stdlib.h>
int main()
{int a,b,c,d;
scanf("%d",&a);
while(a--)
{scanf("%d %d",&b,&c);
if(b==c)
{if(b%2==0){printf("%d\n",2*b);continue;}
else {printf("%d\n",2*b-1);continue;}
}
else if(c==(b-2))
{if(c%2==0){printf("%d\n",(2*c)+2);continue;}
else {printf("%d\n",(2*c)+1);continue;}

}
else
   printf("No Number\n");

}


return 0;
}



