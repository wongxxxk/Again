#pragma once
class PrueVirtual
{
public:
	virtual void Prue() = 0;
};

class PrueVirtualTestA : public PrueVirtual
{
public:
	virtual void Prue() override;
};

class PrueVirtualTestB : public PrueVirtual
{
public:
	virtual void Prue() override;
};

