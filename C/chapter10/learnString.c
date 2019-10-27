#include<stdio.h>
#include<string.h>
#define LENGTH 20

int main(int argc, char *argv[])
{
	char a[LENGTH];
	const char *s = "ABCDEFG";
	strcpy(a, s);
	puts(a);
	for(int i = 0; i < LENGTH; i++) {
		a[i] = '\0';
	}
	strncpy(a, s, 4);
	puts(a);
	strcat(a, s);
	puts(a);
	strncat(a, s, 4);
	puts(a);
	return 0;
}
