#include <iostream>
//#include "Log.h"
//ALT+G �ɿ������(�ӻ������Ż�)
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
	I32* ptr = &var;//c++ָ���С��ָ��ĵ�ַ�����޹�,WIN32 4�ֽ�
	*ptr = 100;

	char* buffer = new char[8];//��̬�����ڴ棿heap
	memset(buffer, 0, 8);
	delete[] buffer;//�ͷŵ�

	int& ref = var;// ���ò�����Ĵ���ref������ֻ�Ǹ������ (int* ref = &var)
	Log(var);

	return 0;
	std::cin.get();
}