#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "../media_library/file_cmd.h"

#define MAX_LENGTH 40
#define MAX_FILE_LENGTH 255
#define GET_NAME "%255s"

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
				//if(l < MAX_LENGTH) {
				//	for(i = 0; i < MAX_LENGTH; i++) {
				//		if(!f_list[i][0]) {
				//			do{
				//				printf("输入文件名：");
				//			} while(!scanf(GET_NAME, f_list[i]));
				//			p_list[i] = f_list[i];
				//			l++;
						//	break;
				//		}
				//	}
				//} else {
				//	printf("列表满了\n");
				//}
				break;
			case 2:
				if(l > 0) {
					printf("输入文件序号：\n");
					scanf("%s", temp);
					int index = ctoi(temp);
					if(index > 0 && index <= l) {
						for(i = index - 1; i < l - 1;i++) {
							p_list[i] = p_list[i + 1];
						}
						f_list[--index][0] = 0;
						l--;
					}
				} else {
					printf("列表没数据");
				}
				break;
			case 3:
				for(i = 0; i < l; i++) {
					printf("%d : %s\n", (i + 1), p_list[i]);
				}
				break;
			case 4:
				exit_switch = 0;
				break;
			case 5:
				if(l > 1) {
					for(i = 0; i < l - 1; i++) {
						for(j = i + 1; j < l; j++) {
							if(strcmp(p_list[i], p_list[j]) > 0) {
								cmp = p_list[i];
								p_list[i] = p_list[j];
								p_list[j] = cmp;
							}
						}
					}
				}
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
