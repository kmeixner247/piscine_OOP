#include "Bank.hpp"
#include <iostream>
int main()
{
	Bank bank;

	bank.createAccount(0);
	bank.depositToAccount(0, 1000000);
	bank.createAccount(1);
	bank.depositToAccount(1, 25000);
	bank.giveLoan(1, 1250);
	std::cout << bank;
} 