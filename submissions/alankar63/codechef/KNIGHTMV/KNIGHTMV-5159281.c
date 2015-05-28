#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define getchar getchar//_unlocked
#define M 1000000007
#define x str
 
int getint ()
{
        int  n=0;
        char ch=getchar();
 
        while(ch<'0' || ch>'9')
            ch=getchar();
 
        while(ch>='0' && ch<='9')
        {
                n=n*10+ch-'0';
                ch=getchar();
        }
 
        return n;
 
}
 
 
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
 
 
        unsigned long long div=a,did=b,rem;
 
        while((rem=did%div)!=0)
        {
                did=div;
                div=rem;
 
        }
 
        return div;
 
 
}
 
long long getlonglong ()
{
        long long  n=0;
        char ch=getchar();
 
        while(ch<'0' || ch>'9')
            ch=getchar();
 
        while(ch>='0' && ch<='9')
        {
                n=n*10+ch-'0';
                ch=getchar();
        }
 
        return n;
 
}
 
 
void sort(int a[] ,int start1 ,int end1 ,int start2 ,int end2)
{
 
        int temp[end1-start1 +1 + end2-start2+1 ];
        int i=start1,j=start2,count=0;
 
        while(i<=end1 && j<=end2)
        {
                if(a[i]<=a[j])
                    temp[count++]=a[i++];
                else
                    temp[count++]=a[j++];
 
 
        }
 
        for(;i<=end1;++i)
            temp[count++]=a[i];
 
        for(;j<=end2;++j)
            temp[count++]=a[j];
 
        for(i=0;i<count;++i)
            a[i+start1]=temp[i];
 
 
}
 
void mergesort(int a[] ,int start,int end)
{
        if(start==end)
            return;
 
        int middle =(start+end)/2;
 
        mergesort(a,start,middle);
        mergesort(a,middle+1,end);
        sort(a,start,middle,middle+1,end);
 
}
 
 
long long Ceil(long long a , long long n)
{
        if(a<0)
            return 0;
 
        if(a%n==0)
            return a/n;
        else
            return a/n +1 ;
 
 
}
 
long long Max(long long a ,long long b)
{
 
        if(a>=b)
            return a;
        else
            return b;
 
}
 
long long Abs(long long a)
{
 
        if(a<0)
            return -a;
        else
            return a;
 
}
 
 
void sorttt(int n, int a[n][2])
{
        int i,j,smallest,temp1,temp2;
 
        for(i=0;i<n;++i)
        {
                smallest =i;
 
                for(j=i+1;j<n;++j)
                {
                        if(a[smallest][1] > a[j][1])
                            smallest=j;
 
                }
 
                temp1=a[i][0];
                temp2=a[i][1];
 
                a[i][0]= a[smallest][0];
                a[i][1] = a[smallest][1];
 
                a[smallest][0] =temp1;
                a[smallest][1]=temp2;
 
 
        }
 
 
}
 
int valid(char*x)
{
        //if(('a'<=str[0] && str[0]<='h') && ('1'<=str[1] && str[1]<='8') && (str[2]=='-') && ('a'<=str[3] && str[3]<='h') && ('1'<=str[4] && str[4]<='8') && (str[5]=='\0'))
            
        if(x[5]=='\0'&&isdigit(x[1])!=0&&isdigit(x[4])!=0&&x[2]=='-'&&x[1]>48&&x[4]>48&&x[1]<57&&x[4]<57&&x[0]<105&&x[3]<105&&x[0]>96&&x[3]>96)
            return 1;
        else
            return 0;
 
 
}
 
int validmove(char *str)
{
        int i;
        char moves[9][2];
 
 
        moves[0][0]=str[0]+1;
        moves[0][1]=str[1]+2;
 
        moves[1][0]=str[0]+1;
        moves[1][1]=str[0]-2;
 
        moves[2][0]=str[0]-1;
        moves[2][1]=str[1]-2;
 
        moves[3][0]=str[0]-1;
        moves[3][1]=str[1]+2;
 
        moves[4][0]=str[0]+2;
        moves[4][1]=str[1]-1;
 
        moves[5][0]=str[0]+2;
        moves[5][1]=str[1]+1;
 
        moves[6][0]=str[0]-2;
        moves[6][1]=str[1]-1;
 
        moves[7][0]=str[0]-2;
        moves[7][1]=str[1]+1;
 
        moves[8][0]=str[0];
        moves[8][1]=str[1];
 
        for(i=0;i<9;++i)
            if(str[3]==moves[i][0] && str[4]==moves[i][1])
                    return 1;
 
        return 0;
 
 
}
 
int main()
{
        int t,n,a,b,i,p,nn;
        char x[40];
        t=getint();
 
        while(t--)
        {
                gets(x);
 
                //if(valid(str))
                
                
                if(x[5]=='\0'&&isdigit(x[1])!=0&&isdigit(x[4])!=0&&x[2]=='-'&&x[1]>48&&x[4]>48&&x[1]<57&&x[4]<57&&x[0]<105&&x[3]<105&&x[0]>96&&x[3]>96)
                {
                       /* if(validmove(str))
                            printf("Yes\n");
                        else
                            printf("No\n");*/
 
 
                    	if((x[0]-x[3]==1||x[0]-x[3]==-1)&&(x[1]-x[4]==2||x[1]-x[4]==-2))
                            printf("Yes\n");
                        else if((x[0]-x[3]==2||x[0]-x[3]==-2)&&(x[1]-x[4]==1||x[1]-x[4]==-1))
                            printf("Yes\n");
                        else
                            printf("No\n");
                }
                else
                    printf("Error\n");
 
 
        }
 
        return 0;
 
 
}