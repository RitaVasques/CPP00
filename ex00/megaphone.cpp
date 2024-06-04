/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ritavasques <ritavasques@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:55:29 by ritavasques       #+#    #+#             */
/*   Updated: 2024/06/04 18:42:09 by ritavasques      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string capitalize(char *str)
{
    std::string message;
    
    for (int i = 0; str[i]; i++)
        message += toupper(str[i]);
    return (message);
}

int main(int argc, char **argv)
{
    std::string no_arg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    
    if (argc == 1)
    {
        std::cout << no_arg;
        return (0);
    }
    for (int i = 1; i < argc; i++)
        std::cout << capitalize(argv[i]);
    std::cout << std::endl;
    return (0);
}
