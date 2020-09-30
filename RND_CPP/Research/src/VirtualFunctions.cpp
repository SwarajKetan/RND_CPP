#include "Runnable.h"
#include <vector>
#include <algorithm>
using namespace std;

struct VirtualFunctions : public Runnable {

    

    class Account {
    public:
        Account(double d) { _balance = d; }
        virtual ~Account() {}
        virtual double GetBalance() { return _balance; }
        virtual void PrintBalance() { cerr << "Error. Balance not available for base type." << endl; }
    private:
        double _balance;
    };

    class CheckingAccount : public Account {
    public:
        CheckingAccount(double d) : Account(d) {}
        void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
    };

    class SavingsAccount : public Account {
    public:
        SavingsAccount(double d) : Account(d) {}
        void PrintBalance() { cout << "Savings account balance: " << GetBalance(); }
    };


	void Run() {

        std::vector<int> v;
        std::vector<int>::iterator it;

        it = std::find(v.begin(), v.end(), 20);

        std::binary_search(v.begin(), v.end(), 50);

        // Create objects of type CheckingAccount and SavingsAccount.
        CheckingAccount checking(100.00);
        SavingsAccount  savings(1000.00);

        // Call PrintBalance using a pointer to Account.
        Account* pAccount = &checking;
        pAccount->PrintBalance();

        // Call PrintBalance using a pointer to Account.
        pAccount = &savings;
        pAccount->PrintBalance();

	};
};