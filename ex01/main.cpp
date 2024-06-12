/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:09:16 by ritavasques       #+#    #+#             */
/*   Updated: 2024/06/12 13:30:31 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    std::string command;
    PhoneBook   contacts;

    std::cout << "WELCOME TO YOUR PHONEBOOK" << std::endl;
    while (1)
    {
        std::cout << "1. ADD a new contact" << std::endl;
        std::cout << "2. SEARCH contacts" << std::endl;
        std::cout << "3. EXIT" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter your option:" << std::endl;
        getline(std::cin, command);
        system("clear");
        if (command == "ADD" || command[0] == '1')
            contacts.addContact();
        else if (command == "SEARCH" || command[0] == '2')
            contacts.searchContact();
        else if (command == "EXIT" || command[0] == '3')
            break ;
        else
            std::cout << "Command not found" << std::endl;
    }
    return (0);
}
