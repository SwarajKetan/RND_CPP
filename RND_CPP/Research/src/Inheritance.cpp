#pragma once
#include "Runnable.h"
#include <string>


struct Inheritance : public Runnable {

	struct A {
		virtual void Print() {};
	};

	struct B : public A {
		void Print() final {

		};
	};

	struct C : public A {
		void Print() override {

		};
	};


	// Can not override final function
	/*struct D : public B {
		void Print() override {

		};
	};*/


	void Run() {

	};
};