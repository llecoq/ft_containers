/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:21:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/01 18:12:41 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.hpp"
#include "utils/tester.hpp"

int TestClass::objectCount = 0;

std::ostream	&operator<<(std::ostream &output, TestClass &rhs)
{
	output << rhs.getName() << std::endl;
	return output;
};

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
		tester_push_back();
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


	// std::vector<float>		vec(5);
	// // ft::vector<float>		vec(5, 10);
	// // std::vector<Ah>		vec(5);
	// // std::cout << vec[2] << std::endl;
	// // ft::vector<int>	v(5);
	
	// std::cout << vec.max_size() << std::endl;
	// // std::cout << vec[0] << std::endl;

//   // constructors used in the same order as described above:
//   std::vector<int> first;                                // empty vector of ints
//   std::vector<int> second (4,100);                       // four ints with value 100
//   std::vector<int> third (second.begin(),second.end());  // iterating through second
//   std::vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';