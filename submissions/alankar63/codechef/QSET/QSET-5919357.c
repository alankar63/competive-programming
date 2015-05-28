#include<stdio.h>
#include<math.h>
int min( int a , int b )
{
  return a < b ?a:b;
}
long long int cal( int x )
{
  long long int ans = x;
  ans *= (x - 1);
  ans /= 2;
  return ans;
}

int ans[3] , n , s , arr[100003] , tbox;
typedef struct box
{
  int a ;
  int rem[3];
}box;
box b[100003];
int gi( int i )
{
  if( i <= 0 )
  {
    return -i;
  }
  else if( i == 1 )
    return 2;
  else if( i == 2 )
    return 1;
}

int query( int i , int j )
{
  int boxi = i / s , boxj = j / s , x;

  do
  {
    x = ( arr[i] + b[boxi].a ) % 3;
    x = ( x < 0 )?(x + 3 ):x;
    ans[x]++;
    i++;
  }
  while( i <= j && ( i % s != 0 ) );

  ++boxi;

  while( boxi < boxj )
  {
    int ind = gi( b[ boxi ].a );
    ans[0] += b[ boxi ].rem[ ind ];
    ans[1] += b[ boxi ].rem[ ( 1 + ind )%3];
    ans[2] += b[ boxi ].rem[ ( 2 + ind )%3];
    i += s;
    boxi++;
  }

  while( i <= j )
  {
    x = ( arr[i] + b[ boxi ].a )%3;
    x = ( x < 0 )?(x + 3 ):x;
    ans[x]++;
    i++;
  }
}

int update( int i , int y )
{
  int boxi = i / s;
  if( y < 0 )
    y += 3;
  do
  {
    --b[ boxi ].rem[ arr[i] ];
    arr[i] = ( arr[i] + y ) % 3 ;
    ++b[ boxi ].rem[ arr[i] ];
    i++;
  }
  while( i < n && i % s );
  ++ boxi;

  while( boxi < tbox )
  {
    b[ boxi ].a = ( y + b[ boxi ].a ) % 3;
    boxi++;
  }

}

int main()
{
  int i , x , a , bb , m;
  int ori[100003];
  char ss[100003];
  // box b[10000];
  scanf("%d %d" , &n , &m);
  scanf("%s" , ss);
  ori[0] = ss[0] -'0';
  arr[0] = ( ss[0] -'0' ) % 3;
  i = n +  1;
  while(i--)
  {
    b[i].rem[0] = 0;
    b[i].rem[1] = 0;
    b[i].rem[2] = 0;
    b[i].a = 0;
  }
  b[0].rem[arr[0]]++;
  s = sqrt(n);
  int p , q;
  p = 1;
  q = 0;
  for( i = 1 ; i < n ; i++ )
  {
    ori[i] = ss[i] -'0';
    arr[i] = ( arr[i-1] + ss[i] - '0' ) % 3;
    ++b[q].rem[ arr[i] ];
    p++;
    if( p == s )
    {
      p = 0;
      q++;
    }
  }
  tbox = q + 1;
  while( m-- )
  {
    scanf("%d %d %d" , &x , &a , &bb);
    a--;
    if( x == 2 )
    {
      bb--;
      ans[0] = 0;
      ans[1] = 0;
      ans[2] = 0;
      if( a != 0 )
        query( a-1 , bb);
      else
      {
        query(a , bb );
        ans[0]++;
      }
      long long int ans1 = 0;
      for( i = 0 ; i < 3 ; i++)
        ans1 +=  cal( ans[i] );
      printf("%lld\n" , ans1 );
    }
    else
    {
      update( a , ( bb - ori[a] )%3 );
      ori[a] = bb;
    }
  }
  return 0;
}