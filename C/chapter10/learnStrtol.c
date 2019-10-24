#include<stdio.h>
#include<stdlib.h>

int main()
{
	const char *s = {"1234.3个苹果"};
	char *p;
	long l;
	int i = 10;
	l = strtol(s, &p, i);
	printf("数值是：%ld\n", l);
	printf("%ld后的字符串是：%s\n", l, p);
	return 0;
}
