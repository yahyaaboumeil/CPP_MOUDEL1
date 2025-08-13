#include "ClsPhoneBook.hpp" 
#include <iostream>
#include <string>
#include <limits>
#include <cctype> // for std::toupper

std::string ReadChoice()
{
    std::string Ans = "";

    std::cout << "Pleas enter u choice ==>[ADD] || [SEARCH] || [EXIT] ?\n";

    std::getline(std::cin, Ans);
    
    if (std::cin.eof())
        return "EXIT";
    for (int i = 0; Ans[i]; i++)
        Ans[i] = toupper(Ans[i]);
    std::cout << "Ans = " << Ans << std::endl;
    return Ans; 
}

void    Start()
{
    ClsPhoneBook PhoneBook;
    std::string Choice;

    while (true)
    {
        Choice = ReadChoice(); 
        if (Choice == "EXIT")
            break ;
        else if (Choice == "ADD")
            PhoneBook.AddContact();
        else if (Choice == "SEARCH")
            PhoneBook.SearchContact();
        else 
            std::cout << "\n\nUnavailable Choice <_>\n";
    }
}

int main()
{
    Start();
    return 0;
}