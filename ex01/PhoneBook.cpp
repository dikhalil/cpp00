/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:47:18 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/22 18:51:52 by dikhalil         ###   ########.fr       */
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
static int isNumber(const std::string &s)
{
    size_t i;

    i = 0;
    if (s.empty())
        return (0);
    while (std::isspace(s[i]))
        i++;
    if (s.length() == i)
            return (0);
    if (s[i] == '-' || s[i] == '+')
    {
        i++;
        if (s.length() == i)
            return (0);
    }
    for (size_t j = i; j < s.length(); j++)
    {
        if (!std::isdigit(s[j]))
            return (0);
    }
    return (1);
}

bool PhoneBook::searchContacts() const
{
    int     index;
    std::string input;

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
    if (isNumber(input))
    {
        index = atoi(input.c_str());
        if (index >= 1 && index <= totalContacts)
            contact[index - 1].getContact();
        else
            std::cout << "Contact Not Found!" << std::endl;
    }
    else
        std::cout << "Invalid input!" << std::endl;
    return (true);
}