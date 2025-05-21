/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:54:30 by ehosta            #+#    #+#             */
/*   Updated: 2025/05/21 10:59:35 by ehosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static std::string _capitalize(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (isalpha(str[i]))
			str[i] = toupper(str[i]);
	}
	return str;
}

int main(int argc, char *argv[]) {
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	int i = 0;
	while (++i < argc)
		std::cout << _capitalize(argv[i]);;
	std::cout << std::endl;
	return (1);
}
