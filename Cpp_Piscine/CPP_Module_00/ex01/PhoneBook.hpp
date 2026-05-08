#pragma once
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
    public:
        Contact contact_s[8]; // Contact c -> c.contact_s[i]
        
        void    addOne(Contact data);
        int i = 0;
};

#endif