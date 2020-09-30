#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

enum class Type {
	TYPE1 = 0,
	TYPE2
};

class Prototype {

private :
	std::string prototype_name_;
	float prototype_field_ = 0.0f;

public:
	Prototype() = delete;
	Prototype(std::string name) : prototype_name_(name), prototype_field_(0.0f) {

	}

	virtual ~Prototype() {}
	virtual Prototype* Clone() const = 0;
	virtual void Method(float prototype_field) {
		this->prototype_field_ = prototype_field;
		std::cout << "Call Method from " << prototype_name_ << " with field : " << prototype_field << std::endl;
	}

};
//************************************************************************************************************************************
class ConcretePrototype1 : public Prototype {
private:
	float concrete_prototype_field1_;

public:
	ConcretePrototype1(string prototype_name, float concrete_prototype_field)
		: Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field) {
	}

	// Inherited via Prototype
	virtual Prototype* Clone() const override
	{
		return new ConcretePrototype1(*this);
	}
};

class ConcretePrototype2 : public Prototype {
private:
	float concrete_prototype_field2_;

public:
	ConcretePrototype2(string prototype_name, float concrete_prototype_field)
		: Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field) {
	}
	Prototype* Clone() const override {
		return new ConcretePrototype2(*this);
	}
};
//************************************************************************************************************************************
class ProtoTypeFactory {

private:
	std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
	ProtoTypeFactory() {
		prototypes_[Type::TYPE1] = new ConcretePrototype1("TYPE1", 50.0f);
		prototypes_[Type::TYPE2] = new ConcretePrototype2("TYPE2", 60.0f);
	};

	~ProtoTypeFactory() {
		for (auto pair : prototypes_) {
			delete pair.second;
		}
	};

	Prototype* Create(Type type) {
		return prototypes_[type]->Clone();
	}

 };