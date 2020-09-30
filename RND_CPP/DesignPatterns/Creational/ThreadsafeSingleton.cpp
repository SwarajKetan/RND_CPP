#include <mutex>
#include <thread>
#include <string>
#include <ctime>
#include <utility>

class Singleton
{
private:
	static Singleton* pInstance_;
	static std::mutex mutex_;
	Singleton() {

	}

	void operator delete(void*) {};

public:
	Singleton(Singleton&) = delete; // Copy prohibited
	void operator=(const Singleton&) = delete; // Assignment prohibited
	//Singleton& operator=(Singleton&&) = delete; // Move assignment

	static Singleton* GetInstance();
	static Singleton& GetInstanceRef();
	static void Dispose();

	std::string GetTime() const {
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		return std::ctime(&now);
	};

};

Singleton* Singleton::GetInstance() {
	if (pInstance_ == nullptr) {
		std::lock_guard<std::mutex> lock(mutex_);
		if (pInstance_ == nullptr)
			pInstance_ = new Singleton();
	}
	return pInstance_;
}

Singleton& Singleton::GetInstanceRef() {
	if (pInstance_ == nullptr) {
		std::lock_guard<std::mutex> lock(mutex_);
		if (pInstance_ == nullptr)
			pInstance_ = new Singleton();
	}
	return *pInstance_;
}

void Singleton::Dispose() {
	delete pInstance_;
}

struct X {

	X& operator=(X&&) = delete;

};


void Thread1() {
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	Singleton* sing1 = Singleton::GetInstance();
	Singleton& singRef = Singleton::GetInstanceRef();
	Singleton::GetInstance()->GetTime();
	Singleton::GetInstanceRef().GetTime();

	/*std::string x;
	std::string y;
	x = std::move(y);*/

	X x;
	X y;
	//x = std::move(y);
}