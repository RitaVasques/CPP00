/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:48:36 by ritavasques       #+#    #+#             */
/*   Updated: 2024/07/01 12:31:53 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//CONSTRUCTOR & DESTRUCTOR
PhoneBook::PhoneBook() {
    this->_index = 0;
}

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook destroyed" << std::endl;
}

//GETTERS
Contact PhoneBook::getContact(int i) {
    return this->_contacts[i];
}

int PhoneBook::getTotal(void) {
    return this->_index;
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

//CREATE NEW CONTACT
void PhoneBook::createContact( void ) {
    
    std::string newName;
    std::string newLast;
    std::string newNickname;
    std::string newNumber;
    std::string newSecret;
  
    std::cout << "CREATE NEW CONTACT" << std::endl;
    newName = "";
    while (!std::cin.eof() && newName == "")
    {
        std::cout << "Enter First Name:" << std::endl;
        if (getline(std::cin, newName) && newName != "")
            this->_contacts[this->_index % 8].setFirstName(newName);
        else
            std::cout << "Field cannot be empty" << std::endl;
    }
    newLast = "";
    while (!std::cin.eof() && newLast == "")
    {
        std::cout << "Enter Last Name:" << std::endl;
        if (getline(std::cin, newLast) && newLast != "")
            this->_contacts[this->_index % 8].setLastName(newLast);
        else
            std::cout << "Field cannot be empty" << std::endl;
    }
    newNickname = "";
    while (!std::cin.eof() && newNickname == "")
    {
        std::cout << "Enter Nickname:" << std::endl;
        if (getline(std::cin, newNickname) && newNickname != "")
            this->_contacts[this->_index % 8].setNick(newNickname);
        else
            std::cout << "Field cannot be empty" << std::endl;
    }
    newNumber = "";
    while (!std::cin.eof() && newNumber == "")
    {
        std::cout << "Enter Number:" << std::endl;
        if (getline(std::cin, newNumber) && newNumber != "")
            this->_contacts[this->_index % 8].setNumber(newNumber);
        else
            std::cout << "Field cannot be empty" << std::endl;
    } 
    newSecret = "";
    while (!std::cin.eof() && newSecret == "")
    {
        std::cout << "Enter Darkest Secret:" << std::endl;
        if (getline(std::cin, newSecret) && newSecret != "")
            this->_contacts[this->_index % 8].setSecret(newSecret);
        else
            std::cout << "Field cannot be empty" << std::endl;
    }
    this->_index++;
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
        for (unsigned int i = 0; i < 8; ++i)
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
