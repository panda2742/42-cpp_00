#include "Account.hpp"
#include <cstring>
#include <ctime>
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
	char		buffer[100];
	std::time_t	now = std::time(NULL);
	std::tm		*ltm = std::localtime(&now);

	bzero(buffer, sizeof(buffer));
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", ltm);

	std::cout << "[" << buffer << "] ";
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
	_totalAmount += initial_deposit;

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
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:";

	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount() const {
	return _amount;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
