#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	printf("参数个数：%d\n", argc);
	for(int i = 0; i < argc; i++) {
		printf("参数%d的值：%s\n", i, argv[i]);
	}

	char *p = "我爱北京天安门";
	char *des = malloc(50);
	printf("内容：%s\t长度：%ld\n", p, strlen(p));
	memmove(des, p + 3, strlen(p) - 6);
	printf("输出结果\n");
	printf("%s\n", des);
	free(des);

	return 0;
}
