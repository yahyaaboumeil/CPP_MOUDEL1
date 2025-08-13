// #include "Account.hpp"
// #include <iostream>

// Account::Account( int initial_deposit )
// {
//     _amount = initial_deposit;
//     _nbDeposits = 0;
//     _nbWithdrawals = 0;

//     std::cout << "[" << "]" << " index:" << _accountIndex << ";amount:" << initial_deposit
//         << ";created\n";
// }

// Account::~Account()
// {
//     std::cout << "[" << "]" << " index:" << _accountIndex << ";amount:" << _nbDeposits
//         << ";closed\n";
// }

// //static functions

// int	Account::getNbAccounts( void )
// {
//     return Account::_nbAccounts;
// }
// int	Account::getTotalAmount( void )
// {
//     return Account::_totalAmount;
// }

// int	Account::getNbDeposits( void )
// {
//     return Account::_totalNbDeposits;
// }

// int	Account::getNbWithdrawals( void )
// {
//     return Account::_totalNbWithdrawals;
// }

// void	Account::displayAccountsInfos( void )
// {
//     std::cout << "[" << "]" << "accounts:" << Account::getNbAccounts() << ";total:" << Account::getTotalAmount()
//               << ";deposeits:" << getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals();
// }
// //static functions

// bool	Account::makeWithdrawal( int withdrawal )
// {
//     _nbWithdrawals = withdrawal;
//     return true;
// }

// int		Account::checkAmount( void ) const
// {
//     return _amount;
// }

// void	Account::displayStatus( void ) const
// {
//     std::cout << "[" << "]" << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:"
//     << _nbDeposits << ";withdrawals:" << _nbWithdrawals;
// }

// void    Account::makeDeposit(int deposit)
// {
//     _nbDeposits = deposit;
// }

#include "Account.hpp"
#include <iostream>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(nullptr);
    std::tm *ltm = std::localtime(&now);

    std::cout << "["
              << 1900 + ltm->tm_year
              << (ltm->tm_mon + 1 < 10 ? "0" : "") << ltm->tm_mon + 1
              << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday
              << "_"
              << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
              << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
              << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
              << "]";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts; 
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp(); 
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";created\n";
}

Account::~Account()
{
    _displayTimestamp();
    std::cout
            << " index:" << _accountIndex
            << ";amount:" << _amount
            << ";closed\n";
}

// static functions
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << "\n";
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout 
              << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << "\n";
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        std::cout << " index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused\n";
        return false;
    }

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:" << withdrawal;

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << "\n";

    return true;
}

