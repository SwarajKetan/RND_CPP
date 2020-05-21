
#pragma once
#include "Runnable.h"
#include <assert.h>

struct Casting : public Runnable {

	// Static cast
	// Dynamic cast
	// Const cast
	// Reinterpret cast (dangerous)

	// Checks compile time 
	// OK for promotion /narrowing
	void StaticCast() {
		double d = 0.9;
		int i = static_cast<int>(d);
		/*std::string s = "abc";
		int k = static_cast<int>(s);*/ // Error 
		assert(i == 0);
	}


	struct base {
		void basePrint() {
			std::cout << "base print" << std::endl;
		};
	};

	struct derived : public base {
		void derivedPrint() {
			std::cout << " derived print" << std::endl;
		}
	};

	void DynamicCast() {

		// parent to child -> not allowed

		/*base* b = new base();
		derived* d = dynamic_cast<derived*>(b);*/

		// child to parent allowed
		derived* d = new derived();
		base* b = dynamic_cast<base*>(d);
		
	}

	void DoSomethingMore(const int x) {
		std::cout << x << std::endl;
	}
	void DoSomething(int& x) {
		x += 1;
	}

	void ConstCast() {
		const int i = 5;
		//DoSomething(i); // doesn;t work
		DoSomething(const_cast<int&>(i));
		//assert(i == 6);

		int nc = 7;
		DoSomethingMore(const_cast<int&>(nc));
	}


	void Run() {
		StaticCast();
		DynamicCast();
		ConstCast();
	};
};