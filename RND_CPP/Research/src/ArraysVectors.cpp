#include "Runnable.h"
struct ArraysVectors : public Runnable
{
	struct Account { 	
		Account(int id) : id(id) {}
		int id; 
	};

	Account** account;

	void CreateArrayAtRuntime(int size) {
		account = new Account* [size];
	};

	void Run() {
		CreateArrayAtRuntime(3);
		account[0] = new Account(100);
		account[1] = new Account(200);
		account[2] = new Account(300);

		while (account != nullptr) {
			std::cout << (*account)->id << std::endl;
			account++;
		}
	};
};