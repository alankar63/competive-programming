#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[1000002];
	int test,i,f,fp,l,mid;
	scanf("%d\n",&test);
	while(test--)
	{
		f=1;
		gets(a);
		l=strlen(a);
		fp=0;
		for(i=0;i<l;i++)
		{           
			if(a[i]!='9')
			{
				f=0;
				break;
			} 
		}
		if(f==1)
		{
			a[0]='1';
			for(i=1;i<l;i++)
				a[i]='0';
			a[l]='1';
			a[l+1]='\0';
			fp=1;
		}
		f=0;
		if(fp!=1)
		{
			for(i=0;i<l/2;i++)
			{
				if(a[i]<a[l-1-i])
					f=-1;
				else if(a[i]>a[l-1-i])
					f=1;
				a[l-1-i]=a[i];
			}
			if(l%2==0)
				mid=l/2-1;
			else 
				mid=l/2;
		 
			if(f==0||f==-1)
			{
				i=0;
				while(a[mid-i]=='9')
				{
					a[mid-i]='0';
					a[l-1-mid+i]='0';
					i++;
				}
				a[mid-i]++;
				a[l-1-mid+i]=a[mid-i];
			}
		}
		printf("%s\n",a);
	}
	return 0;
} 