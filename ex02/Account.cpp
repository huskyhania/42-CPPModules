#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account()
{
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}
Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 1;
	_nbWithdrawals = 0;
}

int Account::getNbAccounts(void)
{
	_displayTimestamp();
	std::cout << "getNbAccounts\n";
	return (0);
}

int Account::getTotalAmount(void)
{
	_displayTimestamp();
	std::cout << "getTotalAmount\n";
	return (0);
}

int Account::getNbDeposits(void)
{
	_displayTimestamp();
	std::cout << "getNbDeposits\n";
	return (0);
}

int Account::getNbWithdrawals(void)
{
	_displayTimestamp();
	std::cout << "getNbWithdrawals\n";
	return (0);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "displayAccountsInfos\n";
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "makeDeposits\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "makeWithdrawal\n";
	return (true);
}

int Account::checkAmount(void) const
{
	_displayTimestamp();
	std::cout << "checkAmount\n";
	return (0);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "displayStatus\n";
}

void	Account::_displayTimestamp(void)
{
	char output[18];
	time_t timeCheck = std::time(NULL);
	std::strftime(output, 18, "%Y%m%d_%H%M%S",std::localtime(&timeCheck));
	std::cout << "[" << output << "] ";
}

Account::~Account() 
{
}