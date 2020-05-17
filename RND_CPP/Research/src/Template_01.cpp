#include <iostream>
#include <exception>
#include "Runnable.h"

struct Template_01 : public Runnable {
	
	template<typename T>
	struct MyTemplate {
	private:
		T* t = nullptr;
	public:
		MyTemplate() {

		};
		MyTemplate(T* _t) : t(_t) {

		};

		void DoExecute() {
			std::cout << "DoExecute" << std::endl;
			//t->Run();
		}

		~MyTemplate()
		{
			delete t;
			std::cout << "~MyTemplate()" << std::endl;
		}
	};
	
	
	void Run()
	{
		auto x = MyTemplate<Runnable>(new Template_01());
		x.DoExecute();
	}

};