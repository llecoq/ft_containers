/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:21:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/15 14:18:34 by llecoq           ###   ########.fr       */
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
		tester_assign();
    {
        // ft::vector<TestClass> myvector(13, 10);
        // // for (size_t i = 500000; i > 0; i--)
        // for (size_t i = 10; i > 0; i--)
		// {
        //     myvector.insert(myvector.begin(), i);
		// 	ft::displayData(myvector);
		// }
        // std::cout << "\033[0;33m\tMy vector: \033[0;37m";
        // for (ft::vector<TestClass>::iterator it = myvector.begin(); it != myvector.end(); it++)
        //     std::cout << *it << ' ';
        // std::cout << "\033[0;33m\tSize: \033[0;37m";
        // std::cout << myvector.size() << ' ';
        // std::cout << "\033[0;33m\tCapacity: \033[0;37m";
        // std::cout << myvector.capacity() << ' ';
        // std::cout << std::endl;
    }
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
