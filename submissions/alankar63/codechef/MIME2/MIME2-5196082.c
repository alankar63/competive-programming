#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,i,j;
    char ext[101][15],type[101][51],file[51],*p;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",ext[i]);
        scanf("%s",type[i]);
    }
    while(m--)
    {
        scanf("%s",file);
        /*for(i=strlen(file);i>=0;i--)
            {
                if(file[i]=='.')
                break;
            }*/
                p=strrchr(file,'.');
            if(!p)
                printf("unknown\n");
            else
            {
                for(j=0;j<n;j++)
                    if(strcmp(&p[1],ext[j])==0)
                    {
                        puts(type[j]);
                        break;
                    }
                    if(j==n)
                        printf("unknown\n");
            }
    }
    return 0;
}