/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:49:00 by ritavasques       #+#    #+#             */
/*   Updated: 2024/07/01 12:18:16 by rivasque         ###   ########.fr       */
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
        
        std::string trimFirstName( std::string _firstName );
        std::string trimLastName( std::string _lastName );
        std::string trimNickname( std::string nickname );
        void createContact( void );
        void searchContact( void );

    private:
        Contact _contacts[8];
        int     _index;
};

#endif