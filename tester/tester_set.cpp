/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_set.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:22:18 by llecoq            #+#    #+#             */
/*   Updated: 2022/04/21 20:17:33 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int	tester_set_ft()
{
	/*------------------------------ CONSTRUCTOR ----------------------------*/
	{	
		std::cout << "-------------- CONSTRUCTOR ---------------" << std::endl;

		ft_set first;                           // empty set of ints

		int myints[]= {10,20,30,40,50};
		ft_set second (myints,myints+5);        // range

		ft_set third (second);                  // a copy of second

		ft_set fourth (second.begin(), second.end());  // iterator ctor.

	}

	// /*------------------------------ COPY ASSIGNMENT ----------------------------*/
	{
		std::cout << "-------------- COPY ASSIGNMENT ---------------" << std::endl;
		int myints[]={ 12,82,37,64,15 };
		ft_set first (myints,myints+5);   // set with 5 ints
		ft_set second;                    // empty set
		
		second = first;                          // now second contains the 5 ints
		first = ft_set();                 // and first is empty
		
		std::cout << "Size of first: " << int (first.size()) << std::endl;
		std::cout << "Size of second: " << int (second.size()) << std::endl;
	}

	/*------------------------------ ITERATORS ----------------------------*/
	{
		std::cout << "-------------- ITERATORS ---------------" << std::endl;
		{
		int myints[] = {75,23,65,42,13};
		ft_set myset (myints,myints+5);
		
		std::cout << "myset contains:";
		for (ft_set::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
		std::cout << std::endl;
		}
		{
		int myints[] = {21,64,17,78,49};
		ft_set myset (myints,myints+5);

		ft_set::reverse_iterator rit;

		std::cout << "myset contains:";
		for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
		std::cout << ' ' << *rit;
		std::cout << std::endl;
		}
	}

	/*------------------------------ CAPACITY ----------------------------*/
	{
		std::cout << "-------------- CAPACITY ---------------" << std::endl;
		ft_set myset;

		myset.insert(20);
		myset.insert(30);
		myset.insert(10);

		std::cout << "myset contains:";
		while (!myset.empty())
		{
		std::cout << ' ' << *myset.begin();
		myset.erase(myset.begin());
		}
		std::cout << std::endl;
	}
	{
		std::cout << "-------------- SIZE ---------------" << std::endl;
		ft_set myints;
		std::cout << "0. size: " << myints.size() << std::endl;

		for (int i=0; i<10; ++i) myints.insert(i);
		std::cout << "1. size: " << myints.size() << std::endl;

		myints.insert (100);
		std::cout << "2. size: " << myints.size() << std::endl;

		myints.erase(5);
		std::cout << "3. size: " << myints.size() << std::endl;
	}
	{
		std::cout << "-------------- MAX SIZE ---------------" << std::endl;
		int i;
		ft_set myset;

		if (myset.max_size()>1000)
		{
			for (i=0; i<1000; i++) myset.insert(i);
			std::cout << "The set contains 1000 elements." << std::endl;
		}
		else std::cout << "The set could not hold 1000 elements." << std::endl;
	}

	/*------------------------------ MODIFIERS ----------------------------*/
	{
		std::cout << "-------------- MODIFIERS ---------------" << std::endl;
	
		//-------------------------- INSERT / ERASE
		{
			{
				std::cout << "-------------- INSERT / ERASE -------------" << std::endl;
				ft_set 							myset;
				ft_set::iterator 				it;
				ft::pair<ft_set::iterator,bool> ret;
	
				// set some initial values:
				for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50
	
				ret = myset.insert(20);               // no new element inserted
	
				if (ret.second==false) it=ret.first;  // "it" now points to element 20
	
				std::cout << "*it = " << *it << std::endl;
				myset.insert (it,25);                 // max efficiency inserting
				myset.insert (it,24);                 // max efficiency inserting
				myset.insert (it,26);                 // no max efficiency inserting
	
				int myints[]= {5,10,15};              // 10 already in set, not inserted
				myset.insert (myints,myints+3);
	
				std::cout << "myset contains:";
				for (it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
				std::cout << std::endl;
			}
			{
				ft_set myset;
				ft_set::iterator it;

				// insert some values:
				for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

				it = myset.begin();
				++it;                                         // "it" points now to 20

				myset.erase (it);

				myset.erase (40);

				it = myset.find (60);
				myset.erase (it, myset.end());

				std::cout << "myset contains:";
				for (it=myset.begin(); it!=myset.end(); ++it)
				std::cout << ' ' << *it;
				std::cout << std::endl;
			}
		} // INSERT ERASE
	}
		//-------------------------- CLEAR
		{
			std::cout << "-------------- CLEAR -------------" << std::endl;
			ft_set	set;

			set.clear();
			ut::fillSet<ft_set>(set, 20, RANDOMIZED_QUEUE);
			ut::displayDataSet<ft_set>(set);
			set.clear();
			ut::displayDataSet<ft_set>(set);
			std::cout << std::endl;
		} // CLEAR

		//-------------------------- SWAP
		{
			std::cout << "-------------- SWAP -------------" << std::endl;
			ft_set foo,bar;

			ut::fillSet<ft_set>(foo, 10, QUEUE);
			ut::fillSet<ft_set>(bar, 5, RANDOMIZED_QUEUE);
			
			foo.swap(bar);
			
			std::cout << "foo contains:" << std::endl;
			for (ft_set::iterator it = foo.begin(); it != foo.end(); ++it)
				std::cout << *it << std::endl;
			
			std::cout << "bar contains:" << std::endl;
			for (ft_set::iterator it = bar.begin(); it != bar.end(); ++it)
				std::cout << *it << std::endl;
			
			std::cout << "swap friend" << std::endl;

			swap(foo, bar);

			std::cout << "foo contains:" << std::endl;
			for (ft_set::iterator it = foo.begin(); it != foo.end(); ++it)
				std::cout << *it << std::endl;
			
			std::cout << "bar contains:" << std::endl;
			for (ft_set::iterator it = bar.begin(); it != bar.end(); ++it)
			std::cout << *it << std::endl;
		} // SWAP
	// }

	/*------------------------------ OBSERVERS ----------------------------*/
	{
		std::cout << "-------------- OBSERVERS ---------------" << std::endl;
		//-------------------------- KEY_COMPARE
		{
			ft_set myset;
			int highest;
			
			ft_set::key_compare mycomp = myset.key_comp();
			
			for (int i=0; i<=5; i++) myset.insert(i);
			
			std::cout << "myset contains:";
			
			highest=*myset.rbegin();
			ft_set::iterator it=myset.begin();
			do {
			std::cout << ' ' << *it;
			} while ( mycomp(*(++it),highest) );
			
			std::cout << std::endl;
		} // KEY_COMPARE

		//-------------------------- VALUE_COMP
		{
			ft_set myset;

			myset.insert(1001);
			myset.insert(2002);
			myset.insert(3003);			
			
			std::cout << "myset contains:" << std::endl;
			
			int highest = *myset.rbegin();          // last element
			
			ft_set::iterator it = myset.begin();
			do{
			std::cout << *it << std::endl;
			} while ( myset.value_comp()(*it++, highest) );
		} // VALUE_COMP
		
		std::cout << std::endl;
	}

	/*------------------------------ OPERATIONS ----------------------------*/
		std::cout << "-------------- OPERATIONS ---------------" << std::endl;
		
		//-------------------------- FIND
		{
			ft_set myset;
			ft_set::iterator it;
			
			// set some initial values:
			for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50
			
			it=myset.find(20);
			myset.erase (it);
			myset.erase (myset.find(40));
			
			std::cout << "myset contains:";
			for (it=myset.begin(); it!=myset.end(); ++it)
			std::cout << ' ' << *it;
			std::cout << std::endl;
		} // FIND

		//-------------------------- COUNT
		{
			ft_set myset;

			// set some initial values:
			for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

			for (int i=0; i<10; ++i)
			{
			std::cout << i;
			if (myset.count(i)!=0)
			std::cout << " is an element of myset." << std::endl;
			else
			std::cout << " is not an element of myset." << std::endl;
  }

		} // COUNT
			
		//-------------------------- LOWER / UPPER_BOUND
		{
			std::cout << "lower and upper bounds" << std::endl;

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
			std::cout << *itup << std::endl;

			myset.erase(itlow,itup);        // erases [itlow,itup)

			// print content:
			for (ft_set::iterator it=myset.begin(); it!=myset.end(); ++it)
			std::cout << *it << std::endl;

			
			// myset.print_tree();
			itlow = myset.lower_bound(0);
			std::cout << *itlow << std::endl;
			itup = myset.upper_bound(13);
			if (itup == myset.end())
				std::cout << "OK" << std::endl;
			else
				std::cout << "KO" << std::endl;
			// myset.print_tree();
			std::cout << *myset.upper_bound(5) << std::endl;
			std::cout << *myset.lower_bound(5) << std::endl;
			std::cout << *myset.upper_bound(3) << std::endl;
			std::cout << *myset.lower_bound(3) << std::endl;
			std::cout << *myset.upper_bound(2) << std::endl;
			std::cout << *myset.lower_bound(2) << std::endl;

		} // LOWER / UPPER_BOUND

		//-------------------------- EQUAL_RANGE
		{
			ft_set myset;

			for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

			ft::pair<ft_set::const_iterator,ft_set::const_iterator> ret;
			ret = myset.equal_range(30);

			std::cout << "the lower bound points to: " << *ret.first << std::endl;
			std::cout << "the upper bound points to: " << *ret.second << std::endl;

		} // EQUAL_RANGE


	// /*------------------------------ ALLOCATOR ----------------------------*/
	{
		std::cout << "-------------- ALLOCATOR ---------------" << std::endl;
	
		ft_set myset;
		int * p;
		unsigned int i;

		// allocate an array of 5 elements using myset's allocator:
		p=myset.get_allocator().allocate(5);

		// assign some values to array
		for (i=0; i<5; i++) p[i]=(i+1)*10;

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		myset.get_allocator().deallocate(p,5);
	}

	/*------------------------------ RELATIONAL OPERATORS ----------------------------*/
	{
		std::cout << "-------------- RELATIONAL OPERATORS ---------------" << std::endl;
	
		ft_set foo,bar,zob,bah;
		ut::fillSet<ft_set>(zob, 10, RANDOMIZED_QUEUE);
		ut::fillSet<ft_set>(bah, 10, RANDOMIZED_QUEUE);
		foo.insert(100);
		foo.insert(200);
		bar.insert(10);
		bar.insert(1000);

		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
		if (foo==bar) std::cout << "foo and bar are equal" << std::endl;
		if (foo!=bar) std::cout << "foo and bar are not equal" << std::endl;
		if (foo< bar) std::cout << "foo is less than bar" << std::endl;
		if (foo> bar) std::cout << "foo is greater than bar" << std::endl;
		if (foo<=bar) std::cout << "foo is less than or equal to bar" << std::endl;
		if (foo>=bar) std::cout << "foo is greater than or equal to bar" << std::endl;
	
		if (foo==zob) std::cout << "foo and zob are equal" << std::endl;
		if (foo!=zob) std::cout << "foo and zob are not equal" << std::endl;
		if (foo< zob) std::cout << "foo is less than zob" << std::endl;
		if (foo> zob) std::cout << "foo is greater than zob" << std::endl;
		if (foo<=zob) std::cout << "foo is less than or equal to zob" << std::endl;
		if (foo>=zob) std::cout << "foo is greater than or equal to zob" << std::endl;
	
		ft_set::iterator	it = bah.begin();
		// *it = 7; 
		if (bah==zob) std::cout << "bah and zob are equal" << std::endl;
		if (bah!=zob) std::cout << "bah and zob are not equal" << std::endl;
		if (bah< zob) std::cout << "bah is less than zob" << std::endl;
		if (bah> zob) std::cout << "bah is greater than zob" << std::endl;
		if (bah<=zob) std::cout << "bah is less than or equal to zob" << std::endl;
		if (bah>=zob) std::cout << "bah is greater than or equal to zob" << std::endl;
	} // RELATIONAL OPERATORS

	return (SUCCESS);
}