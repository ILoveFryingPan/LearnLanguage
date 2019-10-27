#include<stdio.h>
#include<stdlib.h>
#define LENGTH 6

int main() 
{
	double d = 1234.5678;
	char p[LENGTH + 2];
	gcvt(d, LENGTH, p);
	puts(p);
	char q[100];
	sprintf(q, "%4.2f%s", d, "已转换");
	puts(q);
	return 0;
}
