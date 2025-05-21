/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:04:50 by ehosta            #+#    #+#             */
/*   Updated: 2025/05/21 17:05:01 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <inttypes.h>
#include <types.hpp>
#include "Contact.hpp"

class PhoneBook {
	private:
	Contact _contacts[8];
	int _size;
	int _cursor;

	std::string _truncateColumn(const std::string &str);

	public:
	PhoneBook();
	~PhoneBook();

	void addContact(const Contact &contact);
	void displayGrid();
	void pushRandomContact();

	Contact *getContacts();
	int getSize();
};

#endif