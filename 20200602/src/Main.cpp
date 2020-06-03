#include <iostream>
#include "SysLog.h"
//#include "Log.h"
//ALT+G 可看反汇编(从汇编层面优化)
typedef char	I8;
typedef short	I16;
typedef int	I32;
typedef float	f32;
typedef unsigned short U16;
typedef unsigned int   U32;

#define Out(x) std::cout << x << std::endl

class Player//类≈结构体，多方法有继承 用类
{
public://允许外部访问，默认私有不可访问的
	int PlayerX = 1, PlayerY = 1;
	int speed = 1;

	void Move( int xa, int ya)//拥有的function,操作类中的变量\仅仅是语法糖
	{
		PlayerX += xa * speed;
		PlayerY += ya * speed;
	}
};

struct stPlayer//结构体，一堆变量和简单方法用结构体
{
	int PlayerX = 1, PlayerY = 1;
	int speed = 1;

	void Move(int xa, int ya)
	{
		PlayerX += xa * speed;
		PlayerY += ya * speed;
	}
};

extern int NormalVar;//函数同理

int main()
{
	static Player Player1;//实例化
	static stPlayer Player2;//C++结构体,不用struct
	Player1.Move(1, -1);
	Player2.Move(3, -3);
	Out(Player1.PlayerX);
	Out(Player2.PlayerX);
	SysLog syslog;
	syslog.SetLevel(syslog.LogLevelInfo);
	syslog.Error("Hello");
	syslog.Warn("Hello");
	syslog.Info("Hello");
	Out("Extern："<<NormalVar);

	std::cin.get();

/*
	bool bHome;//Home clone成功
	I32 var = 0;
	I32* ptr = &var;//c++指针大小和指向的地址类型无关,WIN32 4字节
	*ptr = 100;

	char* buffer = new char[8];//动态申请内存？heap
	memset(buffer, 0, 8);
	delete[] buffer;//释放掉

	int& ref = var;// 引用不会真的创建ref变量，只是更方便≈ (int* ref = &var)
	Log(var);

	return 0;
*/
}