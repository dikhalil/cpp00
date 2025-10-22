/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:08:22 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/22 18:44:29 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static int getInput(const std::string &prompt, std::string &field)
{
    while (field.empty())
    {
        std::cout << prompt;
        if (!std::getline(std::cin, field))
        {
            std::cout << "\nEOF or error detected!" << std::endl;
            return (0);
        }
    }
    return (1);
}

bool Contact::setContact()
{
    if (!getInput("First Name: ", firstName))
        return (false);
    if (!getInput("Last Name: ", lastName))
        return (false);
    if (!getInput("Nick Name: ", nickName))
        return (false);
    if (!getInput("Phone Number: ", phoneNumber))
        return (false);
    if (!getInput("Darkest Secret: ", darkestSecret))
        return (false);
    return (true);
}

void Contact::getContact() const
{
    std::cout << "First Name: " << firstName;
    std::cout << "\nLast Name: " << lastName;
    std::cout << "\nNick Name: " << nickName;
    std::cout << "\nPhone Number: " << phoneNumber;
    std::cout << "\nDarkest Secret: " << darkestSecret << std::endl;
}

static std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
} 

void Contact::getContactSummary(int index) const
{
    std::cout << std::setw(10) << index << "|";
    std::cout << std::setw(10) << formatField(firstName) << "|";
    std::cout << std::setw(10) << formatField(lastName) << "|";
    std::cout << std::setw(10) << formatField(nickName) << std::endl;
}
