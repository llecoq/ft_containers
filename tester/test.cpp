/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:15:20 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/22 10:11:32 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	test()
{

			ft_set myset;
			ft_set::iterator itlow,itup;

			// myset.insert(1);
			// myset.insert(2);
			// myset.insert(3);
			// myset.insert(4);
			// myset.insert(5);
			
			ut::fillSet<ft_set>(myset, 10, RANDOMIZED_QUEUE);

			itlow=myset.lower_bound (2);  // itlow points to b
			itup=myset.upper_bound (4);   // itup points to e (not d!)
			std::cout << "up = " <<  *itup << std::endl;
			std::cout << "low = " << *itlow << std::endl;

			myset.erase(itlow,itup);        // erases [itlow,itup)

			// myset.print_tree();
			// // print content:
			// for (ft_set::iterator it=myset.begin(); it!=myset.end(); ++it)
			// std::cout << *it << std::endl;

			
			// itlow = myset.lower_bound(0);
			// std::cout << *itlow << std::endl;
			// itup = myset.upper_bound(13);
			// if (itup == myset.end())
			// 	std::cout << "OK" << std::endl;
			// else
			// 	std::cout << "KO" << std::endl;
			// myset.print_tree();
			std::cout << *myset.upper_bound(5) << std::endl;
			std::cout << *myset.lower_bound(5) << std::endl;
			std::cout << *myset.upper_bound(3) << std::endl;
			std::cout << *myset.lower_bound(3) << std::endl;
			std::cout << *myset.upper_bound(2) << std::endl;
			std::cout << *myset.lower_bound(2) << std::endl;

		// } // INSERT ERASE
		// }
	return 0;
}