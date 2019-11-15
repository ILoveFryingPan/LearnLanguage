//这是个测试用while清空输入缓冲区函数文件

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char *s = (char *) malloc(3);
	char getBuff;
	printf("输入一段字符串\n");
	while(scanf("%10s", s)) {
		scanf("%*[^\n]%*c");
		
		//while(getBuff = getchar() != '\n' && getBuff != EOF);
		printf("输入的字符串是：%s\n", s);
	}
	printf("输入结束\n");
	return 0;
}
