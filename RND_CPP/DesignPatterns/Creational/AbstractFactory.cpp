#include <string>
#include <iostream>

class AbstractProductA {
public:
	virtual ~AbstractProductA() {};
	virtual void UsefulFunctionA() const = 0;
};

class ConcreateProductA1 : public AbstractProductA {
	// Inherited via AbstractProductA
public:
	virtual void UsefulFunctionA() const override
	{
		std::cout << "printing from ConcreateProductA1" << std::endl;
	}
};

class ConcreateProductA2 : public AbstractProductA {
	// Inherited via AbstractProductA
	virtual void UsefulFunctionA() const override
	{
		std::cout << "printing from ConcreateProductA2" << std::endl;
	}
};

//************************************************************************************************************************************
class AbstractProductB {
public:
	virtual ~AbstractProductB() {};
	virtual void UsefulFunctionB() = 0;
	virtual void AnotherUsefulFunctionB(const AbstractProductA& otherA) const = 0;
};

class ConcreateProductB : public AbstractProductB {
public:
	// Inherited via AbstractProductB
	virtual void UsefulFunctionB() override
	{
		std::cout << "Printing from ConcreateProductB" << std::endl;
	}
	virtual void AnotherUsefulFunctionB(const AbstractProductA& otherA) const override
	{
		otherA.UsefulFunctionA();
	}
};

//************************************************************************************************************************************

class AbstractFactory {
public:
	virtual AbstractProductA* CreateProductA() const = 0;
	virtual AbstractProductB* CreateProductB() const = 0;
};

class ConcreateFactory1 : public AbstractFactory {

	// Inherited via AbstractFactory
	virtual AbstractProductA* CreateProductA() const override
	{
		return new ConcreateProductA1();
	}
	virtual AbstractProductB* CreateProductB() const override
	{
		return new ConcreateProductB();
	}
};

//************************************************************************************************************************************

void ClientCode(const AbstractFactory& factory) {
	AbstractProductA* pa = factory.CreateProductA();
	AbstractProductB* pb = factory.CreateProductB();
	pa->UsefulFunctionA();
	pb->UsefulFunctionB();

	delete pa;
	delete pb;
};

//************************************************************************************************************************************

int x_main() {

	ConcreateFactory1 cf1;
	ClientCode(cf1);
};