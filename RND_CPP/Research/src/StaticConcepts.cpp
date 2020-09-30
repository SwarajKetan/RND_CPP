#include "Runnable.h"

struct StaticConcepts : public Runnable {

	void Print() {
		static int num = 100;
	};

	// Inherited via Runnable
	virtual void Run() override
	{
		//static int num = 100;
	}
};