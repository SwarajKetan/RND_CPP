#include "Runnable.h"
#include <iostream>

struct MoveConstructor : public Runnable {

	struct Box {
		
		Box(int height, int width)
		:h(height), w(width){
		};

		/*Box(const Box& box) noexcept 
			:h(box.h), w(box.w)
		{
			std::cout << "copy constructor called" << std::endl;
		}*/

		/*Box(Box&& box) noexcept
			: h(box.h), w(box.w)
		{
			std::cout << "move constructor called" << std::endl;
		}*/

		

		int h;
		int w;
	};
	Box getANewBox() {
		auto o = Box(78, 90);
		std::cout << "addr of o : " << &o << std::endl;
		return o;
	}

	void Run() {

		Box b(5,10);
		//Box b1(b);
		Box b2(getANewBox());
		std::cout << "addr of b2 : " << &b2 << std::endl;
		std::cout << "b2 : " << b2.h << " , " << b2.w << std::endl;
	};
};