#ifndef ClsPhoneBook_H
#define ClsPhoneBook_H

#include "ClsContact.hpp"

class   ClsPhoneBook
{
private :
    ClsContact _Contacts[8];
    short   _index = 0;

public :

void    AddContact();
void    SearchContact();

};

#endif