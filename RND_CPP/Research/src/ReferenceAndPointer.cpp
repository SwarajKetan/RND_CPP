#include "Runnable.h"

struct ReferenceAndPointer : public Runnable {
	
	struct W
	{
		W(int&, int&) {}
	};

	struct X
	{
		X(const int&, int&) {}
	};

	struct Y
	{
		Y(int&, const int&) {}
	};

	struct Z
	{
		Z(const int&, const int&) {}
	};

	class MemoryBlock {
	public:

		MemoryBlock() {

		};
		void f(const MemoryBlock& mblValue) {

		};

		void f(const MemoryBlock&& mbRvalue) {

		};
	};

	/*template<typename T, typename A1, typename A2>
	T* factory(A1& a1, A2& a2) {
		return new T(a1, a2);
	};*/

	template<typename T, typename A1, typename A2>
	T* factory(A1&& a1, A2&& a2) {

		return new T(std::forward<A1>(a1), std::forward<A2>(a2));
	};


	void Run() {
		int x = 7;
		int* ptrInt = &x;
		int& refInt = *ptrInt;
		refInt = 8;

		std::cout << *ptrInt << std::endl;

		int a = 4; int b = 5;
		W* pw = factory<W>(a, b);
		Z* pz = factory<Z>(2, 3);
		char cc = 'X';
		volatile char* pCh = &cc;
		
		//char* volatile kch = &cc;
		const char* cpCh = &cc;
		char* const pcCh = &cc; // which we dont want to reassign
		char another = 'L';

		char* anotherOne = &another;

		anotherOne = const_cast<char*>(cpCh);
		//cpCh = &another;
		//pcCh = &another;

		MemoryBlock block;
		block.f(block);
		block.f(MemoryBlock());

	};
};