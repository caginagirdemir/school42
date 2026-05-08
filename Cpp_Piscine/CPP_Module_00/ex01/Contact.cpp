#include "Contact.hpp"

std::string Contact::get_secret_value() {
    return this->secret_value;
}

void    Contact::set_secret_value(std::string value) {
    this->secret_value = value;
}