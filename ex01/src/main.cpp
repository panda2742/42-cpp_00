#include <cstdlib>
#include <ctime>
#include "PhoneBook.hpp"
#include "phonebook_utils.hpp"

int main() {
	PhoneBook phonebook;

	std::srand(std::time(0));
	while (true)
		phonebook.runInterface();

	return EXIT_SUCCESS;
}
