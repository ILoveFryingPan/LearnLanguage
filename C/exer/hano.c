#include<stdio.h>

void hanoi(int n, char a, char b, char c, int type)
{
	type = (type << 1) + 1;
	if(n == 1)
	{
		printf("%c>-->%c, 层次%d\n", a, c, type);
		return;
	}
	hanoi(n - 1, a, c, b, type);
	printf("%c>-->%c,层次%d\n", a, c, type);
	hanoi(n - 1, b, a, c, type);
}

int main(int argc, char *argv[])
{
	hanoi(3, 'a', 'b', 'c', 1);
	return 0;
}
