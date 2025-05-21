/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:41:43 by ehosta            #+#    #+#             */
/*   Updated: 2025/05/21 17:08:09 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "PhoneBook.hpp"
#include "types.hpp"

static void _ask_input(Contact &c, const std::string &prompt, Setter setter, int *status) {
	std::string input;

	std::cout << prompt << std::endl;
	while (true) {
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.length() == 0) {
			std::cout <<
				RED "Field cannot be empty. Enter 'EXIT' to abort." RESET <<
				std::endl;
			continue;
		} if (input.compare("EXIT") == 0) {
			std::cout << BLACK "(Aborting...)" RESET << std::endl;
			*status = EXIT_FAILURE;
			break;
		}
		(c.*setter)(input);
		break;
	}
}

static void _add_prompt(PhoneBook &phonebook) {
	Contact c;
	std::string input;
	int status = EXIT_SUCCESS;

	std::cout << BGREEN "Okay! Let's add a new user." RESET << std::endl;

	_ask_input(c, "Their first name?", &Contact::setFirstName, &status);
	if (status == EXIT_FAILURE)
		return;
	_ask_input(c, "Their last name?", &Contact::setLastName, &status);
	if (status == EXIT_FAILURE)
		return;
	_ask_input(c, "Their nickname?", &Contact::setNickname, &status);
	if (status == EXIT_FAILURE)
		return;
	_ask_input(c, "Their phone number?", &Contact::setPhoneNumber, &status);
	if (status == EXIT_FAILURE)
		return;
	_ask_input(c, BMAGENTA "Their darkest secret?" RESET, &Contact::setDarkestSecret, &status);
	if (status == EXIT_FAILURE)
		return;

	std::cout << BGREEN << c.getFirstName() << " has been added!" RESET
		<< std::endl;
	phonebook.addContact(c);
}

static void _search_prompt(PhoneBook &phonebook) {
	phonebook.displayGrid();
	
	if (phonebook.getSize() == 0)
		return ;

	std::string input;
	int input_val;
	Contact c;
	
	std::cout << "Contact number > ";
	std::getline(std::cin, input);

	std::cout << "Contact:" << std::endl;
	input_val = std::atoi(input.c_str()) % phonebook.getSize();
	c = phonebook.getContacts()[input_val];
	std::cout << "First name: " << c.getFirstName() << std::endl
		<< "Last name: " << c.getLastName() << std::endl
		<< "Nickname: " << c.getNickname() << std::endl
		<< "Phone number: " << c.getPhoneNumber() << std::endl
		<< "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

int main() {
	std::srand(std::time(0));

	PhoneBook phonebook;
	std::string prompt;

	while (true) {
		std::cout << BBLUE "[PhoneBook Interface] > " RESET;
		std::getline(std::cin, prompt);

		if (prompt.compare("ADD") == 0)
			_add_prompt(phonebook);
		else if (prompt.compare("SEARCH") == 0)
			_search_prompt(phonebook);
		else if (prompt.compare("EXIT") == 0) {
			std::cout << BMAGENTA "Bye bye!" RESET << std::endl;
			exit(0);
		}
		else if (prompt.compare("FILL") == 0) {
			phonebook.pushRandomContact();
			_search_prompt(phonebook);
		}
		else if (prompt.length()) {
			std::cout << BRED "Hum... `"
				<< prompt << "` is invalid!" RESET << std::endl;
		}
	}
	return (0);
}
