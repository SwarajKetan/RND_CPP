#pragma once
#include "Runnable.h"
#include <string>

struct LValueRValue : public Runnable {


	struct Some {
		int name;
	};

	Some& DonotDoThis() {
		Some s;
		return s;
	}


	void MyFun_01(std::string& s) {
		std::cout << s << " " << &s << std::endl;
	};


	void MyFun_03(const std::string& s) {

	};

	void MyFun_02(std::string&& s) {
		std::cout << s << " " << &s << std::endl;
	};

	void Run() {
		/*std::string a = "abc";
		std::string b = "def";

		MyFun_02(a + b);
		MyFun_03(a + b);

		auto c = a + b;
		MyFun_01(c);*/


		std::string xyz = "bbhh";
		MyFun_01(xyz);
		MyFun_02(std::move(xyz));
		MyFun_02("gg");

		auto ref = DonotDoThis();
	
	};
};
