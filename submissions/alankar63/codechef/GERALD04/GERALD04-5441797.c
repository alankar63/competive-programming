#include<stdio.h>
#include<stdlib.h>
 
typedef struct time{
	int hr1, hr2, min1, min2;
}time;
 
int main()
{
	long int t;
	int	a, dist, i, tim, b;
	float time1;
	time T;
	scanf("%ld", &t);
	for (i = 0; i < t; i++)
	{
	    tim=0;a=0;b=0;
		scanf("%d:%d", &T.hr1, &T.min1);
		scanf("%d:%d", &T.hr2, &T.min2);
		scanf("%d", &dist);
 
		b = T.min1 - T.min2;
		a = T.hr1 - T.hr2;
 
		if (b < 0)
		{
			a--;
			tim = a * 60 + (b + 60);
			tim = tim + dist;
			printf("%.1f ",(float)tim);
		}
 
		if (b>=0)
		{
			tim = a * 60 + b;
			tim = tim + dist;
			printf("%.1f ",(float)tim);
		}
 
		tim=tim-dist;
 
		if(tim>=(2*dist))
        {
            printf("%.1f\n",(float)tim);
        }
        else if(tim==dist)
        {
            time1=(float)(3*tim)/2;
            printf("%.1f\n",time1);
        }
        else
        {
            time1=(float)dist+(float)tim/2;
            printf("%.1f\n",time1);
        }/*
		else if(tim>dist)
        {
            time1=(float)(dist+(tim/2));
            printf("%.1f\n",time1);
        }*/
	}
	return 0;
}