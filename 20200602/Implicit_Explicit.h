#pragma once
#include <String>
#include <iostream>

class Implicit_Explicit
{

private:
	int i_var;
	std::string str_var;

public:
	Implicit_Explicit(int );

	explicit Implicit_Explicit(const std::string& );
//ע�⣺����������Ͷ���ֱ��������ļ���ʱ��explicitֻ��д���������У�����д�ڶ����С�
};

