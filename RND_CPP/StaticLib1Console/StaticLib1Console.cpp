// StaticLib1Console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Bank.h"

int main()
{
    sb::Bank* bank = new sb::Bank();
    bank->Add(100);
    bank->Withdraw(90);
    return std::getchar();
}
