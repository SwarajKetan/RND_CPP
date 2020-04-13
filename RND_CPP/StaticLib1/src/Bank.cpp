// StaticLib1.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include <iostream>
#include "Bank.h"
#include <string>

void sb::Bank::Add(int money) {
	Print("money added");
	m_bal += money;
}

int sb::Bank::Withdraw(int money) {
	if (m_bal >= money) {
		m_bal -= money;
		Print("Remainig :: " );
		return money;
	}
	int r = m_bal;
	m_bal = 0;
	Print("Remainig :: ");
	return r;
}

void sb::Bank::Print(const char* msg) {
	std::cout << msg << std::endl;
}
