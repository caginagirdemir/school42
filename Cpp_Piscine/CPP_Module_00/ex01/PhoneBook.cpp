#include "PhoneBook.hpp"

void PhoneBook::addOne(Contact data)
{
    this->contact_s[this->i % 8] = data;
    this->i++;
}