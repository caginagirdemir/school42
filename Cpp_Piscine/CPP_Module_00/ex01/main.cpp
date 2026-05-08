#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void    check_10_print(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".|";
    else
        std::cout << str <<  std::string((10 - str.length()), ' ') << "|";
}

void    Print_Book_Contacts(PhoneBook book_data, int index)
{
        std::cout << index << "         |"; //10 char length
        check_10_print(book_data.contact_s[index].firstname);
        check_10_print(book_data.contact_s[index].surname);
        check_10_print(book_data.contact_s[index].nickname);
        std::cout << std::endl;
}

void    Print_one_contact(Contact data)
{
    std::cout << "---------Contact---------" << std::endl;
    std::cout << "Firstname : " << data.firstname << std::endl;
    std::cout << "Surname   : " << data.surname << std::endl;
    std::cout << "Nickname  : " << data.nickname << std::endl;
    std::cout << "Phone     : " << data.phonenumber << std::endl;
    std::cout << "Secret Val: " << data.get_secret_value() << std::endl;
    std::cout << "-------------------------" << std::endl;
}

int main(void)
{
    std::string command;
    std::string secret_val;
    PhoneBook   Book;
    int         ind;

    while (1)
    {
        //std::cout << ">";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            Contact new_contact;
            std::cout << "Type in firstname of your Contact" << std::endl;
            while(new_contact.firstname == "")
                std::getline(std::cin, new_contact.firstname);
            std::cout << "Type in surname of your Contact" << std::endl;
            while(new_contact.surname == "")
                std::getline(std::cin, new_contact.surname);
            std::cout << "Type in nickname of your Contact" << std::endl;
            while(new_contact.nickname == "")
                std::getline(std::cin, new_contact.nickname);
            std::cout << "Type in phone of your Contact" << std::endl;
            while(new_contact.phonenumber == "")
                std::getline(std::cin, new_contact.phonenumber);
            std::cout << "Secret Value, Don't forget this value keep secret..." << std::endl;
            while(secret_val == "")
                std::getline(std::cin, secret_val);
            new_contact.set_secret_value(secret_val);
            secret_val = "";
            Book.addOne(new_contact);
            Print_one_contact(new_contact);
        }
        else if (command == "SEARCH")
        {
            int i = -1;
            while(++i < 8)
                if(i < Book.i)
                    Print_Book_Contacts(Book, i);
                else
                    break;
            
            ind = -1;
            std::cout << "type contact number you want to see" << std::endl;
            std::cin >> ind;
            if(std::cin.fail())
            {
                std::cout << "Non-numeric assignment\n";
                std::cin.clear();
                ind = -1;
            }
            if (ind >= 0 && ind < 8)
            {
                Print_one_contact(Book.contact_s[ind]);
                std::cout << std::endl;
            }
            else if (ind != -1)
            {
                std::cout << "There is nothing such as a contact number. Or non-numeric assingment" << std::endl;
                std::cout << std::endl;
            }
        }
        else if (command == "EXIT")
            break;
        //std::cout << command << std::endl;
    }
    return (0);
}