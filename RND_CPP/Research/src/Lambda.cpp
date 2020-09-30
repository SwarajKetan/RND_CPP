#include "Runnable.h"
#include <functional>
struct Lambda : public Runnable {

	//template<class... T>
	//void f(T... args) {
	//	auto x = [args...]() {
	//		/*for (auto i : args) {
	//			std::cout << i << std::endl;
	//		}*/
	//		std::cout << args << std::endl;
	//	};
	//	x();
	//};

	/*
	void S::f(int i) {
		[&, i] {};      // OK
		[&, &i] {};     // ERROR: i preceded by & when & is the default
		[=, this] {};   // ERROR: this when = is the default
		[=, *this] { }; // OK: captures this by value. See below.
		[i, i] {};      // ERROR: i repeated
	}
	*/
	void Run() {		

		int k = 0;
		auto predicate = [&](int a, int b) mutable throw() -> bool {
			//this->Run();
			std::cout << k << std::endl;
			return a < b;
			
		};

		auto p2 = [&k](int a, int b) mutable throw() -> bool {
			//this->Run();
			std::cout << k << std::endl;
			return a < b;

		};

		std::function<int(int, int)> f2 = [](int a, int b) -> int { return a + b; };
		std::cout << f2(12, 20) << std::endl;

		int res = [](int a, int b)->int {
			return a + b;
		}(6, 7);

		//f("abc", "bcd", "def");
	};
};