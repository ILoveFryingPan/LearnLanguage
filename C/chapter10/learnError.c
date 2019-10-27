#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *error = strerror(2);
	puts(error);
	printf("\n错误信息长度为：%d\n", strlen(error));
	return 0;
}

