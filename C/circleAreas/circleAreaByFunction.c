#include<stdio.h>
#include<math.h>
#define PI 3.14
float area(float r)
{
	return PI * pow(r, 2);
}

int main()
{
	float r;
	printf("r of circle:");
	scanf("%f", &r);
	printf("\nr=%f\n",r);
	printf("area:%f\n", area(r));
	return 0;
}
