/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/06 15:25:29 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	// ft::vector<int>	vec;

	// ut::pushBackVec(vec, 10);

	// ft::vector<int>::iterator			it = vec.begin();
	// ft::vector<int>::const_iterator		constit = it;
	
	// constit++;
	
	// if (it == vec.begin())
	// 	std::cout << "oui" << std::endl;
	ft::map<char,int> foo,bar,zob,bah;
	ut::fillMap<ft::map<char,int>, ft::pair<char, int> >(zob, 10, RANDOMIZED_QUEUE);
	ut::fillMap<ft::map<char,int>, ft::pair<char, int> >(bah, 10, RANDOMIZED_QUEUE);
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal" << std::endl;
	if (foo!=bar) std::cout << "foo and bar are not equal" << std::endl;
	if (foo< bar) std::cout << "foo is less than bar" << std::endl;
	if (foo> bar) std::cout << "foo is greater than bar" << std::endl;
	if (foo<=bar) std::cout << "foo is less than or equal to bar" << std::endl;
	if (foo>=bar) std::cout << "foo is greater than or equal to bar" << std::endl;

	if (foo==zob) std::cout << "foo and zob are equal" << std::endl;
	if (foo!=zob) std::cout << "foo and zob are not equal" << std::endl;
	if (foo< zob) std::cout << "foo is less than zob" << std::endl;
	if (foo> zob) std::cout << "foo is greater than zob" << std::endl;
	if (foo<=zob) std::cout << "foo is less than or equal to zob" << std::endl;
	if (foo>=zob) std::cout << "foo is greater than or equal to zob" << std::endl;

	ft::map<char, int>::iterator	it = bah.begin();
	it->second = 7;
	if (bah==zob) std::cout << "bah and zob are equal" << std::endl;
	if (bah!=zob) std::cout << "bah and zob are not equal" << std::endl;
	if (bah< zob) std::cout << "bah is less than zob" << std::endl;
	if (bah> zob) std::cout << "bah is greater than zob" << std::endl;
	if (bah<=zob) std::cout << "bah is less than or equal to zob" << std::endl;
	if (bah>=zob) std::cout << "bah is greater than or equal to zob" << std::endl;
	// ft::map<char,int> mymap;

	// char	c;
	
	// mymap ['a']=101;
	// mymap ['c']=202;
	// mymap ['f']=303;
	
	// for (c = 'a'; c < 'h'; c++)
	// {
	// 	std::cout << c;
	// 	if (mymap.count(c) > 0)
	// 		std::cout << " is an element of mymap." << std::endl;
	// 	else 
	// 		std::cout << " is not an element of mymap." << std::endl;
	// }

	
	return (SUCCESS);
}