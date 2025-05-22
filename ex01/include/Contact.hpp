#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	public:
	// Constructors & Destructors
	Contact();
	~Contact();

	// Methods
	void writeRow(int index) const;
	void writeInformation() const;

	// Getters
	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	const std::string &getPhoneNumber() const;
	const std::string &getDarkestSecret() const;

	// Setters
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);

	private:
	// Attributes
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;
};

typedef void (Contact::*Setter)(const std::string &);

#endif