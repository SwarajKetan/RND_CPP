#pragma once

namespace StateBank {
	class Bank {
	private:
		int m_bal = 0;
		void Print(const char* msg);
	public:
		void Add(int money);
		int Withdraw(int money);
	};
}
// Namespace alias
namespace sb = ::StateBank;