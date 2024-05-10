#include "Bank.hpp"

Bank::Bank() : _liquidity(0)
{
}

int& Bank::getLiquidity()
{
	return _liquidity;
}

const int& Bank::getLiquidity() const
{
	return _liquidity;
}

void Bank::setLiquidity(const int& liquidity)
{
	_liquidity = liquidity;
}
std::map<int, Bank::Account*>& Bank::getClientAccounts() 
{
	return _clientAccounts;
}
const std::map<int, Bank::Account*>& Bank::getClientAccounts() const 
{
	return _clientAccounts;
}

void Bank::setClientAccounts(std::map<int, Bank::Account*> clientAccounts) 
{
	_clientAccounts = clientAccounts;
}

Bank::Account* Bank::operator[](int id) 
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);
	if (it == _clientAccounts.end())
	{
		throw IdNotFoundException(id);
	}
	return it->second;	
}

void Bank::createAccount(int id)
{
	if (_clientAccounts.find(id) != _clientAccounts.end())
	{
		throw DuplicateIdException(id);
	}
	Account* newAccount = new Account();
	newAccount->_id = id;
	_clientAccounts.insert(std::make_pair(id, newAccount));
}

void Bank::deleteAccount(int id)
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);
	if (it == _clientAccounts.end())
	{
		throw IdNotFoundException(id);
	}
	_clientAccounts.erase(it);
}

void Bank::modifyAccount(int id, int newId, unsigned int newValue, unsigned int newLoans)
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);
	if (it == _clientAccounts.end())
	{
		throw IdNotFoundException(id);
	}
	if (_clientAccounts.find(newId) != _clientAccounts.end())
	{
		throw DuplicateIdException(newId);
	}
	Account* account = it->second;
	account->_id = newId;
	account->_value = newValue;
	account->_loans = newLoans;
}

void Bank::depositToAccount(int id, unsigned int value)
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);
	if (it == _clientAccounts.end())
	{
		throw IdNotFoundException(id);
	}
	Account *account = it->second;
	unsigned int fee = (value * 5) / 100;
	_liquidity += fee;
	account->_value += value - fee;
}

void Bank::withdrawFromAccount(int id, unsigned int value)
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);
	if (it == _clientAccounts.end())
	{
		throw IdNotFoundException(id);
	}
	Account *account = it->second;
	if (account->_value < value)
	{
		throw InsufficientFundsException();
	}
	else
	{
		account->_value -= value;
	}
}

void Bank::giveLoan(int id, unsigned int value)
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);
	if (it == _clientAccounts.end())
	{
		throw IdNotFoundException(id);
	}
	if (value > _liquidity)
	{
		throw InsufficientFundsException();
	}
	Account* account = it->second;
	account->_value += value;
	account->_loans += value;
	_liquidity -= value;
}

void Bank::reclaimLoan(int id, unsigned int value)
{
	std::map<int, Account*>::iterator it = _clientAccounts.find(id);
	if (it == _clientAccounts.end())
	{
		throw IdNotFoundException(id);
	}
	Account* account = it->second;
	if (value < account->_loans)
	{
		value = account->_loans;
	}
	if (value > account->_value)
	{
		throw InsufficientFundsException();
	}
	account->_value -= value;
	account->_loans -= value;
	_liquidity += value;
}

std::ostream& operator<<(std::ostream& p_os, const Bank::Account& p_account)
{
	p_os << "[id: " << p_account.getId() << "] - [balance: " << p_account.getValue() << "] - [loans: " << p_account.getLoans();
	return p_os;
}

std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank._liquidity << std::endl;
	for (auto &clientAccount : p_bank._clientAccounts)
		p_os << clientAccount.second << std::endl;
	return p_os;
}

const char* Bank::DuplicateIdException::what() const throw()
{
	std::stringstream ss;
	ss << "ID " << _id << "already exists!";
	return ss.str().c_str();
}

const char* Bank::IdNotFoundException::what() const throw()
{
	std::stringstream ss;
	ss << "ID " << _id << "not found!";
	return ss.str().c_str();
}

const char* Bank::InsufficientFundsException::what() const throw()
{
	return "Insufficient funds!";
}