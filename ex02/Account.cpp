/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:59:16 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/22 18:36:06 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << " index:"  << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
    return (_totalAmount);
}
int	Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:"    << getNbAccounts()
              << ";total:"       << getTotalAmount()
              << ";deposits:"    << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    int p_amount;

    _displayTimestamp();
    p_amount = _amount;
    _amount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;
    _totalAmount += deposit;
    std::cout << " index:"       << _accountIndex
              << ";p_amount:"    << p_amount
              << ";deposit:"     << deposit
              << ";amount:"      << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount;
    
    _displayTimestamp();
    p_amount = _amount;
    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << " index:"          << _accountIndex
                  << ";p_amount:"       << p_amount
                  << ";withdrawal:"     << withdrawal
                  << ";amount:"         << _amount
                  << ";nb_Withdrawals:" << _nbWithdrawals
                  << std::endl;
        return (true);
    }
    std::cout << " index:"             << _accountIndex
              << ";p_amount:"          << _amount
              << ";withdrawal:refused" << std::endl;
    return (false);
}

int		Account::checkAmount(void) const
{
    return (_amount);
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:"       << _accountIndex
              << ";amount:"      << _amount
              << ";deposits:"    << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:"  << _accountIndex
              << ";amount:" << _amount
              << ";closed"  << std::endl;
}
void Account::_displayTimestamp(void)
{
    std::time_t t;
    std::tm *now;
    
    t = std::time(NULL);
    now = std::localtime(&t);

    std::cout << "[" 
              << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << now->tm_mon +1
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "]";
}
