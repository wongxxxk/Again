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

class Player//��ֽṹ�壬�෽���м̳� ����
{
public://�����ⲿ���ʣ�Ĭ��˽�в��ɷ��ʵ�
	int PlayerX = 1, PlayerY = 1;
	int speed = 1;

	void Move( int xa, int ya)//ӵ�е�function,�������еı���\�������﷨��
	{
		PlayerX += xa * speed;
		PlayerY += ya * speed;
	}
};

struct stPlayer//�ṹ�壬һ�ѱ����ͼ򵥷����ýṹ��
{
	int PlayerX = 1, PlayerY = 1;
	int speed = 1;

	void Move(int xa, int ya)
	{
		PlayerX += xa * speed;
		PlayerY += ya * speed;
	}
};

int main()
{
	Player Player1;//ʵ����
	stPlayer Player2;//C++�ṹ��,����struct
	Player1.Move(1, -1);
	Player2.Move(3, -3);
	Log(Player1.PlayerX);
	Log(Player2.PlayerX);

	std::cin.get();


/*
	bool bHome;//Home clone�ɹ�
	I32 var = 0;
	I32* ptr = &var;//c++ָ���С��ָ��ĵ�ַ�����޹�,WIN32 4�ֽ�
	*ptr = 100;

	char* buffer = new char[8];//��̬�����ڴ棿heap
	memset(buffer, 0, 8);
	delete[] buffer;//�ͷŵ�

	int& ref = var;// ���ò�����Ĵ���ref������ֻ�Ǹ������ (int* ref = &var)
	Log(var);

	return 0;
*/
}