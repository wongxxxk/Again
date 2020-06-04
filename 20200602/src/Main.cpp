#include <iostream>
#include "SysLog.h"
#include "../Satatic_Extern.h"
#include "Singleton.h"
#include "Constructors.h"
#include "Inheritance.h"

//#include "Log.h"
//ALT+G �ɿ������(�ӻ������Ż�)
typedef char	I8;
typedef short	I16;
typedef int	I32;
typedef float	f32;
typedef unsigned short U16;
typedef unsigned int   U32;

#define Out(x) std::cout << x << std::endl

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

struct Entity
{
	static int x, y;
};

extern int NormalVar;//����ͬ��

int Entity::x = 10;//�ྲ̬��Ա��ʼ��
//��̬���������ⲿ����,���Թ������е������,ʵ�����ݹ���
int Entity::y= 20;

void Construction_Destruction()
{
	Constructorswk Con(5.5f, 6.5f);
	Out("���캯��");
	Con.print();
	Out("");
	Constructorswk Ion(1, 2);
	Out("������ͬ�Ĺ��캯��");
	Ion.print();
}

int main()
{
	static Player Player1;//ʵ����
	static stPlayer Player2;//C++�ṹ��,����struct
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
	Out("enum: ÿ��ö��size"<<sizeof(SysLog::LogLevelError));//Ĭ��4�ֽڣ�Ҳ����������
	Out("Extern��"<<NormalVar);
	E1.x = 5;
//	Entity::x = 5;
	E2.x = 6;
	Out(E1.x);//�ྲ̬��Ա
	Out(E2.x);
	Out(E1.y);
	Out(E2.y);

	for(int i = 0;i < 5 ;i++)
		Satatic_add();

	Singleton& RealInstance = Singleton::GetInstance();//ÿ�ε���Singleton::GetInstance()�����õ�ͬһʵ��
	for (int i = 0; i < 6; i++)
	{
		RealInstance.HelloSingleton();
		Out("HelloSingleton: " << RealInstance.var);//ͬһʵ���еı���Ҳ�Ǿ�̬��
	}
//------------����\����------------------------
	Out("");
	Construction_Destruction();
//************�̳�\��Ԫ**********************
	Out('\n'<<"�̳�");
	ChildInheritance AAA;
	AAA.Copy(5.0f);
	AAA.f_PB = 6.0f;
	AAA.ChildAdd();
	fri_Test(AAA);//��Ԫ���������Է��ʱ����Private��Protected

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