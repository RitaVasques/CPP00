/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rivasque <rivasque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:27 by ritavasques       #+#    #+#             */
/*   Updated: 2024/07/01 12:18:49 by rivasque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
  
  public:
    //CONSTRUCTOR & DESTRUCTOR
    Contact(void);
    ~Contact(void);
    
    //GETTERS
    std::string   getFirstName(void);
    std::string   getLastName(void);
    std::string   getNickname(void);
    std::string   getNumber(void);
    std::string   getDarkestSecret(void);
    void          setFirstName( std::string newName);
    void          setLastName( std::string newLast);
    void          setNick( std::string newNick );
    void          setNumber( std::string newNumber);
    void          setSecret( std::string newSecret);
    
  private:
    std::string   _firstName;
    std::string   _lastName;
    std::string   _nickname;
    std::string   _number;
    std::string   _darkestSecret;
};

#endif