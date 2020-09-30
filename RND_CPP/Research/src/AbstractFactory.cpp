#include "Runnable.h"
#include <memory>
#include <typeinfo>
#include <unordered_map>
#include <functional>

class AbstractFactoryPattern : public Runnable {

	struct Product {
		virtual	void make() = 0;
	};

	struct Phone : public Product {
		// Inherited via Product
		virtual void make() override
		{
			std::cout << "make phone " << std::endl;
		}
	};

	struct Car : public Product {
		// Inherited via Product
		virtual void make() override
		{
			std::cout << "make car " << std::endl;
		}
	};


	std::unordered_map<std::string, std::function<Product*()>> factory;


	Product* get(std::string productName) {
		return nullptr;
	}


	// Inherited via Runnable
	virtual void Run() override
	{
		// prepare factory

		factory.insert({ typeid(Phone).name(), []()-> Product* { return  new Phone(); } });
		factory.insert({ typeid(Car).name(), []()-> Product* { return  new Car(); } });

		auto obj = get("Car");
	}

};