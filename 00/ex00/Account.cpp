#include "Bank.hpp"
#include <utility>

const int& Bank::Account::getId() const
{
	return _id;
}

const unsigned int& Bank::Account::getValue() const 
{
	return _value;
}

const unsigned int& Bank::Account::getLoans() const
{
	return _loans;
}