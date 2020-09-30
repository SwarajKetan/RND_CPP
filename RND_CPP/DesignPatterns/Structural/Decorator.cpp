#include <iostream>
#include <string>

namespace Decorator_Pattern {

	struct Component {
		virtual void Operation() = 0;
	};

	// main concrete component
	struct Pizza : public Component {
		virtual void Operation() override
		{
			std::cout << "Pizza.Operation()" << std::endl;
		}
	};

	struct Decorator : public Component {
	private:
		Component* component_;
	public:
		void SetComponent(Component* component) {
			component_ = component;
		}
		virtual void Operation() override
		{
			if (component_) {
				component_->Operation();
			}
		}
	};

	struct Cheese : public Decorator {
		void Operation() override
		{
			Decorator::Operation();
			std::cout << "added cheese" << std::endl;
		}
	};

	struct Garlic : public Decorator {
		void Operation() override
		{
			Decorator::Operation();
			std::cout << "added garlic" << std::endl;
		}
	};

	struct Honey : public Decorator {
		void Operation() override
		{
			Decorator::Operation();
			std::cout << "added honey" << std::endl;
		}
	};


	void Client() {
		Component* pizza = new Pizza();
		
		Cheese* cheese = new Cheese();
		Garlic* garlic = new Garlic();
		Honey* honey = new Honey();

		cheese->SetComponent(pizza);
		garlic->SetComponent(cheese);
		honey->SetComponent(garlic);

		honey->Operation();

	}

}