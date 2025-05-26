#include "Contact.hpp"
#include "phonebook_utils.hpp"
#include <iomanip>
#include <iostream>

// Constructors & Destructors
Contact::Contact() {}

Contact::~Contact() {}

// Methods
void Contact::writeRow(int index) const {
	std::cout << "|"  << std::setw(ROW_WIDTH) << index
		<< "|"  << std::setw(ROW_WIDTH) << truncateColumn(getFirstName())
		<< "|"  << std::setw(ROW_WIDTH) << truncateColumn(getLastName())
		<< "|"  << std::setw(ROW_WIDTH) << truncateColumn(getNickname())
		<< "|" << std::endl;
}

void Contact::writeInformation() const {
	std::cout << "First name: " BBLUE << getFirstName() << RESET << std::endl
		<< "Last name: " BBLUE << getLastName() << RESET << std::endl
		<< "Nickname: " BBLUE << getNickname() << RESET << std::endl
		<< "Phone number: " BBLUE << getPhoneNumber() << RESET << std::endl
		<< "Darkest secret: " BBLUE << getDarkestSecret() << RESET << std::endl;
}

// Getters
const std::string &Contact::getFirstName() const {
	return _firstName;
}

const std::string &Contact::getLastName() const {
	return _lastName;
}

const std::string &Contact::getNickname() const {
	return _nickname;
}

const std::string &Contact::getPhoneNumber() const {
	return _phoneNumber;
}

const std::string &Contact::getDarkestSecret() const {
	return _darkestSecret;
}

// Setters
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