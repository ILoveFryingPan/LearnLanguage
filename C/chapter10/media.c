#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../media_library/file_cmd.h"

#define MAX_LENGTH 40
#define MAX_FILE_LENGTH 255
#define GET_NAME "%255s"

int main() {
	int i, j, l = 0;
	char f_list[MAX_LENGTH][MAX_FILE_LENGTH + 1];
	char *p_list[MAX_LENGTH];
	for(i = 0; i < MAX_LENGTH; i++) {
		p_list[i] = NULL;
		f_list[i][0] = 0;
	}

	int select_value;
	char exit_switch = 1;
	char *temp = malloc(sizeof(char) * 10);
	char *cmp;
	do{
		puts("请选择操作命令：");
		puts("（1）添加新文件：");
		puts("（2）删除列表中的文件");
		puts("（3）打印播放列表");
		puts("（4）退出程序");
		puts("（5）按文件名排序");

		scanf("%s", temp);
		if(strlen(temp) != 1) {
			continue;
		}

		select_value = ctoi(temp);
		printf("输入的数字是：%d\n", select_value);
		switch(select_value) {
			case 1:
				add(p_list, f_list, MAX_FILE_LENGTH + 1, MAX_LENGTH, GET_NAME, &l);
				break;
			case 2:
				del(p_list, &l);
				break;
			case 3:
				p(p_list, &l);
				break;
			case 4:
				exit_switch = 0;
				break;
			case 5:
				sort(p_list, &l);
				break;
			default:
				printf("别瞎输入\n");
				break;
		}
	} while(exit_switch);
	free(temp);
	temp = NULL;

	return 0;
}
