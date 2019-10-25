#include<stdio.h>
#include "file_cmd.h"
void add(char *p_list[], char **f_list, int list_max, char *file_max_length, int *list_num)
{
	if(*list_num < list_max) {
		int i;
		for(i = 0; i < list_max; i++)
		{
			if(!f_list[i][0])
			{
				do{
					printf("请输入文件名字：\n");
				} while(!scanf(file_max_length, f_list[i]));
				p_list[*list_num++] = f_list[i];
				break;
			}
		}
	} else {
		printf("列表满了\n");
	}
}
