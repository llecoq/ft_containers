/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:21:24 by llecoq            #+#    #+#             */
/*   Updated: 2022/02/27 14:19:43 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/vector.hpp"
#include <vector>
#include "Ah.hpp"

int	main()
{
	std::vector<float>		vec(5);
	// ft::vector<float>		vec(5, 10);
	// std::vector<Ah>		vec(5);
	// std::cout << vec[2] << std::endl;
	// ft::vector<int>	v(5);
	
	std::cout << vec.max_size() << std::endl;
	// std::cout << vec[0] << std::endl;
	return (0);
}

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