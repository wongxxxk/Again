#pragma once
class Inheritance
{
protected:
	float f_PA;//ֻ���������(friend�ؼ���,���������Ա�������Է������Ա)��Ԫ�����ı�

public:
	void Copy(float x);

private:
	int i_PA;//������������\��Ԫ\��������
};

//һ��������̳������еĻ��෽����������������⣺
//����Ĺ��캯�������������Ϳ������캯����
//����������������
//�������Ԫ������
/*****������******/
class ChildInheritance : public Inheritance//һ�㶼����Public�̳У����ı丸�������
{
public:
	float f_PB;
	void ChildAdd();
	friend void fri_Test(ChildInheritance );

private:
	int Child_i_PB;
};
