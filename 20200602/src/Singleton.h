#pragma once
class Singleton
{
/*
private:
	static Singleton* s_Instance;//Ч��һ��
*/
public:
	static Singleton& GetInstance();
	void HelloSingleton();
	int var ;
};

