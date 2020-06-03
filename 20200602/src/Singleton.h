#pragma once
class Singleton
{
/*
private:
	static Singleton* s_Instance;//效果一样
*/
public:
	static Singleton& GetInstance();
	void HelloSingleton();
	int var ;
};

