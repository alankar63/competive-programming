#include<stdio.h>
//#include<conio.h>
int main()
{
  int n,m,j;
 // clrscr();
  //printf("Enter any number between 1 to 99 : ");
  scanf("%d",&n);
  //printf("You entered ");
  if(n==0)
    printf("zero");
  else
  {
      if((n%10)!=0)
      {
         if(n>0&&n<=10)
     goto one;
  else if (n>10&&n<20)
       {
      m=n%10;
      goto two;
       }
       else if(n>20&&n<100)
        {
           j=n/10;
           n=n%10;
           goto three;
        }
 two:
 switch(m)
{
 case 1:printf("eleven");
        goto w3;
 case 2:printf("twelve");
        goto w3;
 case 3:printf("thirteen");
        goto w3;
 case 4:printf("fourteen");
        goto w3;
 case 5:printf("fifteen");
        goto w3;
 case 6:printf("sixteen");
        goto w3;
 case 7:printf("seventeen");
        goto w3;
 case 8:printf("eighteen");
        goto w3;
 case 9:printf("nineteen");
        goto w3;
}
 three:
 switch(j)
{
 case 2:printf("twenty-");
        goto one;
 case 3:printf("thirty-");
        goto one;
 case 4:printf("forty-");
        goto one;
 case 5:printf("fifty-");
        goto one;
 case 6:printf("sixty-");
        goto one;
 case 7:printf("seventy-");
        goto one;
 case 8:printf("eighty-");
        goto one;
 case 9:printf("ninety-");
        goto one;
}
 one:
 switch(n)
{
 case 1:printf("one");
        break;
 case 2:printf("two");
        break;
 case 3:printf("three");
        break;
 case 4:printf("four");
        break;
 case 5:printf("five");
        break;
 case 6:printf("six");
        break;
 case 7:printf("seven");
        break;
 case 8:printf("eight");
        break;
 case 9:printf("nine");
        break;
 case 10:printf("ten");
        break;
}

      }
  else
  {



  if(n>0&&n<=10)
     goto one1;
  else if (n>10&&n<20)
       {
      m=n%10;
      goto two1;
       }
       else if(n>=20&&n<100)
        {
           j=n/10;
           n=n%10;
           goto three1;
        }
 two1:
 switch(m)
{
 case 1:printf("eleven");
        break;
 case 2:printf("twelve");
        break;
 case 3:printf("thirteen");
        break;
 case 4:printf("fourteen");
        break;
 case 5:printf("fifteen");
        break;
 case 6:printf("sixteen");
        break;
 case 7:printf("seventeen");
        break;
 case 8:printf("eighteen");
        break;
 case 9:printf("nineteen");
        break;
}
 three1:
 switch(j)
{
 case 2:printf("twenty");
        goto one1;
 case 3:printf("thirty");
        goto one1;
 case 4:printf("forty");
        goto one1;
 case 5:printf("fifty");
        goto one1;
 case 6:printf("sixty");
        goto one1;
 case 7:printf("seventy");
        goto one1;
 case 8:printf("eighty");
        goto one1;
 case 9:printf("ninety");
        goto one1;
}
 one1:
 switch(n)
{
 case 1:printf("one");
        break;
 case 2:printf("two");
        break;
 case 3:printf("three");
        break;
 case 4:printf("four");
        break;
 case 5:printf("five");
        break;
 case 6:printf("six");
        break;
 case 7:printf("seven");
        break;
 case 8:printf("eight");
        break;
 case 9:printf("nine");
        break;
 case 10:printf("ten");
        break;
}
}
  }
//getch();goto w3;
w3:return 0;
}