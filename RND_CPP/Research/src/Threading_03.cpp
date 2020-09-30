#pragma once
#include "Runnable.h"
#include <thread>
#include <mutex>
#include <functional>
#include <initializer_list>
// Different tways to create thread

struct Threading_03 : public Runnable {

	// Lambda
	void Lambda() {
		std::cout << "Lambda " << std::endl;
		std::thread th([](int x) {

			while (x-- > 0) {
				std::cout << x << ", ";
			}
			std::cout << std::endl;
			}, 5);
		th.join();
	};

	// Static member function
	struct class_01 {
	public:		
		static void Do(int x) {
			std::cout << "Static member function " << std::endl;
			while (x-- > 0) {
				std::cout << x << ", ";
			}
			std::cout << std::endl;
		};
	};

	void StaticMemberFunction() {
		std::thread th(&class_01::Do, 11); th.join();
	};

	// Non-static member function
	struct class_02 {
	public:
		void Do(int x) {
			std::cout << "NOn- Static member function " << std::endl;
			while (x-- > 0) {
				std::cout << x << ", ";
			}
			std::cout << std::endl;
		};
	};

	void NonStaticMemberFunction() {
		class_02 c02;
		std::thread th(&class_02::Do, &c02, 11); th.join();
	};

	// functor
	struct class_03 {

		void operator()(int x) const {
			std::cout << "functor " << std::endl;
			while (x-- > 0) {
				std::cout << x << ", ";
			}
			std::cout << std::endl;
		};
	};

	std::mutex _mutex;


	template<class T>
	void func(std::initializer_list<T> args) {
		for (auto a : args)
			std::cout << a << std::endl;
	}

	// for threadsafe execution
	void useOfMutex() {

		std::unique_lock<std::mutex> uniq(_mutex, std::defer_lock);
		
		uniq.lock();
		std::cout << "some critical section \n";
		uniq.unlock();

		std::function<void(int, std::string, int)> somelambda = [](int a, std::string b, int c) {
			std::cout << "abc" << std::endl;
		};

		//run_callback(somelambda);

		//std::lock_guard<std::mutex> lock(_mutex);
		//{
		//	//do something
		//}
	}

	void Functor() {
		std::thread th((class_03()), 5);
		th.join();
	};


	void Run() {
		Functor();
		NonStaticMemberFunction();
		StaticMemberFunction();
		Lambda();
	};
};