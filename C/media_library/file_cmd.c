#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file_cmd.h"

void clear_buffer()
{
	scanf("%*[^\n]%*c");
}

void add(char *p_list[], char *f_list, int size, int list_max, char *file_max_length, int *list_num)
{
	if(*list_num < list_max) {
		int i;
		for(i = 0; i < list_max; i++)
		{
			if(!*(f_list + size * i))
			{
				do{
					clear_buffer();
					printf("请输入文件名字：\n");
				} while(!scanf(file_max_length, f_list + size * i));
				p_list[*list_num] = f_list + i * size;
				(*list_num)++;
				break;
			}
		}
	} else {
		printf("列表满了\n");
	}
}


int ctoi(char *c) {
	int result = 0;
	int temp = 0;
	while(*c) {
		temp = *c - '0';
		if(temp >= 0 && temp <= 9) {
			result = result * 10 + temp;
		}
		c++;
	}
	return result;
}

void del(char *p_list[], int *list_num)
{
	if(*list_num) {
		char *num = (char *) malloc(sizeof(char) * 2);
		char *buff = (char *) malloc(sizeof(char) * 11);
		do{
			clear_buffer();
			printf("输入文件序号：");
		} while(!scanf("%1s", num));
		char c = getchar();
		printf("多余的：%c\n", c);
		int numnum = ctoi(num);
		if(numnum <= 0 || numnum > *list_num) {
			printf("超出了范围\n");
			return;
		}

		p_list[--numnum][0] = 0;
		for(int i = numnum; i < *list_num - 1; i++) 
		{
			p_list[i] = p_list[i + 1];
		}
		--*list_num;
		free(num);
		num = NULL;
	} else {
		printf("还没有数据\n");
	}
}

void p(char *p_list[], int *list_num)
{
	for(int i = 0; i < *list_num; i++)
	{
		printf("%d	%s\n", i + 1, p_list[i]);
	}
}

void sort(char *p_list[], int *list_num)
{
	if(*list_num > 1) {
		char *tmp;
		for(int i = 0; i < *list_num - 1; i++)
		{
			for(int j = i + 1; j < *list_num; j++)
			{
				if(strcmp(p_list[i], p_list[j]) > 0)
				{
					tmp = p_list[i];
					p_list[i] = p_list[j];
					p_list[j] = p_list[i];
				}
			}
		}
	}
}

void search(char *p_list[], int *list_num, char *input, char *p_input)
{
	int i;
	int find_mode = 0;	//用于保存查找模式，默认为0， 即完全匹配模式
	p_input[0] = 0;
	int score = 0;	//用于保存匹配项目的个数
	puts("请输入要查找的字符串：");
	puts("“=”开始表示完全匹配，“?”用于替代一个字符，“*”用于替代多个字符");
	scanf(input, p_input);
	clear_buffer();
	if (p_input[0] != '=')
		find_mode = 1;
	else
		memmove(p_input, p_input + 1, strlen(p_input));
	for(i = 0; i < *list_num; i++) {
		if(find_mode == 0)
			if(strlen(p_list[i]) == strlen(p_input)) {
				res = strcmp(p_list[i], p_input);
				if(res)
					res = 1;
				else
					res = 0;
			} else 
				res = 0;
		else
			res = hazy_find(p_list[i], p_input);
		if(res) {
			printf("%d : %s\n", i + 1, p_list[i]);	//输出找到的字符串
			score++;
		}
	}
	if(score < 1) {
		printf("找不到匹配的项目");
	}
}

int hazy_find(const char *str1, const char *str2)
{
	const char *ct = "*?";	//保存通配符
	int i, j = 0;	//用于保存str1、str2的操作位置
	int l;		//用于保存str2的长度
	int k;		//用于保存查找时每次查找的长度
	char sec[strlen(str1)];	//用于保存每次查找的字符串分段
	int res;	//用于保存查找结果
