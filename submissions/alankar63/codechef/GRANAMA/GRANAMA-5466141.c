#include<string.h>
#include<stdio.h>
#define MAX 1001
int main()
{
    char x[MAX],y[MAX];
    int t,a[26],b[26],i,l1,l2,f;
    scanf("%d",&t);
    while(t--)
    {
              f=1;
              scanf("%s",x);
              scanf("%s",y);
              l1=strlen(x);
              l2=strlen(y);
              for(i=0;i<26;i++)
              {
              a[i]=0;
              b[i]=0;
              }
              for(i=0;i<l1;i++)
              a[x[i]-'a']++;
              for(i=0;i<l2;i++)
              b[y[i]-'a']++;
              for(i=0;i<26;i++)
              {
              if(a[i]==b[i])
              continue;
              if((a[i]==0&&b[i]!=0)||(a[i]!=0&&b[i]==0))
              {
              f=2;
              break;
              }
              else
              f=0;
              }
              if(f)
              printf("YES\n");
              else
              printf("NO\n");
    }
    return 0;
}