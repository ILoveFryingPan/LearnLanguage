#include<stdio.h>

int main()
{
	int a = 123;
	float b = 45.6789;
	printf("%5d-%7.2f", a, b);
	printf("\n%-5dend\n", a);
	printf("%5d\n", a);
	char ch = getchar();
	putchar(ch);
	printf("输出结束");
	return 0;
}
