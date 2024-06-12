/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:14 by ritavasques       #+#    #+#             */
/*   Updated: 2024/06/12 13:31:27 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//CONSTRUCTOR
Contact::Contact(void) {
    
    this->_nbr = -1;
    this->_firstName = "";
    this->_lastName = "";
    this->_nickname = "";
    this->_number = "";
    this->_darkestSecret = "";
}

Contact::Contact(int _nbr, std::string _firstName, std::string _lastName, std::string _nickname, std::string _number, std::string _darkestSecret) {
    this->_nbr = _nbr;
    this->_firstName = _firstName;
    this->_lastName = _lastName;
    this->_nickname = _nickname;
    this->_number = _number;
    this->_darkestSecret = _darkestSecret;
}

//DESTRUCTOR
Contact::~Contact() {
}

//GETTERS
int Contact::getNbr(void) {
    return this->_nbr;
}

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
