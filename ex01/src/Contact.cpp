/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 11:08:01 by ehosta            #+#    #+#             */
/*   Updated: 2025/05/21 16:51:51 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setFirstName(const std::string& firstName) {
	_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
	_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
	return _firstName;
}

std::string Contact::getLastName() {
	return _lastName;
}

std::string Contact::getNickname() {
	return _nickname;
}

std::string Contact::getPhoneNumber() {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return _darkestSecret;
}
