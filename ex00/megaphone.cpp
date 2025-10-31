/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:51:43 by dikhalil          #+#    #+#             */
/*   Updated: 2025/10/31 16:51:45 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>


int main(int argc, char **argv)
{
    std::string word;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            word = argv[i];
            for (size_t j = 0; j < word.length(); j++)
            {
                word[j] = std::toupper(word[j]);
            }
            if (i < argc - 1)
                std::cout << word << " ";
            else
                std::cout << word << std::endl;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}