#include <cstdlib>
#include <ctime>
#include "PhoneBook.hpp"
#include "phonebook_utils.hpp"

int main() {
	PhoneBook phonebook;

	std::srand(std::time(0));

	while (phonebook.runInterface() != EXIT_STOP);

	return EXIT_SUCCESS;
}
