#include "Account.hpp"
#include "Bank.hpp"
#include <iostream>
int main()
{
	Bank::Account bob;

	std::cout << bob << std::endl;
	bob.setId(5);
	bob.setValue(1234);
	std::cout << bob << std::endl;
} 