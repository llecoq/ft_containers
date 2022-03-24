/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/24 14:36:11 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	ft_map mymap;
	
	// first insert function version (single parameter):
	mymap.insert ( ft_pair(1, 100) );
	mymap.insert ( ft_pair(26, 200) );
	
	ft::pair<ft_map::iterator,bool> ret;
	ret = mymap.insert ( ft_pair(26, 500) );
	if (ret.second==false)
	{
		std::cout << "element 26 already existed";
		std::cout << " with a value of " << ret.first->second << std::endl;
	}
	
	// second insert function version (with hint position):
	ft_map::iterator it = mymap.end();
	mymap.insert (it, ft_pair(2, 300));  // max efficiency inserting
	mymap.insert (it, ft_pair(3, 400));
	std::cout << mymap.size() << std::endl;
	// std::cout << mymap.find(3)->second << std::endl;

	return (SUCCESS);
}