#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ll long
void prod_mat( ll double a[28][28], ll double b[28][28]);
void fast_square(long long int k);
void copy_m(long long int n);

/*inline int inp()
{
    int h=0,sign=1;
    char c;
    c=gc();
    while(c<'0' || c>'9')
        {if(c=='-')	sign=-sign;
            c=gc();
    }
    while(c>='0' && c<='9')
    {
        h=(h<<3)+(h<<1)+c-'0';


        c=gc();
    } h=h*sign;

     return h;
}
*/
 ll double inp_mat[28][28], M[28][28];

void prod_mat( ll double a[28][28], ll double b[28][28])

{
    ll double c[28][28],sum=0;
    int i,j,k;
    for(i=0;i<26;i++)
      for(j=0;j<26;j++)
           c[i][j]=0;
    for(i=0;i<26;i++){
      for(j=0;j<26;j++){
           sum=0;
           for(k=0;k<26;k++)//t
               sum=sum+a[i][k]*b[k][j];
           c[i][j]=sum;
      }
      }

	for(i=0;i<26;i++)
      		for(j=0;j<26;j++)
			inp_mat[i][j]=c[i][j];

}

void fast_square(long long int k)
{
    if (k == 0 ||k == 1)
        return;
    fast_square(k/ 2);
    prod_mat(inp_mat, inp_mat);
    if (k % 2 != 0)
        prod_mat(inp_mat, M);
}
void copy_m(long long int n)
{
    int i,j;
    for(i=0;i<26;i++)//t
	for(j=0;j<26;j++)//t
		M[i][j]=inp_mat[i][j];

    fast_square(n);
}

int main()
{int test;
	long long int n,k,i,j,len1,len2,value,hash__map,total[100000]={0};
   ll double sum,mul;
	char s[5],s_2[5];
	scanf("%d",&test);
	while(test--)
    {
        for(i=0;i<100000;i++)
			total[i]=0;
		scanf("%llu%llu",&n,&k);
		scanf("%s",s);
		len1=strlen(s);
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)//t
				scanf("%Lf",&inp_mat[i][j]);
				copy_m(k);
		sum=0;
		for(i=0;i<n;i++){
			value=0;
			mul=1;
			scanf("%s",s_2);
			len2=strlen(s_2);
			j=0;
			if(len1==len2){
				j=0;
				hash__map=1;
				while(s_2[j]!='\0'){
					value=value+s_2[j]*hash__map;
					hash__map=hash__map*26;//hash mapping is used
					mul=mul*inp_mat[s[j]-97][s_2[j]-97];
					j++;
				}
				if(total[value]==0){
				sum=sum+mul;
				total[value]=1;
				}
			}
		}
		printf("%Lf\n",sum);
    }
    return 0;
}