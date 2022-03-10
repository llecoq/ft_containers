/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:21:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/10 17:13:06 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/tester.hpp"

int	tester(std::string library, std::string container)
{
	if (container == "vector")
		return tester_vector(library);
	// else if (container == "")
	return (ERROR);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		tester_copy_assignment();
		return (0);
	}
	if (argc != 3)
	{
		std::cout << "Usage : [ft/std] <container>" << std::endl;
		return (ERROR);
	}
	if (tester(argv[1], argv[2]) == ERROR)
		std::cout << "Usage : [ft/std] <container>" << std::endl;
	return (EXIT_SUCCESS);
}
