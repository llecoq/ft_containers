/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_pair.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:59:45 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 14:47:25 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_pair(void)
{
	ft::pair <std::string,double> product1;                     // default constructor
	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
	ft::pair <std::string,double> product3 (product2);          // copy constructor
	ft::pair <std::string,double> product3_copy;

	product3_copy = product3;
	product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	(void)product1;
	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	std::cout << "The price of " << product3_copy.first << " is $" << product3_copy.second << '\n';


	ft::pair<int,char> foo (10,'z');
	ft::pair<int,char> bar (90,'a');
	
	if (foo==bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo!=bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo< bar) std::cout << "foo is less than bar" << std::endl;
	if (foo> bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo<=bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo>=bar) std::cout << "foo is greater than or equal to bar" << std::endl;

	ft::pair <TestClass,int> foooo;
	ft::pair <TestClass,int> baaar;
	
	foooo = ft::make_pair (10,20);
	baaar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
	
	std::cout << "foooo: " << foooo.first << ", " << foooo.second << '\n';
	std::cout << "baaar: " << baaar.first << ", " << baaar.second << '\n';

	return (0);
}