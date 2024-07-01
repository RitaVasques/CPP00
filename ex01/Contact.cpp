/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:14 by ritavasques       #+#    #+#             */
/*   Updated: 2024/07/01 12:18:31 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//CONSTRUCTOR
Contact::Contact(void) {
    
    this->_firstName = "";
    this->_lastName = "";
    this->_nickname = "";
    this->_number = "";
    this->_darkestSecret = "";
}

//DESTRUCTOR
Contact::~Contact() {
}

//GETTERS
std::string Contact::getFirstName(void) {
    return this->_firstName;    
}

std::string Contact::getLastName(void) {
    return this->_lastName;
}

std::string Contact::getNickname(void) {
    return this->_nickname;
}

std::string Contact::getDarkestSecret(void) {
    return this->_darkestSecret;
}

std::string Contact::getNumber(void) {
    return this->_number;
}

//SETTERS
void Contact::setFirstName( std::string newName) {
    this->_firstName = newName;
}

void Contact::setLastName( std::string newLast) {
    this->_lastName = newLast;
}

void Contact::setNick ( std::string newNick ) {
    this->_nickname = newNick;
}

void Contact::setNumber( std::string newNumber) {
    this->_number = newNumber;
}

void Contact::setSecret( std::string newSecret) {
    this->_darkestSecret = newSecret;
}
