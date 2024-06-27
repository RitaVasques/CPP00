/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:48:36 by ritavasques       #+#    #+#             */
/*   Updated: 2024/06/27 18:42:25 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//CONSTRUCTOR & DESTRUCTOR
PhoneBook::PhoneBook() {
    this->total = 0;
}

PhoneBook::~PhoneBook() {
}

//GETTERS
Contact PhoneBook::getContact(int i) {
    return this->_contacts[i];
}

int PhoneBook::getTotal(void) {
    return this->total;
}

//ADD CONTACT
void PhoneBook::addContact(void) {
    int i = getTotal();
    
    this->_contacts[i % 8] = createContact(i % 8);
    this->total++;
}

//10 CHARACTERS WIDE
std::string PhoneBook::trimFirstName(std::string newName)
{
    std::string name = "";
    
    if (newName.size() < 10)
    {
        for (unsigned long i = 0; i < newName.size(); i++)
            name += newName[i];
    }
    else
    {
        for (int i = 0; i < 9; i++)
            name += newName[i];
        name += ".";
    }
    return (name);
}

std::string PhoneBook::trimLastName(std::string newLast)
{
    std::string last;
    
    if (newLast.size() < 10)
    {
        for (unsigned long i = 0; i < newLast.size(); i++)
            last += newLast[i];
    }
    else
    {
        for (int i = 0; i < 9; i++)
            last += newLast[i];
        last += ".";
    }
    return (last);
}
std::string PhoneBook::trimNickname(std::string newNickname)
{
    std::string nn;
    
    if (newNickname.size() < 10)
    {
        for (unsigned long i = 0; i < newNickname.size(); i++)
            nn += newNickname[i];
    }
    else
    {
        for (int i = 0; i < 9; i++)
            nn += newNickname[i];
        nn += ".";
    }
    return (nn);
}

int PhoneBook::isNumeric(std::string number) {
    for (int i = 0; i < number.size(); i++) {
        if (number[i] <= '0' || number[i] >= 9)
            return (1);
    }
    return (0);
}

//CREATE NEW CONTACT
Contact PhoneBook::createContact(int i) {
    
    std::string new_name;
    std::string new_last;
    std::string new_nickname;
    std::string new_number;
    std::string new_secret;
  
    std::cout << "CREATE NEW CONTACT" << std::endl;
    std::cout << "Enter First Name:" << std::endl;
    getline(std::cin, new_name);
    while (new_name == "")
    {
        std::cout << "Field cannot be empty" << std::endl;
        std::cout << "Enter First Name:" << std::endl;
        getline(std::cin, new_name);
    }
    std::cout << "Enter Last Name:" << std::endl;
    getline(std::cin, new_last);
    while (new_last == "")
    {
        std::cout << "Field cannot be empty" << std::endl;
        std::cout << "Enter Last Name:" << std::endl;
        getline(std::cin, new_last);
    }
    std::cout << "Enter Nickname:" << std::endl;
    getline(std::cin, new_nickname);
    while (new_nickname == "")
    {
        std::cout << "Field cannot be empty" << std::endl;
        std::cout << "Enter Nickname:" << std::endl;
        getline(std::cin, new_nickname);
    }
    std::cout << "Enter Number:" << std::endl;
    getline(std::cin, new_number);
    while (isNumeric(new_number))
    {
        std::cout << "Incorrect! Enter only digits" << std::endl;
        std::cout << "Enter Number:" << std::endl;
        getline(std::cin, new_number);
    } 
    std::cout << "Enter Darkest Secret:" << std::endl;
    getline(std::cin, new_secret);
    while (new_secret == "")
    {
        std::cout << "Field cannot be empty" << std::endl;
        std::cout << "Enter Darkest Secret:" << std::endl;
        getline(std::cin, new_secret);
    }
    Contact new_contact(i, new_name, new_last, new_nickname, new_number, new_secret);
    return (new_contact);
}

//SEARCH CONTACT
void PhoneBook::searchContact(void) {

    std::string index;
    
    /*Dispay all contacts*/
    if (getTotal() == 0)
    {
        std::cout << "No Contacts" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        for (int i = 0; i < 8; ++i)
        {
            std::cout << std::setfill(' ') << std::setw(10) << std::right << i << "|";
            std::cout << std::setfill(' ') << std::setw(10) << std::right << trimFirstName(getContact(i).getFirstName()) << "|";
            std::cout << std::setfill(' ') << std::setw(10) << std::right << trimLastName(getContact(i).getLastName()) << "|";
            std::cout << std::setfill(' ') << std::setw(10) << std::right << trimNickname(getContact(i).getNickname()) << std::endl;
        }
        std::cout << "Enter de index of contact:" << std::endl;
        getline(std::cin, index);
        int idx = index[0] - '0';
        if (idx >= 0 && idx < getTotal())
        {
            std::cout << std::endl;
            std::cout << "Index:" << idx << std::endl;
            std::cout << "First Name: " << getContact(idx).getFirstName() << std::endl;
            std::cout << "Last Name: " << getContact(idx).getLastName() << std::endl;
            std::cout << "Nickname: " << getContact(idx).getNickname() << std::endl;
            std::cout << "Number: " << getContact(idx).getNumber() << std::endl;
            std::cout << "Darkest Secret: " << getContact(idx).getDarkestSecret() << std::endl;
            std::cout << std::endl;
        }
        else
            std::cout << "Please enter a valid index" << std::endl;
        index = "";
    }
}
