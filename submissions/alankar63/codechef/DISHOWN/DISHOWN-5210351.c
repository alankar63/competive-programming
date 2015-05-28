#include<stdio.h>
#include<stdlib.h>
 
//#define getchar_unlocked gc
 
int input()
{
    int n=0;
    char c=getchar_unlocked();
    while(c < '0' || c >'9') {c=getchar_unlocked();}
    while(c>='0' && c<='9')
    {
        n=(n<<3)+(n<<1)+c-'0';
        c=getchar_unlocked();
    }
    return n;
}
 
void output(int n)
{
	if(n<0)
	{  n=-n;
	   putchar_unlocked('-');
	}
	int i=10;char output_buffer[11];
	output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';n/=10;}
	while(n);
	do{putchar_unlocked(output_buffer[i]);}
    while(++i<11);
}
 
int main()
{
    int t;
    int n,q,type,x,y;
    int ownerX, ownerY;
    int score[10001],owner[10001];
    int i,j,own;
    t=input();
    while(t--)
    {
        n = input();
 
        for(i=1;i<=n;i++)
        {
            score[i] = input();
            owner[i] = i;
        }
        q = input();
        while(q--)
        {
            type = input();
            x = input();
            ownerX=owner[x];
            while(ownerX != owner[ownerX])
            {
                ownerX =owner[ownerX];
            }
            owner[x] = ownerX;
            if(type == 0)
            {
                y = input();
                ownerY=owner[y];
                while(ownerY != owner[ownerY])
                {
 
                    ownerY =owner[ownerY];
                }
                owner[y] = ownerY;
 
                if(ownerX == ownerY)
                {
                    putchar_unlocked('I');putchar_unlocked('n');putchar_unlocked('v');
                    putchar_unlocked('a');putchar_unlocked('l');putchar_unlocked('i');
                    putchar_unlocked('d');putchar_unlocked(' ');putchar_unlocked('q');
                    putchar_unlocked('u');putchar_unlocked('e');putchar_unlocked('r');
                    putchar_unlocked('y');putchar_unlocked('!');putchar_unlocked('\n');
                }
 
                else
                {
                    if(score[ownerX] > score[ownerY])
                    {
                        owner[ownerY] = ownerX;
                    }
                    else if(score[ownerX] < score[ownerY])
                    {
                        owner[ownerX] = ownerY;
                    }
 
 
                }
 
            }
            else
            {
 
                output(ownerX);
            }
        }
    }
 
    return 0;
}