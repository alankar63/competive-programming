#include<stdio.h>
  #include<string.h>
    #define MAX 100005
    long long int ones[3*MAX+5]={0};
    long long int twos[3*MAX+5]={0};
    long long int flip[3*MAX+5]={0};
    long long int c[100005]={0},d[100005]={0},sum[100005]={0},sums[300005]={0};
    long long int query_tree(long long int node, long long int a, long long int b, long long int i, long long int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return ones[node];
 
	long long int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	long long int q2 = query_tree(1+(node*2), (a+b)/2+1, b, i, j); // Query right child
 
	long long int res =q1+q2; // Return final result
	
	return res;
}
long long int query_tr(long long int node, long long int a, long long int b, long long int i, long long int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return sums[node];
 
	long long int q1 = query_tr(node*2, a, (a+b)/2, i, j); // Query left child
	long long int q2 = query_tr(1+node*2, (a+b)/2+1, b, i, j); // Query right child
 
	long long int res =q1+q2; // Return final result
	
	return res;
}
long long int query_tre(long long int node, long long int a, long long int b, long long int i, long long int j) {
	
	if(a > b || a > j || b < i) return 0; // Out of range
 
	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return twos[node];
 
	long long int q1 = query_tre(node*2, a, (a+b)/2, i, j); // Query left child
	long long int q2 = query_tre(1+(node*2), (a+b)/2+1, b, i, j); // Query right child
 
	long long int res =q1+q2; // Return final result
	
	return res;
}
    void update_tree(long long int node, long long int a, long long int b, long long int i, long long int j, long long int value) {
	long long int temp;
    
	if(a > b || a > j || b < i) 
		return;
    
  	if(a == b) {
		if(value%3==1){
			temp=twos[node];
			twos[node]=ones[node];
			ones[node]=(b-a+1)-temp-ones[node];
			
		}
		else if(value%3==2){
			temp=twos[node];
			twos[node]=(b-a+1)-ones[node]-twos[node];
			ones[node]=temp;
		}
    		//tree[node] += value;
    		return;
	}
 
	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
	ones[node] = ones[node*2]+ones[node*2+1];
	twos[node]=  twos[node*2]+twos[node*2+1];
}
void update_tr(long long int node, long long int a, long long int b, long long int i, long long int j, long long int value) {
    
	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;
    
  	if(a == b) { // Leaf node
    		sums[node] = value;
    		return;
	}
 
	update_tr(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tr(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
 
	sums[node] = (sums[node*2]+sums[node*2+1]); // Updating root with max value
}
    void build_tree(long long int node, long long int a, long long int b) {
  	if(a > b) return; 
  	
  	if(a == b) { 
    		ones[node] = c[a]; 
		return;
	}
	
	build_tree(node*2, a, (a+b)/2); 
	build_tree(node*2+1, (a+b)/2+1, b);
	
	ones[node] = ones[node*2]+ones[node*2+1];
}
void build_tre(long long int node, long long int a, long long int b) {
  	if(a > b) return; 
  	
  	if(a == b) { 
    		twos[node] = d[a]; 
		return;
	}
	
	build_tre(node*2, a, (a+b)/2); 
	build_tre(node*2+1, (a+b)/2+1, b);
	
	twos[node] = twos[node*2]+twos[node*2+1];
}
void build_tr(long long int node, long long int a, long long int b) {
  	if(a > b) return; 
  	
  	if(a == b) { 
    		sums[node] = sum[a]; 
		return;
	}
	
	build_tr(node*2, a, (a+b)/2); 
	build_tr(node*2+1, (a+b)/2+1, b);
	
	sums[node] = sums[node*2]+sums[node*2+1];
}
    long long int main()
    {
    long long int N,Q,x,y,type,i,temp,temp1,temp2,temp3,on,tw,ze,total,final,last1,last2;
    char s[100005];
    scanf("%lld%lld",&N,&Q);
    scanf("%s",s);
    temp1=0;
	 for(i=0;i<N;i++){
		temp=s[i]-48;
		temp1=temp1+temp;
		//build_tr(1, 0, N-1);
		if(temp1%3==2){
			//build_tree(1, 0, N-1);
			c[i]=0;
			d[i]=1;
			
		}
		else if(temp1%3==1){
			c[i]=1;
			d[i]=0;
		}
		else{
			c[i]=0;
			d[i]=0;
		}
	}
	 for(i=0;i<N;i++){
		sum[i]=s[i]-48;
		
	}
		build_tree(1, 0, N-1);
		build_tre(1, 0, N-1);
		build_tr(1, 0, N-1);
	//for(i=1;i<=2*N;i++)
	//	prlong long intf("%d\n",twos[i]);
	//for(i=1;i<2*N;i++)
	//	prlong long intf("%d\n",ones[i]);
	
	
    while(Q--)
    {
 
    total=0;
    scanf("%lld%lld%lld",&type,&x,&y);
    if(type==1){
		last1=final=query_tr(1, 0, N-1, 0,x-1); 
		update_tr(1, 0, N-1,x-1,x-1, y);
		last2=final=query_tr(1, 0, N-1, 0,x-1); 
		//prlong long intf("jd%ddj%d\n",last1,last2);
		
		if(last1<last2)
			update_tree(1, 0, N-1,x-1,N-1,last2-last1); 
		else{
			update_tree(1, 0, N-1,x-1,N-1, last2-last1+3); 
		}
		
		/*for(i=1;i<2*N;i++){
		prlong long intf("%d\n",twos[i]);
	}
	prlong long intf("\n");
	for(i=1;i<2*N;i++){
		prlong long intf("%d\n",ones[i]);
	}*/
		
	}
    else {
		on=query_tree(1, 0, N-1, x-1,y-1);
		tw=query_tre(1, 0, N-1, x-1,y-1);
		ze=y-x+1-on-tw;
		//prlong long intf("%d\n",ze);
		//prlong long intf("%d\n",tw);
		if(x==1){
			total=((on)*(on-1))/2+  ((tw)*(tw-1))/2+  ((ze)*(ze+1))/2;		//prlong long intf("%d\n",ze);
		//prlong long intf("%d\n",on);
		printf("%lld\n",total);
		}
		else{
		//prlong long intf("%d\n",ze);
		//prlong long intf("%d\n",on);
		final=query_tr(1, 0, N-1, 0,x-2);
		//prlong long intf("%d\n",final);
		if(final%3==0)
			ze++;
		if(final%3==1)
			on++;
		if(final%3==2)
			tw++;
		total=((on)*(on-1))/2+  ((tw)*(tw-1))/2+  ((ze)*(ze-1))/2;
		printf("%lld\n",total);
		}
		//total=((on)*(on-1))/2+  ((tw)*(tw-1))/2+  ((ze)*(ze+1))/2;
		//prlong long intf("%d\n",total);
		
	}
    }
    return 0;
    }