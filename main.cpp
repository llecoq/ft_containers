/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:21:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/05/02 18:52:13 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	tester(std::string container)
{
	if (container == "vector")
		return tester_vector();
	else if (container == "stack")
		return tester_stack();
	else if (container == "pair")
		return tester_pair();
	else if (container == "map")
		return tester_map();
	else if (container == "set")
		return tester_set();
	return (ERROR);
}

int	main(int argc, char **argv)			
{
	ft_map	map;

	ft::map<char, TestClass>	oh;

	std::cout << "max size = " << map.max_size() << std::endl;
	std::cout << "max size = " << oh.max_size() << std::endl;

	return 1;
	if (argc != 2)
	{
		std::cout << "Usage : ./ft_containers <container_type>" << std::endl;
		return (ERROR);
	}
	if (tester(argv[1]) == ERROR)
		std::cout << "Usage : ./ft_containers <container_type>" << std::endl;
	return (SUCCESS);
}
