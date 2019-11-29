#ifndef MEDIA_LIBRARY
#define MEDIA_LIBRARY
void add(char *p_list[], char *f_list, int size, int list_max, char *file_max_length, int *list_num);
int ctoi(char *c);
void del(char *p_list[], int *list_num);
void p(char *p_list[], int *list_num);
void sort(char *p_list[], int *list_num);
void clear_buffer();
void search(char *p_list[], int *list_num, char *input, char *p_input);
#endif
