#include "Runnable.h"

struct MostVexingParse : public Runnable {

	struct Timer {
		Timer();
	};

	struct TimeKeeper {
		TimeKeeper(const Timer& t);
		int getTime();
	};

	void Run() {

		TimeKeeper time_keeper(Timer()); // here

	};
};