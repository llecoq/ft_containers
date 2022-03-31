/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/31 12:42:49 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	ft::map<char, TestClass> foo,bar;

	foo['x']=100;
	foo['y']=200;
	
	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	
	foo.swap(bar);
	
	std::cout << "foo contains:" << std::endl;
	for (std::map<char, TestClass>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	
	std::cout << "bar contains:" << std::endl;
	for (std::map<char, TestClass>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	
	return (SUCCESS);
}