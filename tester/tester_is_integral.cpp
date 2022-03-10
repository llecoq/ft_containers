/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_is_integral.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:24:15 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/10 13:04:14 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_is_integral(void)
{
	// bool, char, char16_t, char32_t, wchar_t, short, int, long, long long
	
	std::cout << ft::is_integral<bool>::value << std::endl;
	std::cout << ft::is_integral<char>::value << std::endl;
	std::cout << ft::is_integral<const char>::value << std::endl;
	std::cout << ft::is_integral<int>::value << std::endl;
	std::cout << ft::is_integral<unsigned int>::value << std::endl;
	std::cout << ft::is_integral<short>::value << std::endl;
	std::cout << ft::is_integral<long>::value << std::endl;
	std::cout << ft::is_integral<long long>::value << std::endl;
}
