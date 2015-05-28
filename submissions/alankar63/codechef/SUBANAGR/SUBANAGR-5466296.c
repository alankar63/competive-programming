#include <stdio.h>
 
int main(int argc, char *argv[])
{
  int arr[101][26] = {0};
  char str[101];
  int i,j,n;
  char *ch;
 
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%s", str);
 
    ch = str;
    while (*ch)
    {
      arr[i][*ch-'a']++;
      ch++;
    }
 
    if (i>0)
    {
      for (j=0; j<26; j++)
      {
        if (arr[i][j] < arr[0][j])
          arr[0][j] = arr[i][j];
      }
    }
  }
 
  n=0;
  for (j=0; j<26; j++)
  {
    while(arr[0][j]>0)
    {
      printf("%c", 'a'+j);
      arr[0][j] = arr[0][j]-1;
      n++;
    }
  }
  if (n==0)
  {
    printf("no such string");
  }
  printf("\n");
 
  return 0;
}