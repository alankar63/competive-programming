#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char s[400];
int top=-1;


void push(char t)

   {s[++top]=t;
   }


char pop()

   {char m;
    m=s[top--];
    return m;
   }
   int pre(char f)

   {switch(f)

         {case'#':
                 return(1);
          case'+':return(3);break;
          case'-':
                 return(4);
             break;

          case'*':return(5);break;
          case'/':
              return(6);
              break;
          case '(':
               return(2);
               break;
         }

   }
   int main()
{char input[400],postfix[400];
char ch,m,n;
int i=0,k=0,len,test;
scanf("%d",&test);
while(test--)
{scanf("%s",input);top=-1,k=0;
push('#');

int len1,count=0,count1=0,c1=0,c2=0,t,r;
len1=strlen(input);
char e,d;
i=0;
while((ch=input[i++])!='\0')


     {
      if(ch=='(')
          {push(ch);
          }

      else if(ch=='^')
           {

            push(ch);
           }



      else if(isalnum(ch))
          {postfix[k]=ch;
            k++;
          }



      else if(ch==')')
          {while(s[top]!='(')
               {  n=pop();
                 postfix[k]=n;
                 k++;
               }
          m=pop();
          }

      else
          {
                while(pre(ch)<=pre(s[top]))
                     {n=pop();
                      postfix[k]=n;
                      k++;
                     }

                push(ch);

          }}
           while (s[top] != '#')
          postfix[k++] = pop();

  postfix[k] = '\0';
  len=strlen(postfix);
  for(i=0;i<len;i++)
  printf("%c",postfix[i]);
  printf("\n");
  } 
   return 0;}