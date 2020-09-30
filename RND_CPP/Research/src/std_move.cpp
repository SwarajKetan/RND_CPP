#include "Runnable.h"
#include <string>
#include <vector>

struct std_move : public Runnable {
	


	virtual void Run() override
	{
		std::string mystr = "Hello world";
		std::vector<std::string> v;

		v.push_back(mystr); // whole string content is copied // expensive
		v.empty();

		v.push_back(std::move(mystr));

		std::cout << mystr << "\n";
	}
};