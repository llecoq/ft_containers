/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:21:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/25 12:34:40 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/tester.hpp"



// int	tester(std::string library, std::string container)
// {
// 	if (container == "vector" && library == "ft")
// 		return tester_vector_ft();
// 	else if (container == "vector" && library == "std")
// 		return tester_vector_std();
// 	else if (container == "stack" && library == "std")
// 		return tester_stack_std();
// 	else if (container == "stack" && library == "ft")
// 		return tester_stack_ft();
// 	else if (container == "pair" && library == "std")
// 		return tester_pair_std();
// 	else if (container == "pair" && library == "ft")
// 		return tester_pair_ft();
// 	return (ERROR);
// }

int	main(int argc, char **argv)
{
	return tester_map_ft();
	// return tester_bidirectional_it();

	(void)argv;
	if (argc != 3)
	{
		std::cout << "Usage : [ft/std] <container>" << std::endl;
		return (ERROR);
	}
	// if (tester(argv[1], argv[2]) == ERROR)
	// 	std::cout << "Usage : [ft/std] <container>" << std::endl;
	return (EXIT_SUCCESS);
}

// HEAD is now at 4b8e73d Tree::insert redesigned