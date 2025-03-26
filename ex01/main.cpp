/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:09:16 by ritavasques       #+#    #+#             */
/*   Updated: 2024/07/01 12:19:40 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    std::string command;
    PhoneBook   contacts;

    std::cout << std::endl;
    std::cout << "WELCOME TO YOUR PHONEBOOK" << std::endl;
    while (1)
    {
        std::cout << std::endl;
        std::cout << "1. ADD a new contact" << std::endl;
        std::cout << "2. SEARCH contacts" << std::endl;
        std::cout << "3. EXIT" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your option:" << std::endl;
        getline(std::cin, command);
        if (command == "ADD")
            contacts.createContact();
        else if (command == "SEARCH")
            contacts.searchContact();
        else if (command == "EXIT")
            break ;
        else
            std::cout << "Command not found" << std::endl;
        if (std::cin.eof())
            return (0);
    }
    return (0);
}
