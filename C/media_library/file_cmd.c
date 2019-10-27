#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "file_cmd.h"
void add(char *p_list[], char *f_list, int size, int list_max, char *file_max_length, int *list_num)
{
	if(*list_num < list_max) {
		int i;
		for(i = 0; i < list_max; i++)
		{
			if(!*(f_list + size * i))
			{
				do{
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
