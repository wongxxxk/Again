#include <iostream>
#include "SysLog.h"
#include "../Satatic_Extern.h"
#include "Singleton.h"
#include "Constructors.h"
#include "Inheritance.h"

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

struct Entity
{
	static int x, y;
};

extern int NormalVar;//函数同理

int Entity::x = 10;//类静态成员初始化
//静态变量允许外部申请,可以共享到所有的类变量,实现数据共享
int Entity::y= 20;

void Construction_Destruction()
{
	Constructorswk Con(5.5f, 6.5f);
	Out("构造函数");
	Con.print();
	Out("");
	Constructorswk Ion(1, 2);
	Out("参数不同的构造函数");
	Ion.print();
}

int main()
{
	static Player Player1;//实例化
	static stPlayer Player2;//C++结构体,不用struct
	Entity E1,E2;
	Player1.Move(1, -1);
	Player2.Move(3, -3);
	Out(Player1.PlayerX);
	Out(Player2.PlayerX);
	SysLog syslog;
	syslog.SetLevel(SysLog::LogLevelInfo);
	syslog.Error("Hello");
	syslog.Warn("Hello");
	syslog.Info("Hello");
	Out("enum: 每个枚举size"<<sizeof(SysLog::LogLevelError));//默认4字节，也可设置类型
	Out("Extern："<<NormalVar);
	E1.x = 5;
//	Entity::x = 5;
	E2.x = 6;
	Out(E1.x);//类静态成员
	Out(E2.x);
	Out(E1.y);
	Out(E2.y);

	for(int i = 0;i < 5 ;i++)
		Satatic_add();

	Singleton& RealInstance = Singleton::GetInstance();//每次调用Singleton::GetInstance()都会拿到同一实例
	for (int i = 0; i < 6; i++)
	{
		RealInstance.HelloSingleton();
		Out("HelloSingleton: " << RealInstance.var);//同一实例中的变量也是静态的
	}
//------------构造\析构------------------------
	Out("");
	Construction_Destruction();
//************继承\友元**********************
	Out('\n'<<"继承");
	ChildInheritance AAA;
	AAA.Copy(5.0f);
	AAA.f_PB = 6.0f;
	AAA.ChildAdd();
	fri_Test(AAA);//友元函数，可以访问本类的Private和Protected

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