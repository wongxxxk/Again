#include <iostream>

int NormalVar = 5;	//Ĭ������Extern����
static int s_Var = 10;//�ڲ�������ֻʵ����һ��

void Satatic_add()
{
	static int s_i = 0;//��̬����,��һ�ε���ʱ��ʼ��һ��(֮����ͬһ����),ͬʱ��Ч������������
	s_i++;
	std::cout << s_i << std::endl;
}