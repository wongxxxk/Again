#include <iostream>
#include <string>
#include "SysLog.h"
#include "../Satatic_Extern.h"
#include "Singleton.h"
#include "Constructors.h"
#include "Inheritance.h"
#include "VirtualFun.h"
#include "PrueVirtual.h"
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
public://公开
	int PlayerX = 1, PlayerY = 1;
	int speed = 1;

	void Move( int xa, int ya)//拥有的function,操作类中的变量\仅仅是语法糖
	{
		PlayerX += xa * speed;
		PlayerY += ya * speed;
	}
private://本类\友元函数允许，派生\对象都不允许

protected://只允许子类和(friend关键字,不属于类成员，但可以访问类成员)友元函数改变
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

void PrintName(VirtualFun* entity)//基类的指针允许指向派生类（多态实现）
{
	Out(entity->GetName());
}

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
	static Player Player1;//手动实例化
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
//************继承\友元函数**********************
	Out('\n'<<"继承");
	ChildInheritance AAA;
	AAA.Copy(5.0f);
	AAA.f_PB = 6.0f;
	AAA.ChildAdd();
	fri_Test(AAA);//友元函数，可以访问本类的Private和Protected
//--------------虚函数(派生重写基类)-------------
	Out("");
	VirtualFun* BB = new VirtualFun();
	VirtualTest* BBB = new VirtualTest("wongkang!VirtualFunction!");
/*
new了才有实例,基本等于ptr* a =(*ptr)malloc(sizeof(ptr));
new自动计算申请内存大小；
new和delete在对象创建的时候自动执行构造函数，对象消亡之前会自动执行析构函数。
*/
	PrintName(BB);
	PrintName(BBB);
//---------------纯虚函数(接口\抽象类)------
	Out("");
	PrueVirtualTestA CC;
	PrueVirtualTestB CCC;
	CC.Prue();
	CCC.Prue();
//-----------------字符串----------------
	Out("");
	std::string name = std::string("wong") + "kang";
	Out("std::string字节数: "<< sizeof(name));
	std::wstring wname = std::wstring(L"wong") + L"kang";
	Out("L\"wongkang\" 字节数: " <<sizeof(L"wongkang"));//宽字符类型wchar_t\char_16t\char_32t
//--------------Constc常量-------Mutable可修改的-------------
	int* const d = new int;//可修改变量，不能修改指向地址
	const int* dd = new int;//不可修改变量，可指向其它地址
	const int* const ddd = new int;//初始化后什么都不能改
//--------------Ternary Operator三目运算符---------------------------------
	int i_speed = 65;
	i_speed = i_speed < 5 ? 5 : 10;//Same With C, TRUE = 5 FALSE = 10
	Out(i_speed);
	std::string rank = i_speed > 5 ? "CCC" : i_speed > 10 ? "DDD" : "AAA";
	Out(rank);
//--------------Create/Instantiate Objects(创建\实例对象)---------------
	Out("");
	VirtualTest* pSS;
	{
		VirtualTest SS("Cherno");//函数结束后，SS被释放(栈)
		pSS = &SS;
		Out(pSS->GetName());
	}
	if (pSS->GetName() == "")//证明被弹出了
	{
		Out("Null");
	}

	{
		VirtualTest* pSSS = new VirtualTest("wangk");//堆上申请内存，不delete，这块内存一直存在
		pSS = pSSS;
		Out(pSSS->GetName());
	}
	delete pSS;//释放掉该内存



	//Out(pSS->GetName());
	std::cin.get();
}
/*
	Log(var);
	bool bHome;//Home clone成功
	I32 var = 0;
	I32* ptr = &var;//c++指针大小和指向的地址类型无关,WIN32 4字节
	*ptr = 100;

	char* buffer = new char[8];//动态申请内存？heap
	memset(buffer, 0, 8);
	delete[] buffer;//释放掉

	int& ref = var;//引用不会真的创建ref变量，只是更方便取地址

	return 0;
*/
