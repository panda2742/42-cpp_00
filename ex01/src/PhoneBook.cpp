/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:01:57 by ehosta            #+#    #+#             */
/*   Updated: 2025/05/21 17:05:19 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _size(0), _cursor(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_truncateColumn(const std::string &str) {
	if (str.length() > 10) {
		std::string truncated = str.substr(0, 10);
		truncated[9] = '.';
		return truncated;
	}
	return str;
}

void PhoneBook::addContact(const Contact &contact) {
	_contacts[_cursor] = contact;
	if (_size < 8)
		_size++;
	_cursor = (_cursor + 1) % 8;
}

void PhoneBook::displayGrid() {
	std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
	if (_size == 0)
		return;

	std::cout << "|----------|----------|----------|----------|" << std::endl;

	Contact c;
	int i = 0;
	while (i < _size)
	{
		c = _contacts[i];
		std::cout << "|"  << std::setw(10) << i
			<< "|"  << std::setw(10) << _truncateColumn(c.getFirstName())
			<< "|"  << std::setw(10) << _truncateColumn(c.getLastName())
			<< "|"  << std::setw(10) << _truncateColumn(c.getNickname())
			<< "|" << std::endl;
		i++;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::pushRandomContact() {
	static const std::string firstNames[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    static const std::string lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones"};
    static const std::string nicknames[] = {"Ace", "Shadow", "Flash", "Tiger", "Wolf"};
    static const std::string secrets[] = {"Loves pizza", "Afraid of heights", "Sleeps late", "Secret gamer", "Can sing"};

	std::string phone = "";
    for (int i = 0; i < 10; ++i) {
        phone += '0' + (std::rand() % 10);
	}

    Contact c;
    c.setFirstName(firstNames[std::rand() % 5]);
    c.setLastName(lastNames[std::rand() % 5]);
    c.setNickname(nicknames[std::rand() % 5]);
    c.setPhoneNumber(phone);
    c.setDarkestSecret(secrets[std::rand() % 5]);

	addContact(c);
}

int PhoneBook::getSize() {
	return _size;
}

Contact *PhoneBook::getContacts() {
	return (_contacts);
}