#include "ClsPhoneBook.hpp"

struct stContactInfo
{
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string Phone;
    std::string DarkestSecret;
};

bool    ReadInfo(stContactInfo &Info)
{
    std::system("clear");
    std::cout << "\t" <<  "Read Info Screen\n";
    std::cout << "_____________________________\n";
    std::cout << "Pleas Enter First Name\n";
    getline(std::cin, Info.FirstName);
    if (std::cin.eof())
       return (false);
    std::cout << "Pleas Enter Last Name\n";
    getline(std::cin, Info.LastName);
    if (std::cin.eof())
       return false;
    std::cout << "Pleas Enter Phone\n";
    getline(std::cin, Info.Phone);
    if (std::cin.eof())
       return false;
    std::cout << "Pleas Enter Nick Name\n";
    getline(std::cin, Info.NickName);
    if (std::cin.eof())
       return false;
    std::cout << "Pleas Enter DarkestSecret\n";
    getline(std::cin, Info.DarkestSecret);
    if (std::cin.eof())
       return false;
    std::cout << "_____________________________\n";
    return true;
}

void    ClsPhoneBook::AddContact()
{
    stContactInfo Info;
    bool re;
    short index = 0;

    if (_index > 7)
    {
        short ans;

        std::cout << "pleas enter the index fo contact do you want to replace it (0-7)?\n";
        std::cin >> ans;
        while (std::cin.fail() || !(ans >= 0 && ans <= 7) || std::cin.eof())
        {
            if (std::cin.eof())
                return ;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid choise try again\n"; 
            std::cin >> ans;
        }
        index = ans;
    }
    else
        index = _index;
   re = ReadInfo(Info);
    _Contacts[index].SetFirstName(Info.FirstName);
    _Contacts[index].SetLastName(Info.LastName);
    _Contacts[index].SetNickName(Info.NickName);
    _Contacts[index].SetPhone(Info.Phone);
    _Contacts[index].SetDarkestSecret(Info.DarkestSecret);

    if (!_Contacts[index].CheckIsEmtyObj())
        _index++; 
}

std::string    CheckStrToPrint(std::string Str)
{
    std::string Tmp = Str;

    if (Str.length() >= 10)
        return Tmp.substr(0, 9) + '.';
    return Str;
}

void    PrintContacts(ClsContact Contacts, short i ,bool PrintAll)
{
    std::cout << "_______________________________________________________________\n";
    std::cout << std::setw(10) << std::left << i << "|";
    std::cout << std::setw(10) << std::left << CheckStrToPrint(Contacts.GetFirstName()) << "|";
    std::cout << std::setw(10) << std::left << CheckStrToPrint(Contacts.GetLastName()) << "|";
    std::cout << std::setw(10) << std::left << CheckStrToPrint(Contacts.GetNickName()) << "|"; 
    if (PrintAll)
    {
        std::cout << std::setw(10) << std::left << CheckStrToPrint(Contacts.GetPhone()) << "|";
        std::cout << std::setw(10) << std::left << CheckStrToPrint(Contacts.GetDarkestSecret()) << "|";
    }
    std::cout << "\n_______________________________________________________________\n\n";
}

void   ClsPhoneBook::SearchContact()
{
    if (!_index)
        return ;
    std::system("clear");
    std::cout << std::setw(10) << "Index" << "|"
            << std::setw(10) << "First Name" << "|"
            << std::setw(10) << "Last Name" << "|"
            << std::setw(10) << "Nickname" << "|\n";

    for (int i = 0; i < _index; i++)
        PrintContacts(_Contacts[i], i, false);       

    short Ans = 0;
    std::cout << "Pleas Enter index of a contact to show more detils, if you don't enter -1\n";
    std::cin >> Ans;
    if (Ans == -1)
        return; 
    while (std::cin.fail() || Ans >= _index || Ans < -1)
    {
        if (std::cin.eof())
            return ;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input, Pleas Enter index of a contact to show more detils\n";
        std::cin >> Ans;
    }
    std::system("clear");

    std::cout << std::setw(10) << "Index" << "|"
            << std::setw(10) << "First Name" << "|"
            << std::setw(10) << "Last Name" << "|"
            << std::setw(10) << "Nickname" << "|"
            << std::setw(10) << "phone" << "|"
            << std::setw(10) << "DarkestS." << "|"
            << "\n";
    PrintContacts(_Contacts[Ans], Ans ,true);       

    std::cout << "Press Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}