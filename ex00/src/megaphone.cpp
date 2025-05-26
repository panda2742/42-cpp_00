#include <iostream>
#include <cstdlib>

static std::string _capitalize(const std::string &str);

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return EXIT_SUCCESS;
	}

	for (int i = 1; i < argc; i++)
		std::cout << _capitalize(argv[i]);

	std::cout << std::endl;
	return EXIT_SUCCESS;
}

static std::string _capitalize(const std::string &str) {
	std::string	copy;
	std::size_t	len = str.length();

	for (size_t i = 0; i < len; i++)
		copy.push_back(toupper(str.operator[](i)));

	return copy;
}
