/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:47:35 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/22 18:49:47 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <cstdlib>

class PhoneBook
{
    private:
        Contact contact[8];
        int currentIndex;
        int totalContacts;
    public:
        PhoneBook();
        bool addContact();
        bool searchContacts() const;
};

#endif
