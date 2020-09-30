#include "Runnable.h"
#include <assert.h>
struct usageOfdeclspec : public Runnable {

private:
	int _age = 0;
	void putage(int age_) {
		_age = age_ + 5;
	};

	int getage() {
		return _age;
	}

public:

	__declspec(property(get = getage, put = putage))
		int age;

	__declspec(deprecated("my ununsed function."))
	void MyOldFunction() {

	};

	// Inherited via Runnable
	virtual void Run() override
	{
		usageOfdeclspec usage;
		usage.age = 5;
		assert(usage.age == 10);

		std::cout << __func__ << std::endl;
		//MyOldFunction();
	}
};