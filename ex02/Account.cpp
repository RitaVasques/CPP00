/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:52:11 by ritavasques       #+#    #+#             */
/*   Updated: 2024/07/01 12:35:54 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//STATIC VARIABLES
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


//CONSTRUCTOR
Account::Account(int initial_deposit) {
    this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

//DESTRUCTOR
Account::~Account(void) {
    Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

//GETTERS
int Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
    return (Account::_totalNbWithdrawals);
}

//OTHER FUNCTIONS
void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl; 
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

int Account::checkAmount(void) const {
	return (this->_amount);
}

void Account::displayStatus(void) const {
    Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	std::time_t actual;
    struct std::tm *curTime;
	
	actual = std::time(NULL);
	curTime = std::localtime(&actual);
	std::cout << "[";
	std::cout << curTime->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << 1 + curTime->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << curTime->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << curTime->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << curTime->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << curTime->tm_sec;
	std::cout << "] ";
	//std::cout << "[19920104_091532] ";
}
