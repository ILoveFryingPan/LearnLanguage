#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a[10];
	int i, j;
	int t;
	printf("排序前的数组：\n");
	for(i = 0; i < 10; i ++) {
		a[i] = rand() % 100 + 1;
		printf("%4d ", a[i]);
	}
	printf("\n排序后的数组：\n");
	for(i = 0; i < 9; i++) {
		for(j = i + 1; j < 10; j++) {
			if(a[i] > a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	for(i = 0; i < 10; i++) {
		printf("%4d ", a[i]);
	}
	printf("\n");

	char buddy [3][200];
	printf("请输入联系人姓名：");
	scanf("%50s", buddy[0]);

	printf("\n请输入联系人电话：");
	scanf("%30s", buddy[1]);

	printf("\n请输入联系人地址：");
	scanf("%199s", buddy[2]);

	printf("\n您输入的信息是：\n");
	for(i = 0; i < 3; i++) {
		printf("%s\n", buddy[i]);
	}

	return 0;
}
