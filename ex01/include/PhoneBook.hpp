#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
	public:
	// Constructors & Destructors
	PhoneBook();
	~PhoneBook();

	// Methods
	void addContact(const Contact &contact);
	void displayGrid();
	void pushRandomContact();
	void runInterface();

	// Getters
	const Contact &getContactByIndex(int index) const;
	int getSize() const;

	private:
	// Attributes
	Contact	_contacts[8];
	int		_size;
	int		_cursor;

	void _addContactInterface();
	void _searchContactInterface();
	void _askInput(Contact &c, const std::string &prompt, Setter setter, int *status);
};

#endif