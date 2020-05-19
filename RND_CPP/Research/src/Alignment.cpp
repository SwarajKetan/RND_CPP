#pragma once
#include "Runnable.h"
#include <string>
#include <typeinfo>

struct Alignment : public Runnable {
#pragma pack(1)
	struct X {
		double d;
		int i;
		int j;
		int k;
		short s;
	};
#pragma pack(1)
	struct IX {
		short s;
		int i;
		int j;
		int k;		
		double d;
	};

	#pragma pack(1)
	struct Foo {

		int i; // 4 byte
		int n; // 4 byte
		char arr[3]; // 3 byte
		short s; // 2 byte
	};


	struct alignas(16) Bar {

		int i;
		int n;
		alignas(4) char arr[3];
		short s;
	};

	template<typename T>
	void Print() {
		std::cout << typeid(T).name() << " = " << "alignof:" << alignof(T) << ", sizeof:" << sizeof(T) <<std::endl;
	}
	void Run() {
		Print<Foo>();
		Print<Bar>();
		Print<X>();
		Print<IX>();
	};
	
};
