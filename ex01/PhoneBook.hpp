/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:49:00 by ritavasques       #+#    #+#             */
/*   Updated: 2024/06/12 14:13:37 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {
    
    public:
        //CONSTRUCTOR & DESTRUCTOR
        PhoneBook();
        ~PhoneBook();
        
        //GETTERS
        Contact getContact(int i);
        int getTotal(void);
        
        std::string trimFirstName(std::string _firstName);
        std::string trimLastName(std::string _lastName);
        std::string trimNickname(std::string nickname);
        Contact createContact(int i);
        void searchContact(void);
        void addContact(void);        

    private:
        Contact _contacts[8];
        int     total;
};

#endif