long long x,sum=0,left;
long n,a[1000000];
void merger(long *left,long *right,long *a,long n1,long n2)
{
    long k=0,i=0,j=0;
 
    while(i<n1&&j<n2)
    {
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
 
 
        }
        else
        {
            a[k]=right[j];
            //counter=counter+n1-i;
            j++;
            //counter++;
 
        }
        k++;
    }
    while(i<n1)
        a[k++]=left[i++];
    while(j<n2)
        a[k++]=right[j++];
 
}
void mergesort(long *a,long n)
{
    long mid,*left,*right,i;
    if(n<2)
        return;
    else
    {
        mid=n/2;
        left=(long *)calloc(mid,sizeof(long));
        right=(long *)calloc(mid+1,sizeof(long));
        for(i=0;i<mid;i++)
            left[i]=a[i];
        for(i=mid;i<n;i++)
            right[i-mid]=a[i];
        mergesort(left,mid);
        mergesort(right,n-mid);
        merger(left,right,a,mid,n-mid);
        free(left);
        free(right);
 
    }
}
int main()
{
    long i,fail,k=0,d,j;
    scanf("%ld%lld",&n,&x);
 
    for(i=0;i<n;i++)
       {
           scanf("%ld",&a[i]);
           sum+=(long long )a[i];
       }
       if(sum<=x)
        printf("0 %ld\n",n);
       else
       {
         mergesort(a,n);
        /* for(i=0;i<n;i++)
       {
           printf("%ld",a[i]);
       }*/
         //sum=a[0];
         sum=0;
         for(i=0;i<n;i++)
            {
                d=(a[i]%2)?a[i]/2+1:a[i]/2;
                sum+=(long long)d;
                a[i]-=d;
                 if(sum>x) {
                        //flag=1;
                        a[i]+=d;
                        //d=0;
                        break;
                 }
            }
            if(i==n)
                d=0;
            //if(flag)
            left=x-(sum-(long long)d);
            //else left=x-sum;
            fail=n-(i);
        for(j=0;j<i;j++)
        {
            left-=(long long)a[j];
            if(left<0)
            {
                break;
            }
        }
 
 
 
 
        printf("%ld %ld\n",fail,j);
 
 
       }
return 0;
}