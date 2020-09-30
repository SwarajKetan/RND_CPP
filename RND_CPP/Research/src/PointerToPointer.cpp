
#include <iostream>
#include <string>

namespace PointerToPointer {

	// not related to pointer
	class Interface {
	public:
		virtual void Print() = 0;
		virtual void Set() = 0;
		virtual ~Interface() {};
	};

	void Client1() {
		//Interface* intrf = new Interface(); // uncomment to see the effect
	}


	void Modify(std::string& s) {
		s += "ku";
	}

	void Modify2(std::string** s) {
		(**s) = "";
	}

	void Clinet() {
		std::string orig = "oi";
		Modify(orig);

		auto x = &orig;
		auto y = &x;
		Modify2(y);
	}
}