#ifndef MEDIALIB_H_
#define MEDIALIB_H_
#define MAX_TITLE_LENGTH 512	//标题最长长度
#define MAX_ATRIST_LENGTH 512
#define MAX_ALBUM_LENGTH 256
#define MAX_GENRE_LENGTH 256
#define MAX_PATH_LENGTH 4096
typedef struct _medialib Medialib;
struct _medialib {
	char title[MAX_TITLE_LENGTH];
	char atrist[MAX_ATRIST_LENGTH];
	char album[MAX_ALBUM_LENGTH];
	char genre[MAX_GENRE_LENGTH];
	double record_time;
	char filepath[MAX_PATH_LENGTH];
};
#endif	/*MEDIALIB_H_*/
