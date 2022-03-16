/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:21:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 14:01:54 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/tester.hpp"

int	tester(std::string library, std::string container)
{
	// if (container == "pair")
		// return tester_pair();
	if (container == "vector" && library == "ft")
		return tester_vector_ft();
	else if (container == "vector" && library == "std")
		return tester_vector_std();
	// else if (container == "")
	return (ERROR);
}

int	main(int argc, char **argv)
{
	return tester_pair();
	if (argc != 3)
	{
		std::cout << "Usage : [ft/std] <container>" << std::endl;
		return (ERROR);
	}
	if (tester(argv[1], argv[2]) == ERROR)
		std::cout << "Usage : [ft/std] <container>" << std::endl;
	return (EXIT_SUCCESS);
}
