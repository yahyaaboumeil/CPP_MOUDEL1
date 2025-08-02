#ifndef CLSCONTACT_HPP
#define CLSCONTACT_HPP

#include <iostream>
#include <limits>
#include <iomanip>

class ClsContact
{
private :

    std::string _FirstName;
    std::string _LastName;
    std::string _NickName;
    std::string _Phone;
    std::string _DarkestSecret;

public :

    ClsContact()
    {
        _FirstName = "";
        _LastName = "";
        _NickName = "";
        _Phone = "";
        _DarkestSecret = "";
    }

    void SetFirstName(std::string FirstName);

    void SetLastName(std::string LastName);

    void SetNickName(std::string NickName);

    void SetDarkestSecret(std::string DarkestSecret);

    void SetPhone(std::string Phone);

    //get method
    std::string GetFirstName();

    std::string GetLastName();

    std::string GetNickName();

    std::string GetDarkestSecret();

    std::string GetPhone();
    
    bool  CheckIsEmtyObj(); 
};

#endif