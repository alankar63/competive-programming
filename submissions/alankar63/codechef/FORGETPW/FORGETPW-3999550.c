#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define x 1000001
char a[2][94],s[x];
int main()
{long int t,n,i,len=0,j,k,m,f,g,h,z;

scanf("%ld",&t);
while(t--)
{scanf("%ld",&n);k=f=h=z=0;
for(i=0;i<n;i++)
{scanf("%c",&a[0][i]);if(a[0][i]=='\n')scanf("%c",&a[0][i]);
scanf("%c",&a[1][i]);if(a[1][i]==' ')scanf("%c",&a[1][i]);

}
scanf("%s",s);
len=strlen(s);m=len;
for(i=0;i<len;i++)
{for(j=0;j<n;j++)
{if(s[i]==a[0][j])
{
s[i]=a[1][j];break;
}
}

}
for(i=0;i<len;i++)
{
    if(s[i]!='0'&&s[i]!='.')
    {
    z=1;break;
    }
}
if(z==0)
{
    printf("0\n");continue;
}

for(i=0;i<len;i++)
{if(s[i]!='0')
  {k=i;break;}
}
for(i=0;i<len;i++)
{if(s[i]=='.'){m=i,f=1;break;}
}
if(f==1)
{for(i=len-1;i>m;i--)
{
if(s[i]!='0'){g=i,h=1;break;}


}
}if(h==1)
{for(i=k;i<=g;i++)
printf("%c",s[i]);
printf("\n");}
else
{for(i=k;i<m;i++)
printf("%c",s[i]);
printf("\n");}
}

return 0;
}