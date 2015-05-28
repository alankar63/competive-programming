#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<vector>

using namespace std;
long int N,M;

typedef struct GUtil{
    vector<long int> fEdge;
    vector<long int> bEdge;
}GUtil;


void reverse(int *dp,GUtil *gutil)
{


    long int temp,i,temp2;
    queue<long int> q;
    dp[N] = 0;
    q.push(N);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(!gutil[temp].fEdge.empty())
        for(i=0;i<gutil[temp].fEdge.size();i++)
        {
            temp2 = gutil[temp].fEdge[i];
            if(dp[temp]+1 <dp[temp2] || dp[temp2] == -1)
               {
                 dp[temp2]= dp[temp]+1;
                 q.push(temp2);
               }
        }
        if(!gutil[temp].bEdge.empty())
        for(i=0;i<(gutil[temp].bEdge.size());i++)
        {
            temp2 = gutil[temp].bEdge[i];
            if(dp[temp] <dp[temp2] || dp[temp2] == -1)
             {
                 dp[temp2]= dp[temp];
                 q.push(temp2);
             }
        }


    }


}




int main(){
	long int i,temp1,temp2,count=0,j;

	scanf("%d %d",&N,&M);


	int dp[N+1];
	//GNode graph[M];
    GUtil gutil[N+1];
	memset(dp,-1,sizeof(dp[0])*(N+1));

	for(i=0;i<M;i++)
	{
		scanf("%d %d",&temp1,&temp2);
		//graph[i].src = temp1;
		//graph[i].dest = temp2;
		if(temp1 != temp2){
		gutil[temp1].fEdge.push_back(temp2);
		gutil[temp2].bEdge.push_back(temp1);
        }
	}

   reverse(dp,gutil);
  /* for(int i=1;i<N+1;i++)
   {
       printf("vertex %d : ",i);
       for(int j=0;j<gutil[i].bEdge.size();j++)
        printf("%d  ",gutil[i].bEdge.at(j));
       printf("\n");
   }

   for(int i=0;i<N+1;i++)
  printf("dp[%d]: %d\n",i,dp[i]);
  */
  printf("%d\n",dp[1]);
		return 0;
	}