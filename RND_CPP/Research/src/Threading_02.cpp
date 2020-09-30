#include <unordered_map>
#include "Runnable.h"
#include <future>
#include <string>
struct Threading_02 : public Runnable {

	std::unordered_map<int, int>* map = new std::unordered_map<int, int>();

	void f() {
		int i = 100;
		while (i++ < 200) {
			map->insert({ i, i });
			std::cout << "inserted" << i << "form f" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	};

	void g() {
		int i = 200;
		while (i++ < 300) {
			map->insert({ i, i });
			std::cout << "inserted" << i << "form g" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	};

	void Run() {

		try
		{
			std::async(std::launch::async, [&] { f(); });
			std::async(std::launch::async, [&] { g(); });
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what() << std::endl;
		}

	};

	~Threading_02() {
		delete map;
	}
};