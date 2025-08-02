#include "Account.hpp"
#include <iostream>

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

void	Account::displayAccountsInfos( void )
{
    std::cout << "Account Number : " << getNbAccounts(); 
    std::cout << "Total Amount : " << getTotalAmount();
    std::cout << "Deposits Number : " ;
    std::cout << "With Drawals : " << getNbWithdrawals();
}
