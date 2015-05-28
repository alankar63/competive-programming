#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;
long int N,M;

typedef struct edge{
    vector<long int>real;
    vector<long int>imag;
}edge;



void bfs(int *dp,edge *_edge)
{


    long int temp,i,temp2;
    queue<long int> q;
    dp[1] = 0;
    q.push(1);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

         if(!_edge[temp].real.empty())
        for(i=0;i<_edge[temp].real.size();i++)
        {
            temp2 = _edge[temp].real[i];
            if(dp[temp] <dp[temp2]  || dp[temp2] == -1)
               {
                 dp[temp2]= dp[temp];
                  q.push(temp2);
               }


        }



         if(!_edge[temp].imag.empty())
        for(i=0;i<(_edge[temp].imag.size());i++)
        {
            temp2 = _edge[temp].imag[i];
            if(dp[temp]+1 <dp[temp2] || dp[temp2] == -1)
             {
                 dp[temp2]= dp[temp]+1;
                 q.push(temp2);
             }

        }




    }


}

int main(){
	long int i,temp1,temp2,count=0,j;

	scanf("%d %d",&N,&M);

    int dp[N+1];

    edge _edge[N+1];
	memset(dp,-1,sizeof(dp[0])*(N+1));

	for(i=0;i<M;i++)
	{
		scanf("%d %d",&temp1,&temp2);
		//printf("%llu",dp[i+1]);
		if(temp1 != temp2){
		_edge[temp1].real.push_back(temp2);
		_edge[temp2].imag.push_back(temp1);
        }
	}

   bfs(dp,_edge);
   {


//if(dp[N]==200000)
  //  printf("-1\n");
//else
  printf("%d\n",dp[N]);}
		return 0;
	}