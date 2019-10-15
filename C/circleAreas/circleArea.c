#include<stdio.h>
#define PI 3.14
int main()
{
	float r, s;
	printf("radius = ");
	scanf("%f", &r);
	s = PI * r * r;
	printf("\narea = %f\n", s);
	return 0;
}
