#include <iostream>
#include <string>
#include <string_view>
#include "Runnable.h"

namespace String_View_Experiments {

	static uint32_t allocationCount = 0;
	struct StringViewExperiments : public Runnable {

		void* operator new(size_t size) {
			allocationCount++;
			std::cout << "Allocating " << size << " bytes\n";
			return malloc(size);
		}


		void PrintName(const std::string& name) {
			std::cout << name << std::endl;
		}

		void PrintName2(std::string_view name) {
			std::cout << name << std::endl;
		}



		void Client() {
			//std::string name = "Swaraj Ketan";
			const char* name = "Swaraj Ketan";
			std::string_view* first = new std::string_view(name, 6);
			std::string_view* last = new std::string_view(name + 7, 5);
			PrintName2(*first);
			PrintName2(*last);
		}


		// Inherited via Runnable
		virtual void Run() override
		{
			Client();
		}
	};
}