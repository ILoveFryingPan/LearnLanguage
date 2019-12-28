#include<iostream>	//使用C++的流输入输出库
#include<string.h>	//使用c的字符串处理库
using std::cout;	//使用名字空间std中的cout 类似于java中的import
using std::endl;	//使用名字空间std中的endl

class Buddy {		//定义类名称
public:			//公共成员
	Buddy();	//构造函数
	void setBuddy(const char *, long, const char*);//设置联系人信息函数
	void printBuddy();	//输出联系人信息函数
private:			//似有成员
	char name[50];		//联系人姓名
	long telnum;		//电话号码
	char address[200];	//地址
};

Buddy::Buddy()			//定义构造函数
{
	name[0] = '\n';		//将buddy类中的private成员初始化
	telnum = -1;
	address[0] = '\0';
}

void Buddy::setBuddy(const char *n, long t, const char *a)
	//定义设置联系人信息函数
{
	strcpy(name,n);
	telnum = t;
	strcpy(address, a);
}

void Buddy::printBuddy()	//定义输出联系人信息数据
{
	cout << "姓名：" << name << " 电话：" << telnum
		<< " 地址：" << address << endl;	//使用输出流输出类成员数据
}

int main()
{
	Buddy b;				//使用类Buddy生成对象b
	b.setBuddy("Tom", 1234567890, "China");	//调用对象自身的函数输入数据
	b.printBuddy();				//调用对象自身的函数输出数据
	return 0;
}
