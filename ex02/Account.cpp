#include "Account.hpp"
#include <iostream>

// ************************************************************************** //
//                               Static stuff                                 //
// ************************************************************************** //

// Static attributes
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Static methods
void Account::_displayTimestamp() {
	std::cout << "[19920104_091532] ";
}

// Static getters
int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// ************************************************************************** //
//                               Instance stuff                               //
// ************************************************************************** //

// Constructors & Destructors
Account::Account(int initial_deposit) {
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	(void)_nbDeposits;
	(void)_nbWithdrawals;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << std::endl;
}

Account::Account() {}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount 
			<< ";closed" << std::endl;
}

// Methods
void Account::makeDeposit(int deposit) {
	(void)deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	(void)withdrawal;
	return true;
}

int Account::checkAmount() const {
	return 0;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
