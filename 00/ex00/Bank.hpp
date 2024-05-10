#pragma once

#include <iostream>
#include <map>
#include "Account.hpp"
#include <exception>
#include <sstream>

struct Bank
{
private:
class Account
	{
		friend Bank;
	private:
		int _id;
		unsigned int _value;
		unsigned int _loaned;

	public:
		const int& getId() const;
		const unsigned int& getValue() const;
		const unsigned int& getLoaned() const;
	};


	int _liquidity;
	std::map<int, Account*> _clientAccounts;

public:
	Bank();
	int& getLiquidity();
	const int& getLiquidity() const;
	void setLiquidity(const int& liquidity);
	std::map<int, Account*>& getClientAccounts();
	const std::map<int, Account*>& getClientAccounts() const;
	void setClientAccounts(std::map<int, Account*> clientAccounts);
	Account* operator[](int id);
	void createAccount(int id);
	void deleteAccount(int id);
	void modifyAccount(int id, int newId, unsigned int newValue, unsigned int newLoaned);
	void depositToAccount(int id, unsigned int value);
	void withdrawFromAccount(int id, unsigned int value);
	void giveLoan(int id, unsigned int value);
	void reclaimLoan(int id, unsigned int value);
	class DuplicateIdException : public std::exception
	{
	private:
		int _id;
	public:
		DuplicateIdException(int id) : _id(id) {}
		const char *what() const throw();
	};
	class IdNotFoundException : public std::exception
	{
	private:
		int _id;
	public:
		IdNotFoundException(int id) : _id(id) {}
		const char *what() const throw();
	};
	class InsufficientFundsException: public std::exception
	{
	public:
		const char *what() const throw();
	};

	friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);
};
