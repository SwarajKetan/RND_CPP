#pragma once
#include "Runnable.h"
#include <string>

struct LValueRValue : public Runnable {

	void MyFun_01(std::string& s) {

	};


	void MyFun_03(const std::string& s) {

	};

	void MyFun_02(std::string&& s) {

	};

	void Run() {
		std::string a = "abc";
		std::string b = "def";

		MyFun_02(a + b);
		MyFun_03(a + b);

		auto c = a + b;
		MyFun_01(c);

	};
};
