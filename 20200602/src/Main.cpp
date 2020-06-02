#include <iostream>
//#include "Log.h"
//ALT+G 可看反汇编(从汇编层面优化)
typedef char	I8;
typedef short	I16;
typedef int		I32;
typedef float	f32;
typedef unsigned short U16;
typedef unsigned int   U32;

#define Log(x) std::cout << x << std::endl


int main()
{
	I32 var = 0;
	I32* ptr = &var;//c++指针大小和指向的地址类型无关,WIN32 4字节
	*ptr = 100;

	char* buffer = new char[8];//动态申请内存？heap
	memset(buffer, 0, 8);
	delete[] buffer;//释放掉

	int& ref = var;// 引用不会真的创建ref变量，只是更方便≈ (int* ref = &var)
	Log(var);

	return 0;
	std::cin.get();
}