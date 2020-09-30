#include "Runnable.h"
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

struct SharedPointers : public Runnable
{
	struct Song {
		const char* name;
		int year;

		Song(const char* name_, int year_) : name(name_), year(year_) {

		}
		~Song() {
			std::cout << "Song " << this->name << " deleted";
		}
	};

	void DoSomething(std::shared_ptr<Song> sRef_) {
		auto s = sRef_;
	}

	void Run()
	{
		std::shared_ptr<Song> sptr1 = std::make_shared<Song>("demoname", 2020);
		std::cout << "use count : " << sptr1.use_count() << std::endl;
		//DoSomething(sptr1);
		std::shared_ptr<Song> sptr2 = sptr1;
		std::cout << "use count : " << sptr1.use_count() << std::endl;
		
		
	}
};