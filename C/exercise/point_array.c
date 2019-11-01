#include<stdio.h>

int main()
{
	char *data[] = {
		"china",
		"hello",
		"everybody",
		"onlyone"};
	for(int i = 0; i < 4; i++)
	{
		puts(data[i]);
		printf("%x\n", &data[i]);
	}
	printf("\n");
	char **p = data;
	puts(*p);
	p++;
	puts(*p);
	return 0;
}
