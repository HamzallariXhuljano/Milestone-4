/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhamzall <xhamzall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:17:37 by xhamzall          #+#    #+#             */
/*   Updated: 2025/09/22 16:15:27 by xhamzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex <<";"<< "amount:"<< this->_amount<<";"<<"created"<<std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:"<<this->_accountIndex<<";"
				<<"amount:"<<this->_amount<<";"
				<<"closed"<<std::endl;
}

void	Account::_displayTimestamp( void )
{
	char	timeStr [20];
	time_t	tSecs = 0;
	struct tm *time;

	std::time(&tSecs);
	time = std::localtime(&tSecs);
	std::strftime(timeStr, 20, "[%G%m%d_%H%M%S]", time);
	std::cout << timeStr<<" ";
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout<<"accounts:"<<_nbAccounts<<";"<<"total:"<<_totalAmount<<";"<<"deposits:"<<_totalNbDeposits<<";"<<"withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "index: "<< this->_accountIndex <<";"
				<<"p_amount:"<< this->_amount<<";"
				<<"deposits:"<<deposit<<";"
				<<"amount:"<<this->_amount + deposit<<";"
				<<"nb_deposit:"<<this->_nbDeposits<<std::endl;
}
bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->_amount > withdrawal)
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		std::cout << "index:"<< this->_accountIndex <<";"
					<<"p_amount:"<< this->_amount<<";"
					<<"withdrawals:"<<withdrawal<<";"
					<<"amount:"<<this->_amount - withdrawal<<";"
					<<"nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
		return (true);
	}
	else
		std::cout << "index:"<< this->_accountIndex <<";"
					<<"p_amount:"<< this->_amount<<";"
					<<"withdrawals:refused"<<std::endl;
	return (false);
}

int Account::checkAmount( void ) const
{
	return this->_amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";"
			<<"ammount:"<<this->_amount<<";"
			<<"deposits:"<<this->_nbDeposits<<";"
			<<"withdrawals:"<<this->_nbWithdrawals<<std::endl;
}
