#include "PhoneBook.hpp"
#include "phonebook_utils.hpp"
#include <cstdlib>
#include <iostream>
#include <iomanip>

// Constructors & Destructors
PhoneBook::PhoneBook() : _size(0), _cursor(0) {}
PhoneBook::~PhoneBook() {}

// Methods
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

	for (int i = 0; i < getSize(); i++)
		getContactByIndex(i).writeRow(i);

	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::pushRandomContact() {
	static const std::string firstNames[] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    static const std::string lastNames[] = {"Smith", "Johnson", "Williams", "Brown", "Jones"};
    static const std::string nicknames[] = {"Ace", "Shadow", "Flash", "Tiger", "Wolf"};
    static const std::string secrets[] = {"Loves pizza", "Afraid of heights", "Sleeps late", "Secret gamer", "Can sing"};

	std::string	phone = "";
    for (int i = 0; i < 10; ++i)
        phone += '0' + (std::rand() % 10);

    Contact	c;
    c.setFirstName(firstNames[std::rand() % 5]);
    c.setLastName(lastNames[std::rand() % 5]);
    c.setNickname(nicknames[std::rand() % 5]);
    c.setPhoneNumber(phone);
    c.setDarkestSecret(secrets[std::rand() % 5]);

	addContact(c);
}

void PhoneBook::runInterface() {
	std::string prompt;

	std::cout << BBLUE "[PhoneBook Interface] > " RESET;

	if (!std::getline(std::cin, prompt)) {
		std::cout << BLACK "(Aborting...)" RESET << std::endl;
		exit(EXIT_SUCCESS);
	}

	if (prompt.compare("ADD") == 0)
		return _addContactInterface();
	if (prompt.compare("SEARCH") == 0)
		return _searchContactInterface();
	if (prompt.compare("FILL") == 0) {
		pushRandomContact();
		_searchContactInterface();
		return;
	}
	if (prompt.compare("EXIT") == 0) {
		std::cout << BMAGENTA "Bye bye!" RESET << std::endl;
		exit(EXIT_SUCCESS);
	}

	if (prompt.length())
		errMessage("Hum... `" + prompt + "` is invalid!");
}

void PhoneBook::_askInput(Contact &c, const std::string &prompt, Setter setter, int *status) {
	std::string input;

	std::cout << prompt << std::endl;

	while (true) {
		std::cout << "> ";

		if (!std::getline(std::cin, input)) {
			std::cout << BLACK "(Aborting...)" RESET << std::endl;
			*status = EXIT_FAILURE;
			break ;
		}

		if (input.empty()) {
			errMessage("Field cannot be empty. Enter 'EXIT' to abort.");
			continue;
		}

		if (input.compare("EXIT") == 0) {
			std::cout << BLACK "(Aborting...)" RESET << std::endl;
			*status = EXIT_FAILURE;
			break;
		}

		(c.*setter)(input);
		break;
	}
}

void PhoneBook::_addContactInterface() {
	Contact 	c;
	std::string input;
	int			status = EXIT_SUCCESS;

	std::cout << BGREEN "Okay! Let's add a new user." RESET << std::endl;

	_askInput(c, "Their first name?", &Contact::setFirstName, &status);
	if (status == EXIT_FAILURE)
		return;
	_askInput(c, "Their last name?", &Contact::setLastName, &status);
	if (status == EXIT_FAILURE)
		return;
	_askInput(c, "Their nickname?", &Contact::setNickname, &status);
	if (status == EXIT_FAILURE)
		return;
	_askInput(c, "Their phone number?", &Contact::setPhoneNumber, &status);
	if (status == EXIT_FAILURE)
		return;
	_askInput(c, BMAGENTA "Their darkest secret?" RESET, &Contact::setDarkestSecret, &status);
	if (status == EXIT_FAILURE)
		return;

	std::cout << BGREEN << c.getFirstName() << " has been added!" RESET
		<< std::endl;
	addContact(c);
}

void PhoneBook::_searchContactInterface() {
	displayGrid();

	if (getSize() == 0)
		return ;

	std::string input;
	int 		input_val;

	std::cout << "Contact number > ";
	if (!std::getline(std::cin, input))
		return ;
	input_val = std::atoi(input.c_str());
	if (input_val >= getSize() || input_val < 0)
	{
		std::cout << BYELLOW "Please put an in-range index next time." << std::endl;
		return ;
	}

	std::cout << std::setfill('#') << std::setw(40) << "-" << std::endl;
	getContactByIndex(input_val).writeInformation();
}

// Getters
const Contact &PhoneBook::getContactByIndex(int index) const {
	if (index < 0) {
		warnMessage("Index of contact is out of range.");
		index = 0;
	}
	return _contacts[index % 8];
}

int PhoneBook::getSize() const {
	return _size;
}
