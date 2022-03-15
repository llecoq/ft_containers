/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_is_integral.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:24:15 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 16:41:55 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

void	tester_is_integral(void)
{
	// bool, char, char16_t, char32_t, wchar_t, short, int, long, long long

	//	bool
	std::cout << "bool :" << std::endl;
	std::cout << ft::is_integral<bool>::value << std::endl;
	std::cout << ft::is_integral<volatile bool>::value << std::endl;
	std::cout << ft::is_integral<const bool>::value << std::endl;
	//	char
	std::cout << "char :" << std::endl;
	std::cout << ft::is_integral<char>::value << std::endl;
	std::cout << ft::is_integral<const char>::value << std::endl;
	std::cout << ft::is_integral<volatile char>::value << std::endl;
	std::cout << ft::is_integral<unsigned char>::value << std::endl;
	std::cout << ft::is_integral<const unsigned char>::value << std::endl;
	std::cout << ft::is_integral<volatile unsigned char>::value << std::endl;
	//	char16_t
	std::cout << "char16_t :" << std::endl;
	std::cout << ft::is_integral<char16_t>::value << std::endl;
	std::cout << ft::is_integral<const char16_t>::value << std::endl;
	std::cout << ft::is_integral<volatile char16_t>::value << std::endl;
	//	char32_t
	std::cout << "char32_t :" << std::endl;
	std::cout << ft::is_integral<char32_t>::value << std::endl;
	std::cout << ft::is_integral<const char32_t>::value << std::endl;
	std::cout << ft::is_integral<volatile char32_t>::value << std::endl;
	//	wchar_t
	std::cout << "wchar_t :" << std::endl;
	std::cout << ft::is_integral<wchar_t>::value << std::endl;
	std::cout << ft::is_integral<const wchar_t>::value << std::endl;
	std::cout << ft::is_integral<volatile wchar_t>::value << std::endl;
	//	short
	std::cout << "short :" << std::endl;
	std::cout << ft::is_integral<short>::value << std::endl;
	std::cout << ft::is_integral<const short>::value << std::endl;
	std::cout << ft::is_integral<volatile short>::value << std::endl;
	std::cout << ft::is_integral<unsigned short>::value << std::endl;
	std::cout << ft::is_integral<const unsigned short>::value << std::endl;
	std::cout << ft::is_integral<volatile unsigned short>::value << std::endl;
	//	int
	std::cout << "int :" << std::endl;
	std::cout << ft::is_integral<int>::value << std::endl;
	std::cout << ft::is_integral<const int>::value << std::endl;
	std::cout << ft::is_integral<volatile int>::value << std::endl;
	std::cout << ft::is_integral<unsigned int>::value << std::endl;
	std::cout << ft::is_integral<const unsigned int>::value << std::endl;
	std::cout << ft::is_integral<volatile unsigned int>::value << std::endl;
	//	long
	std::cout << "long :" << std::endl;
	std::cout << ft::is_integral<long>::value << std::endl;
	std::cout << ft::is_integral<const long>::value << std::endl;
	std::cout << ft::is_integral<volatile long>::value << std::endl;
	std::cout << ft::is_integral<unsigned long>::value << std::endl;
	std::cout << ft::is_integral<const unsigned long>::value << std::endl;
	std::cout << ft::is_integral<volatile unsigned long>::value << std::endl;
	//	long long
	std::cout << "long long :" << std::endl;
	std::cout << ft::is_integral<long long>::value << std::endl;
	std::cout << ft::is_integral<const long long>::value << std::endl;
	std::cout << ft::is_integral<volatile long long>::value << std::endl;
	std::cout << ft::is_integral<unsigned long long>::value << std::endl;
	std::cout << ft::is_integral<const unsigned long long>::value << std::endl;
	std::cout << ft::is_integral<volatile unsigned long long>::value << std::endl;

	// float / double (...)
	std::cout << "float / double (...) :" << std::endl;
	std::cout << ft::is_integral<float>::value << std::endl;
	std::cout << ft::is_integral<double>::value << std::endl;
	std::cout << ft::is_integral<const double>::value << std::endl;
	std::cout << ft::is_integral<char *>::value << std::endl;
	std::cout << ft::is_integral<TestClass>::value << std::endl;
	std::cout << ft::is_integral<int *>::value << std::endl;
}
