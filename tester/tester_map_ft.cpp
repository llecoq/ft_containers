/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/08 15:27:48 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	tester_map_ft()
{
	// empty constructor
	ft_map	empty;

	std::cout << "empty size = " << empty.size() << std::endl;

	// range constructor
    ft::vector< ft::pair <int,int> > vect;

    int arr[] = {10, 20, 5, 40 };
    int arr1[] = {30, 60, 20, 50};
    int n = sizeof(arr)/sizeof(arr[0]);
  
    for (int i=0; i<n; i++)
        vect.push_back( ft::make_pair(arr[i],arr1[i]) );
  	
	ft_map	map(vect.begin(), vect.end());
	ft_map	map2(map.begin(), map.end());

	std::cout << "map begin = " << map.begin()->first << std::endl;
	std::cout << "map2 begin = " << map2.begin()->first << std::endl;
	std::cout << "map size = " << map.size() << std::endl;
	std::cout << "map2 size = " << map2.size() << std::endl;
	std::cout << "vect size = " << vect.size() << std::endl;

	// copy constructor
	ft_map	copy(map);
	std::cout << "copy begin = " << copy.begin()->first << std::endl;
	std::cout << "copy size = " << copy.size() << std::endl;

	return (SUCCESS);
}

