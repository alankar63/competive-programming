#include<stdio.h>
#define DEBUG 0
typedef unsigned int num;
int main(){
  num nJars;
  num mixtures[100][100], smoke[100][100];
  num min,sum, tentative;
  while(scanf("%u", &nJars)>0){
    for(num i=0; i<nJars; i++) scanf("%u", &mixtures[i][i]);
    if(DEBUG){
      printf("Input:\n");
      for(num x=0; x<nJars; x++){
	for(num y=0; y<nJars; y++)
	  printf("%u ",mixtures[x][y]);
	printf("\n");
      }
    }
    for(num i=0; i<nJars; i++){
      sum=mixtures[i][i];
      for(num j=i+1; j<nJars; j++){
	sum = (sum + mixtures[j][j])%100;
	mixtures[i][j]=sum;
      }
    }
    if(DEBUG){
      printf("Mixtures:\n");
      for(num x=0; x<nJars; x++){
	for(num y=0; y<nJars; y++)
	  printf("%u ",mixtures[x][y]);
	printf("\n");
      }
    }
    for(num i=0; i<nJars; i++) smoke[i][i]=0;
    for(num k=1; k<nJars; k++){
      for(num i=0; i+k<nJars; i++){
	min=999999;
	for(num j=i; j<i+k; j++){
	  tentative = smoke[i][j]+smoke[j+1][i+k] + mixtures[i][j]*mixtures[j+1][i+k];
	  if(tentative<min) min=tentative;
	  if(DEBUG) printf("k:%u,i:%u,j:%u,tentative:%u,min:%u\n",k,i,j,tentative,min);
	}
	smoke[i][i+k]=min;
      }
    }
    if(DEBUG){
      for(num x=0; x<nJars; x++){
	for(num y=0; y<nJars; y++)
	  printf("%u ",smoke[x][y]);
	printf("\n");
      }
    }    
    printf("%u\n",smoke[0][nJars-1]);
  }
  return 0;
}