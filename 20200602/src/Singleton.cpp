#include "Singleton.h"
//����->���ã�����ֻ��һ��ʵ��


Singleton& Singleton::GetInstance()
{
	static Singleton s_Instance;//����static,�����ڶ���ʵ��,Get����������s_Instanceʵ������
	return s_Instance;//��ʼ��ʱ����һ�Σ���ֻ��һ��ʵ������
};

void Singleton::HelloSingleton()
{
	var += 1;
};
