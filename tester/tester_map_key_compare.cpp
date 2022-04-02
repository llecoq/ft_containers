	ft::map<char,int> mymap;
	
	ft::map<char,int>::key_compare mycomp = mymap.key_comp();
	
	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	
	std::cout << "mymap contains:\n";
	
	char highest = mymap.rbegin()->first;     // key value of last element
	
	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while ( mycomp((*it++).first, highest) );

	// value_comp()

		ft::map<char,int> mymap;
	
	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;
	
	std::cout << "mymap contains:\n";
	
	ft::pair<char,int> highest = *mymap.rbegin();          // last element
	
	ft::map<char,int>::iterator it = mymap.begin();
	do {
	std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	