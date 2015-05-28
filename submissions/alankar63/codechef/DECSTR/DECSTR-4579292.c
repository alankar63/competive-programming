#include<stdio.h>
int main(){
	int t , i , n;
	char *arr[] = {
                      "z","y","x","w","v","u","t","s","r","q","p","o","n","m"
                         ,"l","k","j","i","h","g","f","e","d","c","ba",
                      "z","y","x","w","v","u","t","s","r","q","p","o","n","m"
                         ,"l","k","j","i","h","g","f","e","d","c","ba",
                      "z","y","x","w","v","u","t","s","r","q","p","o","n","m"
                         ,"l","k","j","i","h","g","f","e","d","c","ba",
		      "z","y","x","w","v","u","t","s","r","q","p","o","n","m"
			 ,"l","k","j","i","h","g","f","e","d","c","ba"
		      };
	scanf("%d" , &t);
	while(t --){
		scanf("%d" , &n);
		for(i = 100 - n ; i < 100 ; i ++){
			printf("%s" , arr[i]);
		}
		printf("\n");
	}
	return 0;
}