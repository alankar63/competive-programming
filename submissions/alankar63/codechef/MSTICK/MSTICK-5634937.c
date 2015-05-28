//use of rmq

#include<stdio.h>
#include<math.h>
#define MAX 100000
#define SQRTMAX 317
 
long min[SQRTMAX], max[SQRTMAX], b[MAX];
int size, n;
 
void preProcess(int n){
	int i=0, j=0, k=0;
	long minimum, maximum;
	
	size = sqrt(n);
	//printf("size = %d\n",size);
	while(j<size){
		minimum = maximum = b[i];
		for(k=0 ; k<size ; k++){
			if(minimum>b[i])
				minimum = b[i];
			if(maximum<b[i])
				maximum = b[i];
			i++;
		}
		min[j] = minimum;
		max[j] = maximum;
		j++;
	}
}
long findMin(int l, int r){
	int j, j2;
	long minimum = b[l];
 
	j = l/size + 1;
	j2 = r/size - 1;
 
	//printf("j= %d and j2 = %d\n", j,j2);
	while(l<j*size && l<=r){
		if(minimum > b[l]){
			minimum = b[l];
			
		}
		//printf("Checked for %d\n", l);
		l++;
	}
	while(j<=j2 && l<=r && j<size){
		if(minimum > min[j])
			minimum = min[j];
		l = (j+1)*size;
		//printf("Checked for %d  <-->  %d\n", j*size, l-1);
		j++;
	}
	while(l<=r){
		if(minimum > b[l]){
			minimum = b[l];
		}
		//printf("Checked for %d\n", l);
		l++;
	}
	return minimum;
}
long findMax(int l, int r){
	int j, j2;
	long maximum = b[l];
 
	j = l/size + 1;
	j2 = r/size - 1;
 
	//printf("j= %d and j2 = %d\n", j,j2);
	while(l<j*size && l<=r){
		if(maximum < b[l]){
			maximum = b[l];
			
		}
		//printf("Checked for %d\n", l);
		l++;
	}
	while(j<=j2 && l<=r && j<size){
		if(maximum < max[j])
			maximum = max[j];
		l = (j+1)*size;
		//printf("Checked for %d  <-->  %d\n", j*size, l-1);
		j++;
	}
	while(l<=r){
		if(maximum < b[l]){
			maximum = b[l];
		}
		//printf("Checked for %d\n", l);
		l++;
	}
	return maximum;
}
void printOutput(int l, int r){
	double minIn, maxIn=-1, maxOut=-1, maximum=-1, temp=-1;
 
	minIn = findMin(l,r);
	maxIn = findMax(l,r);
	if(l>0){
		maxOut = findMax(0,l-1);
		//printf("Hello findMax(0,%d) = %ld\n",l-1, maxOut);
	}
	if(r+1 <= n-1){
		temp = findMax(r+1,n-1);
		if(temp > maxOut)
			maxOut = temp;
	}
	//printf("maxOut = %ld, maxIn = %ld, minIn = %ld\n", maxOut, maxIn, minIn);
	maximum = (maxIn - minIn)/2;
	if(maxOut > maximum)
		maximum = maxOut;
	printf("%.1lf\n", maximum + minIn);
}
int main(){
 
	int q, l, r, i; 
 
	scanf("%d",&n);
	for (i = 0; i < n; i++)
		scanf("%ld",&b[i]);
	
	preProcess(n);
 
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&l,&r);
		printOutput(l,r);
	}
	
	//printf("%d\n",(int)ceil(1/3)    );
	return 0;
}