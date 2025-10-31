/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:47:18 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/31 17:01:26 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    currentIndex = 0;
    totalContacts = 0;
}

bool PhoneBook::addContact()
{
    Contact newContact;
    
    if (!newContact.setContact())
        return (false);
    contact[currentIndex] = newContact;
    currentIndex = (currentIndex + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
    return (true);
}

bool PhoneBook::searchContacts() const
{
    int     index;
    std::string input;
    char *end;

    if (!totalContacts)
    {
        std::cout << "No contacts available." << std::endl;
        return (true);
    }
    for (int i = 0; i < totalContacts; i++)
        contact[i].getContactSummary(i + 1);
    std::cout << "Enter Contact Index To View: ";
    if (!std::getline(std::cin, input))
    {
        std::cout << "\nEOF or error detected!" << std::endl;
        return (false);
    }
    index = std::strtol(input.c_str(), &end, 10);
    if (*end == '\0')
    {
        if (index >= 1 && index <= totalContacts)
            contact[index - 1].getContact();
        else
            std::cout << "Contact Not Found!" << std::endl;
    }
    else
        std::cout << "Invalid input!" << std::endl;
    return (true);
}