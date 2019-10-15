#include<stdio.h>
#include<math.h>

void binaryPrint(int num) 
{
	printf("开始输出二进制：\n");
	while(1)
	{
		printf("%d", num % 2);
		num = num / 2;
		if(fabs(num) == 0)
		{
			break;
		}
	}
	printf("\n二进制输出完毕\n");
}

int main()
{
	const int dog_count;
	enum week{mon = 2,tue = 5,wed,thu,fri};
	printf("dog_count=%d\n", dog_count);
	printf("mon = %d \t tue = %d \t wed = %d\n", mon, tue, wed);
	printf("c = %0x \n", 'c');
	int a = -5, d = 7, c;
	binaryPrint(a);
	a = ~a;
	binaryPrint(a);
	c = a > d ? d ++: d --;
	printf("d的值：d = %d\n", d);
	printf("c的值：c = %d\n", c);
	return 0;
}
