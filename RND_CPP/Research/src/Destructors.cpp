#include "Runnable.h"

struct Destructors : public Runnable {

	struct BaseClass final { // this is not inheritable

	};

	struct A1 { virtual ~A1() { printf("A1 dtor\n"); } };
	struct A2 : A1 { virtual ~A2() { printf("A2 dtor\n"); } };
	struct A3 : A2 { virtual ~A3() { printf("A3 dtor\n"); } };

	struct B1 { ~B1() { printf("B1 dtor\n"); } };
	struct B2 : B1 { ~B2() { printf("B2 dtor\n"); } };
	struct B3 : B2 { ~B3() { printf("B3 dtor\n"); } };

	void Run() {

		A1* a = new A3;
		delete a;
		printf("\n");

		B1* b = new B3;
		delete b;
		printf("\n");
		std::cerr << "ee" << std::endl;

		B3* b2 = new B3;
		delete b2;
	};
};