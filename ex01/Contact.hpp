/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:54:27 by ritavasques       #+#    #+#             */
/*   Updated: 2024/06/12 13:01:20 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
  
  public:
    //CONSTRUCTOR & DESTRUCTOR
    Contact(void);
    Contact(int _nbr, std::string _firstName, std::string _lastName, std::string _nickname, std::string _number, std::string _darkestSecret);
    ~Contact(void);
    
    //GETTERS
    int           getNbr(void);
    std::string   getFirstName(void);
    std::string   getLastName(void);
    std::string   getNickname(void);
    std::string   getNumber(void);
    std::string   getDarkestSecret(void);
    
  private:
    int           _nbr;
    std::string   _firstName;
    std::string   _lastName;
    std::string   _nickname;
    std::string   _number;
    std::string   _darkestSecret;
};

#endif