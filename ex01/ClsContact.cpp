#include "ClsContact.hpp" 

void ClsContact::SetFirstName(std::string FirstName)
{
    _FirstName = FirstName;
}

void ClsContact::SetLastName(std::string LastName)
{
    _LastName = LastName;
}

void ClsContact::SetNickName(std::string NickName)
{
    _NickName = NickName;
}

void ClsContact::SetDarkestSecret(std::string DarkestSecret)
{
    _DarkestSecret = DarkestSecret;
}

void ClsContact::SetPhone(std::string Phone)
{
    _Phone = Phone;
}

//get method
std::string ClsContact::GetFirstName()
{
    return _FirstName;
}

std::string ClsContact::GetLastName()
{
    return _LastName;
}

std::string ClsContact::GetNickName()
{
    return _NickName;
}

std::string ClsContact::GetDarkestSecret()
{
    return _DarkestSecret;
}

std::string ClsContact::GetPhone()
{
    return _Phone;
}
    
//check is this class full
bool  ClsContact::CheckIsEmtyObj() 
{
    return (_FirstName == "" || _LastName == "" || _NickName == "" || 
        _Phone == "" || _DarkestSecret == "");
}

