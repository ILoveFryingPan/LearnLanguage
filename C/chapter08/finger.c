#include<stdio.h>
#define M 2
#define N 4

int main()
{
	int a[M][N], *pa;
	int i, j;
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("%4d\n", a[i][j]);
		}
	}
	printf("\n");

	//pa = a[0];
	//printf("请输入数组的数值：");
	//for(i = 0; i < M; i++) {
	//	for(j = 0; j < N;j++) {
	//		scanf("%d", pa + i * N + j);
	//		putchar('\0');
	//	}
	//}
	//printf("数组内的数值是：");
	//for(i = 0; i < M * N; i++) {
	//	printf("%d\n", *(pa + i));
	//}
	
	//char c[20], *pc;
	//pc = c;
	//scanf("%19s", pc);
	//puts(pc);
	//printf("第10位：%d\n", c[9]);
	//printf("结束符：%d\n", '\0');

	char *d[4] = {"China",
		"USA",
		"Rassia",
		"Japan"};
	d[0] = "I Love CHENYANG";
	for(i = 0; i < 4; i++) {
		printf("\n%s", d[i]);
	}
	printf("\n");

	return 0;
}
