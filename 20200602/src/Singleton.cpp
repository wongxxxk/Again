#include "Singleton.h"
//单例->作用：有且只有一个实例


Singleton& Singleton::GetInstance()
{
	static Singleton s_Instance;//必须static,否则在堆上实例,Get函数结束，s_Instance实例销毁
	return s_Instance;//初始化时声明一次，且只有一个实例返回
};

void Singleton::HelloSingleton()
{
	var += 1;
};
