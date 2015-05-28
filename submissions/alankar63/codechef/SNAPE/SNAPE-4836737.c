#include<stdio.h>
#include<math.h>
int main()
{
    int t,b,ls;
    float rs1,rs2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&b, &ls);
        float rs1=((float)(sqrt((ls*ls)-(b*b))));
        float rs2=((float)(sqrt((ls*ls)+(b*b))));
        printf("%f %f\n",rs1,rs2);
    }
    return 0;
}