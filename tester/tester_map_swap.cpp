/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_swap.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:43:17 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/31 13:05:02 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	tester_map_swap_ft()
{
	ft::map<char, TestClass> foo,bar;

	foo['x']=100;
	foo['y']=200;
	
	bar['a']=11;
	bar['b']=22;
	bar['c']=33;
	
	foo.swap(bar);
	
	std::cout << "foo contains:" << std::endl;
	for (ft::map<char, TestClass>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	
	std::cout << "bar contains:" << std::endl;
	for (ft::map<char, TestClass>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	
	std::cout << "swap friend" << std::endl;

	swap(foo, bar);

	std::cout << "foo contains:" << std::endl;
	for (ft::map<char, TestClass>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	
	std::cout << "bar contains:" << std::endl;
	for (ft::map<char, TestClass>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	
	return SUCCES;
}