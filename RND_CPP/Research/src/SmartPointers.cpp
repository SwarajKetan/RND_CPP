#include "Runnable.h"
#include <memory>

struct SmartPointers : public Runnable {

	struct Song {
		const char* name;
		Song(const char* name) : name(name) {

		}
		~Song() {
			std::cout << "Song deleted" << std::endl;
		}
	};


	void SomeMethod(const Song& s) {
		Song ks = s;

	}

	void Scoping() {
		std::unique_ptr<Song> song3(new Song("song3"));
		SomeMethod(*song3);
	}

	void Run() {

		auto up = std::make_unique<int>();
		std::unique_ptr<int> uptr;

		std::unique_ptr<Song> song2(new Song("some song"));
		std::cout << song2->name << std::endl;

		Scoping();
	};
};