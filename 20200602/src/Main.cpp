#include <iostream>
#include <string>
#include "SysLog.h"
#include "../Satatic_Extern.h"
#include "Singleton.h"
#include "Constructors.h"
#include "Inheritance.h"
#include "VirtualFun.h"
#include "PrueVirtual.h"
#include "Implicit_Explicit.h"
#include "KeyWordThis.h"
#include <memory>//����ָ��
#include "Arrow.h"
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
public://����
	int PlayerX = 1, PlayerY = 1;
	int speed = 1;

	void Move( int xa, int ya)//ӵ�е�function,�������еı���\�������﷨��
	{
		PlayerX += xa * speed;
		PlayerY += ya * speed;
	}
private://����\��Ԫ������������\���󶼲�����

protected://ֻ���������(friend�ؼ���,���������Ա�������Է������Ա)��Ԫ�����ı�
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

void PrintName(VirtualFun* entity)//�����ָ������ָ�������ࣨ��̬ʵ�֣�
{
	Out(entity->GetName());
}

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
	static Player Player1;//�ֶ�ʵ����
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
//************�̳�\��Ԫ����**********************
	Out('\n'<<"�̳�");
	ChildInheritance AAA;
	AAA.Copy(5.0f);
	AAA.f_PB = 6.0f;
	AAA.ChildAdd();
	fri_Test(AAA);//��Ԫ���������Է��ʱ����Private��Protected
//--------------�麯��(������д����)-------------
	Out("");
	VirtualFun* BB = new VirtualFun();
	VirtualTest* BBB = new VirtualTest("wongkang!VirtualFunction!");
/*
new�˲���ʵ��,��������ptr* a =(*ptr)malloc(sizeof(ptr));
new�Զ����������ڴ��С��
new��delete�ڶ��󴴽���ʱ���Զ�ִ�й��캯������������֮ǰ���Զ�ִ������������
*/
	PrintName(BB);
	PrintName(BBB);
//---------------���麯��(�ӿ�\������)------
	Out("");
	PrueVirtualTestA CC;
	PrueVirtualTestB CCC;
	CC.Prue();
	CCC.Prue();
//-----------------�ַ���----------------
	Out("");
	std::string name = std::string("wong") + "kang";
	Out("std::string�ֽ���: "<< sizeof(name));
	std::wstring wname = std::wstring(L"wong") + L"kang";
	Out("L\"wongkang\" �ֽ���: " <<sizeof(L"wongkang"));//���ַ�����wchar_t\char_16t\char_32t
//--------------Constc����-------Mutable���޸ĵ�-------------
	int* const d = new int;//���޸ı����������޸�ָ���ַ
	const int* dd = new int;//�����޸ı�������ָ��������ַ
	const int* const ddd = new int;//��ʼ����ʲô�����ܸ�
//--------------Ternary Operator��Ŀ�����---------------------------------
	int i_speed = 65;
	i_speed = i_speed < 5 ? 5 : 10;//Same With C, TRUE = 5 FALSE = 10
	Out(i_speed);
	std::string rank = i_speed > 5 ? "CCC" : i_speed > 10 ? "DDD" : "AAA";
	Out(rank);
//--------------Create/Instantiate Objects(����\ʵ������)---------------
	Out("");
	VirtualTest* pSS;
	{
		VirtualTest SS("Cherno");//����������SS���ͷ�(ջ)
		pSS = &SS;
		Out(pSS->GetName());
	}
	if (pSS->GetName() == "")//֤����������
	{
		Out("Null");
	}

	{
		VirtualTest* pSSS = new VirtualTest("wangk");//���������ڴ棬��delete������ڴ�һֱ����
		pSS = pSSS;
		Out(pSSS->GetName());
	}
	delete pSS;//�ͷŵ����ڴ�/
//----------------��ʽת��---------------------------
	Out("");
	Implicit_Explicit im0 = 22;//��ʽת��
	Implicit_Explicit im1("Hello");//explicit�ؼ���������ʽת��
//-----------------�����ع�--------------------------(���ع����������)
//-------------------this----------------------------
	Out("");
	KeyWordThis(1994, 1997);//ÿһ��������ͨ�� this ָ���������Լ��ĵ�ַ
