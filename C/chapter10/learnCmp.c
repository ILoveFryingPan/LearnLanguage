#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	const char *s1 = "Happy New Year!";
	const char *s2 = "Happy New Year!";
	const char *s3 = "Happy Holidays!";

	printf("%d,%d,%d\n", strcmp(s1, s2), strcmp(s1, s3), strcmp(s2, s3));
	printf("%d,%d,%d\n", strncmp(s1, s2, 6), strncmp(s1, s3, 7), strncmp(s2, s3, 7));
	return 0;
}
