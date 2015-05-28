#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#include<ctype.h>  
#include<stdlib.h>  
#include<time.h>  
#include<assert.h>  
  
#include<vector>  
#include<queue>  
#include<stack>  
#include<map>  
#include<set>  
#include<iostream>  
#include<algorithm>  
#include<string>  
  
using namespace std;  
  
#define FOR(i,n) for(int i=0;i<(n);++i)  
#define REP(i,a,b) for(int i=(a);i<=(b);++i)  
#define CLR(a,x) memset(a,(x),sizeof(a))  
  
#define INF (1<<30)  
  
typedef long long LL;  
typedef pair<int,int> pii;  
  
struct Node {  
    int key;  
    int cnt;  
    int priority;  
  
    Node *left, *right;  
  
    Node(){cnt = 0; priority = 0; left = right = NULL;}  
    Node(int _key){cnt = 1; key = _key; priority = rand(); left = right = NULL;}  
    Node(int _key, int pr){cnt = 1; key = _key; priority = pr; left = right = NULL;}  
}; 

/*

//preprocess create the min array

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

//finding max value
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
*/ 
  
struct Treap {  
    Node* root;  
  
    Treap(){root = NULL; srand(time(NULL));}  
  
    int TreeSize(Node* T)  
    {  
        return T==NULL?0:T->cnt;  
    }  
  
    void UpdateCnt(Node* &T)  
    {  
        if(T)  
        {  
            T->cnt = 1 + TreeSize(T->left) + TreeSize(T->right);  
        }  
    }  
  
    void LeftRotate(Node* &T)  
    {  
        Node* temp = T->left;  
        T->left = temp->right;  
        temp->right = T;  
        T = temp;  
  
        UpdateCnt(T->right);  
        UpdateCnt(T);  
    }  
  
    void RightRotate(Node* &T)  
    {  
        Node* temp = T->right;  
        T->right = temp->left;  
        temp->left = T;  
        T = temp;  
  
        UpdateCnt(T->left);  
        UpdateCnt(T);  
    }  
  
    void Insert(Node* &T, int _key)  
    {  
        if(T == NULL)  
        {  
            T = new Node(_key);  
            return;  
        }  
  
        if(T->key > _key)  
        {  
            Insert(T->left, _key);  
  
            if(T->priority < T->left->priority)  
                LeftRotate(T);  
        }  
        else if(T->key < _key)  
        {  
            Insert(T->right, _key);  
  
            if(T->priority < T->right->priority)  
                RightRotate(T);  
        }  
  
        UpdateCnt(T);  
    }  
  
    void Insert(int _key)  
    {  
        Insert(root, _key);  
    }  
  
    void Delete(Node* &T, int _key)  
    {  
        if(T == NULL)  
            return;  
  
        if(T->key > _key)  
            Delete(T->left, _key);  
        else if(T->key < _key)  
            Delete(T->right, _key);  
        else  
        {  
            if(T->left && T->right)  
            {  
                if(T->left->priority > T->right->priority)  
                    LeftRotate(T);  
                else  
                    RightRotate(T);  
  
                Delete(T, _key);  
            }  
            else  
            {  
                Node* temp = T;  
  
                if(T->left)  
                    T = T->left;  
                else  
                    T = T->right;  
  
                delete temp;  
            }  
        }  
  
  
        UpdateCnt(T);  
    }  
  
    void Delete(int _key)  
    {  
        Delete(root, _key);  
    }  
  
    int Count(Node* T, int bound)  
    {  
        if(T == NULL)  
            return 0;  
  
        if(T->key < bound)  
            return 1 + TreeSize(T->left) + Count(T->right, bound);  
  
        return Count(T->left, bound);  
    }  
  
    int Count(int bound)  
    {  
        return Count(root,bound);  
    }  
  
    int FindKth(Node* T, int k)  
    {  
        if(TreeSize(T) < k)  
            return -INF;  
  
        int sz = 1 + TreeSize(T->left);  
  
        if(sz == k)  
            return T->key;  
  
        if(sz < k)  
            return FindKth(T->right, k-sz);  
  
        return FindKth(T->left,k);  
    }  
  
    int FindKth(int k)  
    {  
        return FindKth(root, k);  
    }  
};  
  
int main()  
{  
    // freopen("in.txt","r",stdin);  
  
    int Q; scanf("%d",&Q);  
  
    Treap oTreap;  
  
    while(Q--)  
    {  
        char t[5];  
        int p;  
        scanf("%s%d",t,&p);  
  
        if(t[0]=='I')  
        {  
            oTreap.Insert(p);  
        }  
        else if(t[0]=='D')  
        {  
            oTreap.Delete(p);  
        }  
        else if(t[0]=='K')  
        {  
            int v = oTreap.FindKth(p);  
  
            if(v > -INF)  
            {  
                printf("%d\n",v);  
            }  
            else  
                puts("invalid");  
        }  
        else  
        {  
            int v = oTreap.Count(p);  
  
            printf("%d\n",v);  
        }  
  
    }  
  
    return 0;  
}