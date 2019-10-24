#include<stdio.h>
#include<stdlib.h>
int main() 
{
	const char *s = {"87.99%已完成"};
	char *p;
	double d;
	d = strtod(s, &p);
	printf("数值是：%.2f\n", d);
	printf("%.2f后的字符串是：%s\n", d, p);
	return 0;
}
