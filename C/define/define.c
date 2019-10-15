#pragma once

#include<stdio.h>
#define PI 3.14

#pragma message("我是预处理信息");

int main()
{
	//我是第一行注释
	/*
	 * 我是第二行注释
	 */
	/****
	 * 我是第三行注释
	 */
	/*
	 我是第四行注释
	 */
	printf("行号：%d", __LINE__);
	printf("文件名：%s", __FILE__);
	printf("编译日期：%s", __DATE__);
	printf("编译时间：%s", __TIME__);
	printf("标准状态码：%d", __STDC__);
	return 0;
}
