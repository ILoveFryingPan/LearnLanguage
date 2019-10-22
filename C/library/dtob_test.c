#include<stdio.h>
#include<stdlib.h>
#include"dtob.h"

int main() {
	char *result = malloc(sizeof(char) * 33);
	dtob(7, result);
	printf("3的值：%s\n", result);
	dtob(-3, result);
	printf("-3的值：%s\n", result);
	free(result);
	result = NULL;
	return 0;
}
