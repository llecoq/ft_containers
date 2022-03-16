/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_vector_std.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:26:55 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 10:21:00 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_vector_std(void)
{
	/*----------------------------- ITERATOR -----------------------------*/
	{
		std::cout << "-------------- ITERATOR ----------------" << std::endl;
		std::vector<int>				vec(5, 10);
		std::vector<int>::iterator	it = vec.begin();
		std::vector<int>::iterator	itcopy(it);
		std::vector<int>::iterator	ittmp = it;
		if (it == itcopy)
			std::cout << "it == itcopy" << std::endl;
	
		/*-------------------- MEMBER ACCESS */
		std::cout << "------------ MEMBER ACCESS -------------" << std::endl;
		std::vector<TestClass>				michel;
		michel.push_back(TestClass());
		std::vector<TestClass>::iterator	iterClass = michel.begin();
		
		// indirection to rvalue
		std::cout << *it << std::endl;
		// member pointer
		std::cout << iterClass->getName() << std::endl;
		// indirection
		int	m = *it;
		std::cout << m << std::endl;

		/*------------------------ INCREMENT */
		std::cout << "-------------- INCREMENT ---------------" << std::endl;
		ittmp = ++it;
		if (ittmp != vec.begin())
			std::cout << "pre incrementation OK" << std::endl;
		else
			std::cout << "pre incrementation KO" << std::endl;
		ittmp = itcopy++;
		if (ittmp == vec.begin() && itcopy == it)
			std::cout << "post incrementation OK" << std::endl;
		else
			std::cout << "post incrementation KO" << std::endl;
		// std::vector<int>::const_iterator	constit = vec.begin();
		// constit = vec.begin();
		// CONST DE MAAAAARDE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		
		/*------------------------ DECREMENT */
		std::cout << "-------------- DECREMENT ---------------" << std::endl;
		it = vec.end();
		ittmp = --it;
		if (ittmp != vec.end())
			std::cout << "pre decrementation OK" << std::endl;
		else
			std::cout << "pre decrementation KO" << std::endl;
		itcopy = vec.end();
		ittmp = itcopy--;
		if (itcopy != vec.end() && ittmp == vec.end())
			std::cout << "post decrementation OK" << std::endl;
		else
			std::cout << "post decrementation KO" << std::endl;
		std::vector<int>::iterator	ite = vec.end();
		if (it != ite)
			std::cout << "it != ite" << std::endl;
		it = vec.begin();
		std::cout << *it-- << std::endl;
		
		/*----------------------- ARITHMETIC */
		std::cout << "-------------- ARITHMETIC --------------" << std::endl;
		it = vec.begin() + 5;
		if (it == vec.end())
			std::cout << "arithemtic operator a + n OK" << std::endl;
		else
			std::cout << "arithemtic operator a + n KO" << std::endl;
		it = 5 + vec.begin();
		if (it == vec.end())
			std::cout << "arithemtic operator n + a OK" << std::endl;
		else
			std::cout << "arithemtic operator n + a KO" << std::endl;
		it = vec.end() - 5;
		if (it == vec.begin())
			std::cout << "arithemtic operator a - n OK" << std::endl;
		else
			std::cout << "arithemtic operator a - n KO" << std::endl;
		std::cout << vec.end() - ++vec.begin() << std::endl;

		/*------------ INEQUALITY RELATIONAL */
		std::cout << "-------------- RELATIONAL --------------" << std::endl;
		if (vec.begin() < vec.end())
			std::cout << "inequality relational < operator OK" << std::endl;
		else
			std::cout << "inequality relational < operator KO" << std::endl;
		if (vec.end() > vec.begin())
			std::cout << "inequality relational > operator OK" << std::endl;
		else
			std::cout << "inequality relational > operator KO" << std::endl;
		if (vec.begin() <= vec.end() && vec.begin() <= vec.begin())
			std::cout << "inequality relational <= operator OK" << std::endl;
		else
			std::cout << "inequality relational <= operator KO" << std::endl;
		if (vec.end() >= vec.begin() && vec.end() >= vec.end())
			std::cout << "inequality relational >= operator OK" << std::endl;
		else
			std::cout << "inequality relational >= operator KO" << std::endl;
	
		/*-------------- COMPOUND ASSIGNMENT */
		std::cout << "---------- COMPOUND ASSIGNMENT ----------" << std::endl;
		if ((vec.begin() += 5) == vec.end())
			std::cout << "compound assignment += OK" << std::endl;
		else
			std::cout << "compound assignment += KO" << std::endl;
		if ((vec.end() -= 5) == vec.begin())
			std::cout << "compound assignment -= OK" << std::endl;
		else
			std::cout << "compound assignment -= KO" << std::endl;

		/*------------------------ SUBSCRIPT */
		std::cout << "-------------- SUBSCRIPT ---------------" << std::endl;
		std::cout << it[2] << std::endl;
	}

	/*----------------------------- CAPACITY -----------------------------*/
		/*--------------------------- SIZE -------------------------------*/
	{
		std::cout << "----------------- SIZE -----------------" << std::endl;
		std::vector<int>			vec(5, 10);
		std::vector<int>			empty;
		std::vector<TestClass>	testClass;

		std::cout << vec.size() << std::endl;
		std::cout << empty.size() << std::endl;
		std::cout << testClass.size() << std::endl;
	}
		/*------------------------- MAX_SIZE -----------------------------*/
		std::cout << "--------------- MAX SIZE ----------------" << std::endl;
	{
		std::vector<int>			vec_int;
		std::vector<char>		vec_char;
		std::vector<TestClass>	testClass;

		std::cout << vec_int.max_size() << std::endl;
		std::cout << vec_char.max_size() << std::endl;
		std::cout << testClass.max_size() << std::endl;
		try
		{
			std::vector<int>	vec(-1, 10);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::vector<int>			vec_int;
		std::vector<char>			vec_char;
		std::vector<double>			vec_double;
		std::vector<float>			vec_float;
		std::vector<long>			vec_long;
		std::vector<const char>		vec_const_char;
		std::vector<const int>		vec_const_int;
		std::vector<TestClass>		vec_class;

		std::cout << "vec_int max_size = " << vec_int.max_size() << std::endl;
		std::cout << "vec_char max_size = " << vec_char.max_size() << std::endl;
		std::cout << "vec_double max_size = " << vec_double.max_size() << std::endl;
		std::cout << "vec_float max_size = " << vec_float.max_size() << std::endl;
		std::cout << "vec_long max_size = " << vec_long.max_size() << std::endl;
		std::cout << "vec_const char max_size = " << vec_const_char.max_size() << std::endl;
		std::cout << "vec_const int max_size = " << vec_const_int.max_size() << std::endl;
		std::cout << "vec_int TestClass = " << vec_class.max_size() << std::endl;
	}
		/*------------------------- ASSIGN -----------------------------*/
		std::cout << "--------------- ASSIGN ----------------" << std::endl;
	{
		std::vector<TestClass> first;
		std::vector<TestClass> second;
		std::vector<TestClass> third;
		// std::vector<TestClass> fourth;

		first.assign (7,100);             // 7 ints with a value of 100
		ft::displayData(first);
		ft::displayVec(first);

		first.assign (10,100);             // 7 ints with a value of 100
		ft::displayData(first);
		ft::displayVec(first);

		std::vector<TestClass>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first
		ft::displayData(second);
		ft::displayVec(second);

		int myints[] = {1776,7,4};
		float myfloat[] = {12.1, 15.3, 42.9};
		third.assign (myfloat,myfloat+3);   // assigning from array.
		third.assign (myints,myints+3);   // assigning from array.
		ft::displayData(third);
		ft::displayVec(third);

		// fourth.assign(10.5, 5.5);

		ft::displayVec(first);
		first.assign(1, 10);
		ft::displayData(first);
		ft::displayVec(first);

		first.assign(second.begin(), second.end());
		ft::displayData(first);
		ft::displayVec(first);
		
		first.assign(20, 10);
		ft::displayData(first);
		ft::displayVec(first);
		
		first.assign(5, 10);
		ft::displayData(first);
		ft::displayVec(first);

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	}
		/*------------------------- CLEAR -----------------------------*/
		std::cout << "--------------- CLEAR ----------------" << std::endl;
	{
		std::vector<TestClass> myvector;
		myvector.clear();
		ft::displayData(myvector);
		
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);
		
		ft::displayVec(myvector);
	
		ft::displayData(myvector);
		std::cout << "clear :" << std::endl;
		myvector.clear();
		ft::displayData(myvector);
		ft::displayVec(myvector);
	
	
		std::cout << "resize" << std::endl;
		myvector.resize(12, TestClass(1));
		ft::displayData(myvector);
		std::cout << "clear :" << std::endl;
		myvector.clear();
		ft::displayData(myvector);
	
		myvector.push_back (1101);
		myvector.push_back (2202);
		
		ft::displayVec(myvector);
	}
		/*-------------------- COPY ASSIGNMENT ------------------------*/
		std::cout << "---------- COPY ASSIGNMENT -----------" << std::endl;
	{
		std::vector<TestClass>	vec(5, 100);
		std::vector<TestClass>	vec_2;
	
		ft::pushBackVec(vec_2);
	
		ft::displayData(vec, "vec");
		ft::displayVec(vec);
		ft::displayData(vec_2, "vec_2");
		ft::displayVec(vec_2);
	
		vec_2 = vec;
		ft::displayData(vec_2, "vec_2");
		ft::displayVec(vec_2);
	
		std::vector<TestClass>	vec_3 = vec;
		ft::displayData(vec_3, "vec_3");
		ft::displayVec(vec_3);
	}
		/*-------------------- COPY CONSTRUCTOR ------------------------*/
		std::cout << "---------- COPY CONSTRUCTOR -----------" << std::endl;
	{	/* COPY CONSTRUCTOR */
		std::vector<TestClass>		vec;
	
		ft::pushBackVec(vec, 5);
		ft::displayData(vec);
		ft::displayVec(vec);

		std::vector<TestClass>		copy(vec);
		ft::displayData(copy, "copy");
		ft::displayVec(copy);

		// /* RANGE */
		std::vector<TestClass>	range(vec.begin() + 1, vec.end());
		ft::displayData(range, "range");
		ft::displayVec(range);
	}
	{	/* OPERATOR= */
		std::vector<TestClass>		vec;
		std::vector<TestClass>		copy;
	
		ft::pushBackVec(vec, 5);
		for (int i = 10; i > 0; i--)
			copy.push_back(TestClass(i));
		ft::displayData(vec);
		ft::displayVec(vec);
		ft::displayData(copy, "copy");
		ft::displayVec(copy);

		copy = vec;
		ft::displayData(copy, "copy");
		ft::displayVec(copy);
	}	
		/*--------------------- ELEMENT ACCESS -------------------------*/
		std::cout << "----------- ELEMENT ACCESS ------------" << std::endl;
	{	// OPERATOR[]
		std::vector<int> myvector (10);   // 10 zero-initialized elements

		std::vector<int>::size_type sz = myvector.size();

		// assign some values:
		for (unsigned i=0; i<sz; i++) myvector[i]=i;

		// reverse vector using operator[]:
		for (unsigned i=0; i<sz/2; i++)
		{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	{	// AT
		std::vector<int> myvector (10);   // 10 zero-initialized ints
		
		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;
		
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
		try
		{
			std::cout << myvector.at(15);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	{	// FRONT
		std::vector<int> myvector;
		
		// std::cout << myvector.back() << std::endl; // undefined when called on empty vector
		myvector.push_back(78);
		myvector.push_back(16);
		
		// now front equals 78, and back 16
		
		myvector.front() -= myvector.back();
		
		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	}
	{	// BACK
		std::vector<int> myvector;
		
		myvector.push_back(10);
		
		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}
		
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
		/*------------------------- ERASE -----------------------------*/
		std::cout << "--------------- ERASE ----------------" << std::endl;
	{
		std::vector<TestClass> myvector;

		// set some values (from 1 to 10)
		ft::pushBackVec(myvector);
		ft::displayDataVec(myvector);

		// erase the 6th element
		std::cout << std::endl << "erase 6th element" << std::endl;
		myvector.erase (myvector.begin()+5);
		ft::displayDataVec(myvector);

		// erase the first 3 elements:
		std::cout << "erase 3 first elements" << std::endl;
		myvector.erase (myvector.begin(),myvector.begin()+3);
		ft::displayDataVec(myvector);
	}
		/*------------------------- INSERT -----------------------------*/
		std::cout << "--------------- INSERT ----------------" << std::endl;
	{
		std::vector<TestClass> myvector (3, TestClass(100));
		std::vector<TestClass>::iterator it;

		ft::displayData(myvector);
		std::cout << "resize 6" << std::endl;
		myvector.resize(6, TestClass());
		ft::displayData(myvector);
		ft::displayVec(myvector);

		it = myvector.begin();
		std::cout << "insert ( it + 1 , 200 )" << std::endl;
		it = myvector.insert ( it + 1 , 200 );

		std::cout << "insert ( it + 1 , 200 )" << std::endl;
		it = myvector.insert ( it + 1 , 200 );

		ft::displayData(myvector);
		ft::displayVec(myvector);

		std::cout << "insert ( it,5,300 )" << std::endl;
		myvector.insert (it,5,300);
		std::cout << "(myvector.begin() + 5,1,50)" << std::endl;
		myvector.insert (myvector.begin() + 5,1,50);

		ft::displayData(myvector);
		ft::displayVec(myvector);

		std::cout << "insert (myvector.begin() + 12,20,1)" << std::endl;
		myvector.insert (myvector.begin() + 12,20,1);

		ft::displayData(myvector);
		ft::displayVec(myvector);

		it = myvector.begin();
		std::vector<TestClass> anothervector (2, TestClass(400));
			myvector.insert (it+2,anothervector.begin(),anothervector.end());

		ft::displayData(myvector);
		ft::displayVec(myvector);

		int myarray [] = { 501,502,503,504,505,506,507,508 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		ft::displayData(myvector);
		ft::displayVec(myvector);
	}
		/*------------------------ IS INTEGRAL ---------------------------*/
		std::cout << "-------------- IS INTEGRAL --------------" << std::endl;
	{
		// bool, char, char16_t, char32_t, wchar_t, short, int, long, long long

		//	bool
		std::cout << "bool :" << std::endl;
		std::cout << ft::is_integral<bool>::value << std::endl;
		std::cout << ft::is_integral<volatile bool>::value << std::endl;
		std::cout << ft::is_integral<const bool>::value << std::endl;
		//	char
		std::cout << "char :" << std::endl;
		std::cout << ft::is_integral<char>::value << std::endl;
		std::cout << ft::is_integral<const char>::value << std::endl;
		std::cout << ft::is_integral<volatile char>::value << std::endl;
		std::cout << ft::is_integral<unsigned char>::value << std::endl;
		std::cout << ft::is_integral<const unsigned char>::value << std::endl;
		std::cout << ft::is_integral<volatile unsigned char>::value << std::endl;
		//	char16_t
		std::cout << "char16_t :" << std::endl;
		std::cout << ft::is_integral<char16_t>::value << std::endl;
		std::cout << ft::is_integral<const char16_t>::value << std::endl;
		std::cout << ft::is_integral<volatile char16_t>::value << std::endl;
		//	char32_t
		std::cout << "char32_t :" << std::endl;
		std::cout << ft::is_integral<char32_t>::value << std::endl;
		std::cout << ft::is_integral<const char32_t>::value << std::endl;
		std::cout << ft::is_integral<volatile char32_t>::value << std::endl;
		//	wchar_t
		std::cout << "wchar_t :" << std::endl;
		std::cout << ft::is_integral<wchar_t>::value << std::endl;
		std::cout << ft::is_integral<const wchar_t>::value << std::endl;
		std::cout << ft::is_integral<volatile wchar_t>::value << std::endl;
		//	short
		std::cout << "short :" << std::endl;
		std::cout << ft::is_integral<short>::value << std::endl;
		std::cout << ft::is_integral<const short>::value << std::endl;
		std::cout << ft::is_integral<volatile short>::value << std::endl;
		std::cout << ft::is_integral<unsigned short>::value << std::endl;
		std::cout << ft::is_integral<const unsigned short>::value << std::endl;
		std::cout << ft::is_integral<volatile unsigned short>::value << std::endl;
		//	int
		std::cout << "int :" << std::endl;
		std::cout << ft::is_integral<int>::value << std::endl;
		std::cout << ft::is_integral<const int>::value << std::endl;
		std::cout << ft::is_integral<volatile int>::value << std::endl;
		std::cout << ft::is_integral<unsigned int>::value << std::endl;
		std::cout << ft::is_integral<const unsigned int>::value << std::endl;
		std::cout << ft::is_integral<volatile unsigned int>::value << std::endl;
		//	long
		std::cout << "long :" << std::endl;
		std::cout << ft::is_integral<long>::value << std::endl;
		std::cout << ft::is_integral<const long>::value << std::endl;
		std::cout << ft::is_integral<volatile long>::value << std::endl;
		std::cout << ft::is_integral<unsigned long>::value << std::endl;
		std::cout << ft::is_integral<const unsigned long>::value << std::endl;
		std::cout << ft::is_integral<volatile unsigned long>::value << std::endl;
		//	long long
		std::cout << "long long :" << std::endl;
		std::cout << ft::is_integral<long long>::value << std::endl;
		std::cout << ft::is_integral<const long long>::value << std::endl;
		std::cout << ft::is_integral<volatile long long>::value << std::endl;
		std::cout << ft::is_integral<unsigned long long>::value << std::endl;
		std::cout << ft::is_integral<const unsigned long long>::value << std::endl;
		std::cout << ft::is_integral<volatile unsigned long long>::value << std::endl;

		// float / double (...)
		std::cout << "float / double (...) :" << std::endl;
		std::cout << ft::is_integral<float>::value << std::endl;
		std::cout << ft::is_integral<double>::value << std::endl;
		std::cout << ft::is_integral<const double>::value << std::endl;
		std::cout << ft::is_integral<char *>::value << std::endl;
		std::cout << ft::is_integral<TestClass>::value << std::endl;
		std::cout << ft::is_integral<int *>::value << std::endl;
	}
		/*------------------------- POP BACK ----------------------------*/
		std::cout << "--------------- POP BACK ---------------" << std::endl;
	{
		std::vector<int>	vec;
		// vec.pop_back(); // std::vector non protege, segfault
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		dprintf(1, "pop back\n");
		vec.pop_back();
		dprintf(1, "pop back done\n");

		std::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);
		
		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		std::cout << "The elements of myvector add up to " << sum << std::endl;
	}
		/*------------------------ PUSH BACK ----------------------------*/
		std::cout << "-------------- PUSH BACK ---------------" << std::endl;
	{
		std::vector<TestClass>	ft;
		std::vector<TestClass>::iterator	it = ft.begin();
		std::vector<TestClass>::iterator	ite = ft.end();

		ft.push_back(TestClass());
		dprintf(1, "%zu -----------------------------------\n", ft.capacity());
		it = ft.begin();
		ite = ft.end();
		while (it != ite)
		{
			dprintf(1, "%d ", it->getNumber());
			it++;
		}
		dprintf(1, "\n");	
		ft.push_back(TestClass());
		dprintf(1, "%zu -----------------------------------\n", ft.capacity());
		it = ft.begin();
		ite = ft.end();
		while (it != ite)
		{
			dprintf(1, "%d ", it->getNumber());
			it++;
		}
		dprintf(1, "\n");	
		ft.push_back(TestClass());
		dprintf(1, "%zu -----------------------------------\n", ft.capacity());
		it = ft.begin();
		ite = ft.end();
		while (it != ite)
		{
			dprintf(1, "%d ", it->getNumber());
			it++;
		}
		dprintf(1, "\n");	
		ft.push_back(TestClass());
		dprintf(1, "%zu -----------------------------------\n", ft.capacity());
		it = ft.begin();
		ite = ft.end();
		while (it != ite)
		{
			dprintf(1, "%d ", it->getNumber());
			it++;
		}
		dprintf(1, "\n");
		ft.push_back(TestClass());
		dprintf(1, "%zu -----------------------------------\n", ft.capacity());
		it = ft.begin();
		ite = ft.end();
		while (it != ite)
		{
			dprintf(1, "%d ", it->getNumber());
			it++;
		}
		dprintf(1, "\n");	
		ft.push_back(TestClass());
		dprintf(1, "%zu -----------------------------------\n", ft.capacity());
		it = ft.begin();
		ite = ft.end();
		while (it != ite)
		{
			dprintf(1, "%d ", it->getNumber());
			it++;
		}
		dprintf(1, "\n");
	}
		/*--------------------- RELATIONAL OPERATORS -------------------------*/
		std::cout << "----------- RELATIONAL OPERATORS ------------" << std::endl;
	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
		std::vector<int> bar (2,200);   // two ints with a value of 200
		
		if (foo == bar) std::cout << "foo and bar are equal" << std::endl;
		if (foo != bar) std::cout << "foo and bar are not equal" << std::endl;
		if (foo < bar) std::cout << "foo is less than bar" << std::endl;
		if (foo > bar) std::cout << "foo is greater than bar" << std::endl;
		if (foo <= bar) std::cout << "foo is less than or equal to bar" << std::endl;
		if (foo >= bar) std::cout << "foo is greater than or equal to bar" << std::endl;

		std::vector<int>	vec;
		std::vector<int>	vec_2;

		ft::pushBackVec(vec);
		ft::pushBackVec(vec_2);
		if (vec == vec_2) std::cout << "vec == vec_2" << std::endl;
		vec.insert(vec.begin() + 2, 3);
		if (vec == vec_2) std::cout << "vec and vec_2 are equal" << std::endl;
		if (vec != vec_2) std::cout << "vec and vec_2 are not equal" << std::endl;
		if (vec < vec_2) std::cout << "vec is less than vec_2" << std::endl;
		if (vec > vec_2) std::cout << "vec is greater than vec_2" << std::endl;
		if (vec <= vec_2) std::cout << "vec is less than or equal to vec_2" << std::endl;
		if (vec >= vec_2) std::cout << "vec is greater than or equal to vec_2" << std::endl;

		vec_2.resize(3, 2);
		if (vec == vec_2) std::cout << "vec and vec_2 are equal" << std::endl;
		if (vec != vec_2) std::cout << "vec and vec_2 are not equal" << std::endl;
		if (vec < vec_2) std::cout << "vec is less than vec_2" << std::endl;
		if (vec > vec_2) std::cout << "vec is greater than vec_2" << std::endl;
		if (vec <= vec_2) std::cout << "vec is less than or equal to vec_2" << std::endl;
		if (vec >= vec_2) std::cout << "vec is greater than or equal to vec_2" << std::endl;
	
		std::vector<std::string> string(2, "AH");
		std::vector<std::string> string_2(2, "MAIS");
		if (string == string_2) std::cout << "string and string_2 are equal" << std::endl;
		if (string != string_2) std::cout << "string and string_2 are not equal" << std::endl;
		if (string < string_2) std::cout << "string is less than string_2" << std::endl;
		if (string > string_2) std::cout << "string is greater than string_2" << std::endl;
		if (string <= string_2) std::cout << "string is less than or equal to string_2" << std::endl;
		if (string >= string_2) std::cout << "string is greater than or equal to string_2" << std::endl;
	}
		/*----------------------------- RESERVE ------------------------------*/
		std::cout << "------------------- RESERVE -----------------" << std::endl;
	{
		std::vector<int> foo;
		std::cout << "making foo grow:\n";
		ft::pushBackVec(foo, 100);
		ft::displayDataVec(foo, "foo");

		std::vector<TestClass> bar;
		ft::pushBackVec(bar, 3);
		ft::displayDataVec(bar, "bar");
		
		std::cout << "reserve 100" << std::endl;
		bar.reserve(100);   // this is the only difference with foo above
		ft::displayDataVec(bar, "bar");

		std::cout << "making bar grow:\n";
		ft::pushBackVec(bar);
		ft::displayDataVec(bar, "bar");

		std::cout << "foo reserve 1" << std::endl;
		foo.reserve(1);
		std::cout << "bar reserve 1" << std::endl;
		bar.reserve(1);
		ft::displayDataVec(bar, "bar");
		std::cout << "foo reserve 103" << std::endl;
		foo.reserve(103);
		ft::displayDataVec(foo, "foo");
	}
		/*----------------------------- RESIZE ------------------------------*/
		std::cout << "------------------- RESIZE -----------------" << std::endl;
	{
		std::vector<TestClass>		vec;

		for (int i = 0; i < 3; i++)
			vec.push_back(TestClass());
		vec.reserve(4);
		ft::displayVec(vec);
		ft::displayData(vec);
		vec.resize(15, TestClass());
		ft::displayData(vec);
		ft::displayVec(vec);
		vec.resize(2, TestClass());
		ft::displayData(vec);
		ft::displayVec(vec);
		vec.resize(20, 1);
		ft::displayData(vec);
		ft::displayVec(vec);
	}
		/*------------------------- REVERSE ITERATOR -------------------------*/
		std::cout << "--------------- REVERSE ITERATOR ------------" << std::endl;
	{
		std::vector<TestClass>					myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		ft::displayVec(myvector);

		std::vector<TestClass>::reverse_iterator	rev_it = myvector.rbegin();
		std::vector<TestClass>::reverse_iterator	rev_ite (myvector.rend());
		std::vector<TestClass>::reverse_iterator	copy;
		copy = rev_it;
		std::cout << "*rev_it = " << *rev_it;
		std::cout << "*copy = " << *copy;
		std::cout << "*rev_ite - 1 = " << *(rev_ite - 1);
		while (++rev_it != rev_ite)
			std::cout << "base = " << *rev_it.base() << "*rev_it = " << *rev_it;
		rev_ite = myvector.rend();
		std::cout << *(rev_ite - 2);
		rev_it = myvector.rbegin();
		std::cout << *(rev_it + 3);
		std::cout << (rev_it + 3)->getI() << std::endl;
		std::cout << rev_it[2];
		std::cout << "myvector has " << myvector.rend() - myvector.rbegin() << " elements." << std::endl;
		rev_it = 3 + myvector.rbegin();
		std::cout << "The fourth element from the end is: " << *rev_it;
		std::cout << (myvector.rbegin() == myvector.rend()) << std::endl;
		std::cout << (myvector.rbegin() == myvector.rbegin()) << std::endl;
		std::cout << (myvector.rbegin() != myvector.rend()) << std::endl;
		std::cout << (myvector.rbegin() != myvector.rbegin()) << std::endl;
		std::cout << (myvector.rbegin() < myvector.rend()) << std::endl;
		std::cout << (myvector.rend() < myvector.rbegin()) << std::endl;
		std::cout << (myvector.rend() > myvector.rbegin()) << std::endl;
		std::cout << (myvector.rbegin() > myvector.rend()) << std::endl;
		std::cout << (myvector.rbegin() >= myvector.rend()) << std::endl;
		std::cout << (myvector.rbegin() >= myvector.rbegin()) << std::endl;
		std::cout << (myvector.rbegin() <= myvector.rend()) << std::endl;
		std::cout << (myvector.rbegin() <= myvector.rbegin()) << std::endl;
	}
		/*------------------------------ SWAP ------------------------------*/
		std::cout << "-------------------- SWAP -----------------" << std::endl;
	{
		std::vector<TestClass>	vec;
		
		std::vector<TestClass>	vec_2(5, 100);

		ft::pushBackVec(vec);
		ft::displayData(vec, "vec");
		ft::displayVec(vec);

		ft::displayData(vec_2, "vec_2");
		ft::displayVec(vec_2);

		std::cout << "SWAP MEMBER" << std::endl;
		vec_2.swap(vec);

		ft::displayData(vec, "vec");
		ft::displayVec(vec);

		ft::displayData(vec_2, "vec_2");
		ft::displayVec(vec_2);

		std::cout << "SWAP NON MEMBER" << std::endl;
		swap(vec, vec_2);
		ft::displayData(vec, "vec");
		ft::displayVec(vec);

		ft::displayData(vec_2, "vec_2");
		ft::displayVec(vec_2);
	}
	return (0);
}