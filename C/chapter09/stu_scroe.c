#include<stdio.h>
#define COURSE 5	//定义课程总数
#define STUDENT 5	//定义学生总数

void input_stu(float (*score)[COURSE]);	//该函数的形式参数是指针数组 输入学生成绩
void avr_stu(float (*score)[COURSE], float *a_stu);	//该函数的形式参数是指针数组和指针 计算学生的平均分
void avr_cor(float (*score)[COURSE], float *a_cor);	//同上 计算课程的平均分
float highest(int *r, int *c, float (*score)[COURSE]);	//该函数的形式参数是指针和指针数组 寻找最好分
float s_diff(float *a_stu);	//该函数的形式参数是指针 求方差

int main(int args, char *argv[]) {
	float score[STUDENT][COURSE];	//用于保存学生成绩
	float a_stu[STUDENT];		//用于保存学生平均分
	float a_cor[COURSE];		//用于保存课程平均分
	int i, j, r, c;			//声明循环控制变量
	float h;			//用于保存最高分
	r = 0;				//初始化最高分的学生编号
	c = 1;				//初始化最高分的课程编号
	input_stu(score);		//实际参数是二维数组首地址
	avr_stu(score, a_stu);		//实际参数是二维数组首地址和一维数组首地址
	avr_cor(score, a_cor);		//实际参数是二维数组首地址和一维数组首地址
	printf("\n	序号	课程1	课程2	课程3	课程4	课程5	平均分");
	for(i = 0; i < STUDENT; i++) {
		printf("\n	NO%2d", i + 1);
		for(j = 0; j < COURSE; j++) {
			printf("	%8.2f", score[i][j]);
		}
		printf("	%8.2f", a_stu[i]);
	}
	printf("\n课平均");
	for(j = 0; j < COURSE; j++) {
		printf("	%8.2f", a_cor[j]);
	}
	h = highest(&r, &c, score);
	printf("\n\n最高分%8.2f是 %d 号学生的第%d门课\n", h, r, c);
	printf("	方差%8.2f\n", s_diff(a_stu));
	return 0;
}

void input_stu(float (*score)[COURSE])
{
	int i, j;
	for(i = 0; i < STUDENT;i++)
	{
		printf("请输入学生%2d的5个成绩：\n", i + 1);
		for(j = 0; j < COURSE; j++)
		{
			scanf("%f", &score[i][j]);
		}
	}
}

void avr_stu(float (*score)[COURSE], float *a_stu)
{
	int i, j;
	float s;
	for(i = 0; i < STUDENT; i++)
	{
		s = 0;
		for(j = 0; j < COURSE; j++)
			s += score[i][j];
		a_stu[i] = s / COURSE;
	}
}

void avr_cor(float (*score)[COURSE], float *a_cor)
{
	int i, j;
	float s;
	for(j = 0; j < COURSE; j++)
	{
		s = 0;
		for(i = 0; i < STUDENT; i++)
			s += score[i][j];
		a_cor[j] = s / (float) STUDENT;
	}
}

float highest(int *r, int *c, float (*score)[COURSE])
{
	float high;
	int i, j;
	high = *score[0];
	for(i = 0; i < STUDENT; i++)
		for(j = 0; j < COURSE; j++)
			if(score[i][j] > high)
			{
				high = score[i][j];
				*r = i + 1;
				*c = j + 1;
			}
	return high;
}

float s_diff(float *a_stu)
{
	int i;
	float sumx;
	float sumxn;
	sumx = 0.0;
	sumxn = 0.0;
