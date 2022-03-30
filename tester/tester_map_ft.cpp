/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_map_ft.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:42:25 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/30 15:18:06 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_map_ft()
{
	// ft::vector<TestClass>       vec_for_stack(4, TestClass(12));
    // ft::vector<TestClass>   empty_vec;
    // ft::stack<TestClass, ft::vector<TestClass> >   empty_stack(empty_vec);
    // ft::stack<TestClass, ft::vector<TestClass> >   stack_from_vec(vec_for_stack);
    // std::cout << std::boolalpha;
    // std::cout << "empty stack is empty = " << empty_stack.empty() << std::endl;
    // std::cout << "stack_from_vec stack is empty " << stack_from_vec.empty() << std::endl;
    // std::cout << std::endl;
    // std::cout << "empty stack size = " << empty_stack.size() << std::endl;
    // std::cout << "stack_from_vec stack size " << stack_from_vec.size() << std::endl;
    // std::cout << std::endl;
    // std::cout << "Testing stack top" << std::endl;
    // std::cout << "empty stack top = " << empty_stack.top() << std::endl;
    // std::cout << "empty_vec back = " << empty_vec.back() << std::endl;
    // std::cout << std::endl;
    // std::cout << "stack_from_vec stack top " << stack_from_vec.top() << std::endl;
    // std::cout << "vec_for_stack stack back " << vec_for_stack.back() << std::endl;
    // std::cout << std::endl;
    // return 0;
	
	ft_map mymap;
	
	// first insert function version (single parameter):
	mymap.insert ( ft_pair(6, 100) );
	mymap.insert ( ft_pair(26, 200) );
	
	// ft::pair<ft_map::iterator,bool> ret;
	// ret = mymap.insert ( ft_pair(26, 500) );
	// if (ret.second==false)
	// {
	// 	std::cout << "element 26 already existed";
	// 	std::cout << " with a value of " << ret.first->second << std::endl;
	// }
	
	// // second insert function version (with hint position):
	ft_map::iterator it = mymap.end();
	// std::cout << "size = " << mymap.size() << std::endl;
	mymap.insert (it, ft_pair(3, 300));  // max efficiency inserting
	// std::cout << "size = " << mymap.size() << std::endl;
	it = mymap.insert (it, ft_pair(4, 400));
	std::cout << "it->second 4 = " << it->second << std::endl;
	it = mymap.insert (mymap.end(), ft_pair(27, 700));
	std::cout << "it->second 27 = " << it->second << std::endl;
	it = mymap.insert (mymap.begin(), ft_pair(2, 900));
	it = mymap.insert (mymap.end(), ft_pair(1, 30));
	it = mymap.insert (mymap.end(), ft_pair(90, 30));
	mymap.insert(it, ft_pair(90, 1)); // insert problem
	std::cout << "it->second 1 = " << it->second << std::endl;
	std::cout << "find 4 = " << mymap.find(4)->second << std::endl;
	std::cout << "find 3 = " << mymap.find(3)->second << std::endl;
	std::cout << "find 2 = " << mymap.find(2)->second << std::endl;
	std::cout << "find 27 = " << mymap.find(27)->second << std::endl;
	std::cout << "find 90 = " << mymap.find(90)->second << std::endl;
	mymap.insert(ft_pair(5, 5));
	// std::cout << "size = " << mymap.size() << std::endl;
	ft::fillMap<ft_map, ft_pair>(mymap, 20, RANDOMIZED_QUEUE);
	// ft::fillMap<ft_map, ft_pair>(mymap, 20, RANDOM);
	// // it = mymap.find(1);
	// // mymap.erase(it);
	// // it = mymap.find(27);
	// // mymap.erase(it);
	// // it = mymap.find(11);
	// // mymap.erase(it);
	// // it = mymap.find(6);
	// // mymap.erase(it);

	// std::cout << "size = " << mymap.size() << std::endl;
	// std::cout << "erase" << std::endl;
	// // mymap.erase(90);
	mymap.print_tree();
	// it = mymap.find(90);
	// std::cout << "erase" << std::endl;
	// mymap.erase(mymap.begin(), mymap.end());
	// mymap.print_tree();
	// // while (it != mymap.end())
	// // {
	// // 	std::cout << it->first << std::endl;
	// // 	it++;
	// // }
	// std::cout << "size = " << mymap.size() << std::endl;
	// std::cout << "erase" << std::endl;
	// // ietartor a tester apres full erase
	// mymap.erase(mymap.begin(), mymap.end());
	
	// std::cout << "size = " << mymap.size() << std::endl;
	// std_map	map;


	// map.insert

	return (SUCCESS);
}