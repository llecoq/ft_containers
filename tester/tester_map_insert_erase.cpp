	
	// ft::map<int, TestClass> map;

	// map.insert(ft::pair<int, TestClass>(1, 1));
	// ft::fillMap<ft::map<int, TestClass>,ft::pair<int, TestClass> > (map, 20, RANDOM);
	// ft_map mymap;
	
	// first insert function version (single parameter):
	// mymap.insert ( ft_pair(6, 100) );
	// mymap.insert ( ft_pair(26, 200) );
	
	// // ft::pair<ft_map::iterator,bool> ret;
	// // ret = mymap.insert ( ft_pair(26, 500) );
	// // if (ret.second==false)
	// // {
	// // 	std::cout << "element 26 already existed";
	// // 	std::cout << " with a value of " << ret.first->second << std::endl;
	// // }
	
	// // // second insert function version (with hint position):
	// ft_map::iterator it = mymap.end();
	// // std::cout << "size = " << mymap.size() << std::endl;
	// mymap.insert (it, ft_pair(3, 300));  // max efficiency inserting
	// // std::cout << "size = " << mymap.size() << std::endl;
	// it = mymap.insert (it, ft_pair(4, 400));
	// std::cout << "it->second 4 = " << it->second << std::endl;
	// it = mymap.insert (mymap.end(), ft_pair(27, 700));
	// std::cout << "it->second 27 = " << it->second << std::endl;
	// it = mymap.insert (mymap.begin(), ft_pair(2, 900));
	// it = mymap.insert (mymap.end(), ft_pair(1, 30));
	// it = mymap.insert (mymap.end(), ft_pair(90, 30));
	// mymap.insert(it, ft_pair(90, 1)); // insert problem
	// std::cout << "it->second 1 = " << it->second << std::endl;
	// std::cout << "find 4 = " << mymap.find(4)->second << std::endl;
	// std::cout << "find 3 = " << mymap.find(3)->second << std::endl;
	// std::cout << "find 2 = " << mymap.find(2)->second << std::endl;
	// std::cout << "find 27 = " << mymap.find(27)->second << std::endl;
	// std::cout << "find 90 = " << mymap.find(90)->second << std::endl;
	// mymap.insert(ft_pair(5, 5));
	// std::cout << "size = " << mymap.size() << std::endl;
	// ft::fillMap<ft_map, ft_pair>(mymap, 20, RANDOMIZED_QUEUE);
	// // ft::fillMap<ft_map, ft_pair>(mymap, 20, RANDOM);
	// it = mymap.find(1);
	// mymap.erase(it);
	// // // it = mymap.find(27);
	// // // mymap.erase(it);
	// // // it = mymap.find(11);
	// // // mymap.erase(it);
	// // // it = mymap.find(6);
	// // // mymap.erase(it);

	// // std::cout << "size = " << mymap.size() << std::endl;
	// // std::cout << "erase" << std::endl;
	// // // mymap.erase(90);
	// mymap.print_tree();
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