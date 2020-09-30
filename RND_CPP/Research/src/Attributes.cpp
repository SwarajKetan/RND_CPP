#pragma once

#include "Runnable.h"
#include <assert.h>


struct Attributes : public Runnable {

	enum class Month : int {
		JAN = 1,
		FEB,
		MAR,
		APR
	};

	//[[deprecated]]
	void SomeOldMethod() {
		std::cout << "old" << std::endl;
	};

	[[noreturn]]
	int NoRetFun() {
		try {
			throw "ee";
		}
		catch(...){
			return -1;
		}
		return 0;
	}

	void Run() {
	
		std::cout << "alignof(char*) : " << alignof(char*) << std::endl;
		std::cout << "alignof(float*) : " << alignof(float*) << std::endl;
		std::cout << "alignof(double*) : " << alignof(double*) << std::endl;
		std::cout << "alignof(int*) : " << alignof(int*) << std::endl;

		static_assert(alignof(int*) == alignof(char*), "Err");

		int x = 3;
		Month m = static_cast<Month>(x);

		assert(m == Month::MAR, "E");

		SomeOldMethod();
		std::cout << NoRetFun() << std::endl;
	
	};
};