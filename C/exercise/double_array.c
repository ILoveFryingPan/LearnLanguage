#include<stdio.h>

void data_show(int *data, int size);

int main(int argc, char *argv[]) {
	int data[][3] = {
		{3,4,5},
		{7,5,33},
		{5,3,12}};

	printf("数组大小：%d\n", sizeof(data));

	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("%5d", data[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

	data_show(data, 3);

	return 0;
}

void data_show(int *data, int size)
{
	long int total = sizeof(data);
	printf("数组总大小：%ld\n", total);
}
