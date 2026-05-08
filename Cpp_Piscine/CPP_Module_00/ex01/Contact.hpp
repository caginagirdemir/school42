#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
    public:
        std::string firstname; // Contact c -> c.firstname
        std::string surname; // Contact c -> c.surname
        std::string nickname; // Contact c -> c.nickname
        std::string phonenumber; // Contact c -> c.phonenumber

        //functions
        std::string get_secret_value(); 
        void        set_secret_value(std::string value);
    
    private:
        std::string secret_value; // Contact c -> c.darkestSecret
};

#endif