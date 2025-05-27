#include "phonebook_utils.hpp"
#include <iostream>

std::string truncateColumn(const std::string &str) {
	if (str.length() > 10) {
		std::string truncated = str.substr(0, 10);
		truncated[9] = '.';
		return truncated;
	}
	return str;
}

void warnMessage(const std::string &str) {
	std::cout << BYELLOW "PhoneBook warning: " << str << RESET << std::endl;
}

void errMessage(const std::string &str) {
	std::cout << BRED "PhoneBook error: " << str << RESET << std::endl;
}