//------Object's Lifttime
	Out("thisָ��----------------------------------------------");
	class Lifttime
	{
	public:
		Lifttime()
		{
			Out("Creat");
		}
		~Lifttime()
		{
			Out("Destroyed");
		}

		void printf()
		{};
	};
	class ScopedPtr
	{
	private:
		Lifttime* m_Ptr;
	public:
		ScopedPtr(Lifttime* Ptr) :
			m_Ptr(Ptr)
		{
		}

		~ScopedPtr()
		{
			delete m_Ptr;
		}

	};
	{
		Lifttime e;//����������ջ�������������淶Χ(��ջ)
		ScopedPtr eee(new Lifttime());//ScopedPtrͬ�������淶Χ����(ֻҪ����������ڴ棬����ʵ�ʱ�����)���������ţ��Զ���������
		Lifttime* ee = new Lifttime();//�����˶��ڴ�,��Ҫdelete
	}
//------------------����ָ��------------------------------
	Out("����ָ��---------------------------------------------");
	{//Ψһָ��,���ܸ���('='���ع���)
		Out("uniqueΨһָ��: ");
		std::unique_ptr<Lifttime> smart_uniqueptr = std::make_unique<Lifttime>();//unique_ptr(Ψһָ�룬ֻ��һ��ָ����ָ����ڴ��ַ)��ֹ��ʽת��;���Զ�����
/*
																	//����ָ��Ĵ���
																	unique_ptr<int> u_i; 	//����������ָ��
																	u_i.reset(new int(3)); 	//�󶨶�̬����
																	unique_ptr<int> u_i2(new int(4));//����ʱָ����̬����
																	unique_ptr<T,D> u(d);	//������ unique_ptr��ִ������Ϊ T �Ķ���������Ϊ D �Ķ��� d �����Ĭ�ϵ�ɾ���� delete
																	//����Ȩ�ı仯
																	int *p_i = u_i2.release();	//�ͷ�����Ȩ
																	unique_ptr<string> u_s(new string("abc"));
																	unique_ptr<string> u_s2 = std::move(u_s); //����Ȩת��(ͨ���ƶ�����)��u_s����Ȩת�ƺ󣬱�ɡ���ָ�롱
																	u_s2.reset(u_s.release());	//����Ȩת��
																	u_s2=nullptr;//��ʽ������ָ����ͬʱ����ָ���Ϊ��ָ�롣��u_s2.reset()�ȼ�
*/
		smart_uniqueptr->printf();
	}
	{
		std::shared_ptr<Lifttime> sharedptr;
		std::weak_ptr<Lifttime> smart_weakptr;//��ָ�벻���ù���ָ��ļ���+1
		{//����ָ��,������ָ����ڴ��ַ��ָ�붼��ʧ�󣬶���Ż��Զ�delete
			Out("shared����ָ��:");
			std::shared_ptr<Lifttime> smart_sharedptr = std::make_shared<Lifttime>();
			sharedptr = smart_sharedptr;//�ڴ汻���ô���+1
			smart_weakptr = smart_sharedptr;
		}
	}

//---------------------Arrow---------------------------------------
	Out("---------------Arrow-----------------");
	{
		BaseArrow entity(new Base());
		entity.GetObject()->printf();
		entity->printf();//�ع���-> ��
	}

	struct VectorArrow
	{
		float x, y, z;//�ڴ���4�ֽ�
	};

	int offset = (int)&(((VectorArrow*)0)->y);
	Out("->�����Կ��ڴ���ĳ��ֵ��ƫ��   "<<offset);
	std::cin.get();
}
/*
	Log(var);
	bool bHome;//Home clone�ɹ�
	I32 var = 0;
	I32* ptr = &var;//c++ָ���С��ָ��ĵ�ַ�����޹�,WIN32 4�ֽ�
	*ptr = 100;

	char* buffer = new char[8];//��̬�����ڴ棿heap
	memset(buffer, 0, 8);
	delete[] buffer;//�ͷŵ�

	int& ref = var;//���ò�����Ĵ���ref������ֻ�Ǹ�����ȡ��ַ

	return 0;
*/
