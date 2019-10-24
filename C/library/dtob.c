/**
 * 下面的代码是看过网上整形转字符串的代码后
 * 按照记忆中的逻辑写的
 */
#include<stdio.h>
#include"dtob.h"

void dtob(int num, char *temp) {
	printf("传递的值：%d\n", num);
	short int yu;
	if(!num){
		temp = "0";
	} else {
		int b = 0;	//数组的偏移量
		int k = 0;	//标志变量，0表示大于0，1表示小于0
		char tmp;
		if(num < 0) {
			k = 1;
			num = -num;
			temp[b] = '-';
			b++;
		}
		do {
			yu = num % 2;
			temp[b] = '0' + yu;
			b++;
			num /= 2;
		}while(num);
		temp[b] = '\0';
		for(int i = k; i < (b - 1) / 2.0; i++) {
			tmp = temp[i];
			temp[i] = temp[b - 1 + k - i];
			temp[b - 1 + k -i] = tmp;
		}
	}
}
