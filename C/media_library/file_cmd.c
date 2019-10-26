#include<stdio.h>
#include "file_cmd.h"
void add(char *p_list[], char *f_list, int size, int list_max, char *file_max_length, int *list_num)
{
	printf("列表最大长度：%d, 文件的输入格式字符串：%s\n", list_max, file_max_length);
	printf("列表游标：%d\n", *list_num);
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
