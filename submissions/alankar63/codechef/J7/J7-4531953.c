#include <stdio.h>
#include <math.h>
 
 
double solveme(double a, double b, double c);
 
int main() 
{
	int n;
	int i;
	double p, s;
 
	double x, y, z, V;
 
	scanf("%d", &n);
 
	for (i = 0; i < n; i++) {	
		scanf("%lf %lf", &p, &s);		
		x = solveme(-6, p, -s);			
		z = x;		
		y = (p - (8 * x)) / 4;		
		V = x * y * z;		
		printf("%.2lf\n", V);
	
	}
	
	return 0;
	
}
 
double solveme(double a, double b, double c) {
 
double D= (b * b) - (4 * a * c); 
 
if (D == 0) return (-b / (2 * a));
else if (D > 0) return (-b + sqrt(D)) / (2 * a); 
else return 0; 
 
}