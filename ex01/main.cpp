/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:25:32 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/22 18:44:03 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nEOF or error detected!" << std::endl;
            return (1);
        }
        if (command == "ADD")
        {
            if (!phonebook.addContact())
                return (1);
        }
        else if (command == "SEARCH")
        {
            if (!phonebook.searchContacts())
                return (1);
        }
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command!" << std::endl;
    }
    return (0);
}
