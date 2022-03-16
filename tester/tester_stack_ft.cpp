/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_stack_ft.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:40:59 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 16:25:23 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/tester.hpp"

int	tester_stack_ft()
{
	// ---------------------- constructors
	ft::vector<TestClass> myvector (2,200);        // vector with 2 elements

	ft::stack<TestClass> first;                    // empty stack

	ft::stack<TestClass,ft::vector<TestClass> > third;  // empty stack using vector
	ft::stack<TestClass,ft::vector<TestClass> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	// ----------------------------- empty
	// deque
	{
		ft::stack<int> mystack;
		int sum (0);
	
		for (int i=1;i<=10;i++) mystack.push(i);
	
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
	
		std::cout << "total: " << sum << std::endl;
	}
	// ft::vector
	{
		ft::stack<int, ft::vector<int> > mystack;
		int sum (0);
	
		for (int i=1;i<=10;i++) mystack.push(i);
	
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
	
		std::cout << "total: " << sum << std::endl;
	}
	// ----------------------------- size
	// deque
	{
		ft::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';
		
		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';
		
		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	// ft::vector
	{
		ft::stack<int, ft::vector<int> > myints;
		std::cout << "0. size: " << myints.size() << '\n';
		
		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';
		
		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	// ------------------------------- top
	// deque
	{
		ft::stack<int> mystack;
		
		mystack.push(10);
		mystack.push(20);
		
		mystack.top() -= 5;
		
		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	// ft::vector
	{
		ft::stack<int, ft::vector<int> > mystack;
		
		mystack.push(10);
		mystack.push(20);
		
		mystack.top() -= 5;
		
		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	// ------------------------ pop / push
	// deque
	{
		ft::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << std::endl;
	}
	// ft::vector
	{
		ft::stack<int, ft::vector<int> > mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << std::endl;
	}
	// -------------- relational operators
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (2,200);   // two ints with a value of 200
		ft::stack<int, ft::vector<int> >	foo_stack(foo);
		ft::stack<int, ft::vector<int> >	bar_stack(bar);

		if (foo_stack == bar_stack) std::cout << "foo_stack and bar_stack are equal" << std::endl;
		if (foo_stack != bar_stack) std::cout << "foo_stack and bar_stack are not equal" << std::endl;
		if (foo_stack < bar_stack) std::cout << "foo_stack is less than bar_stack" << std::endl;
		if (foo_stack > bar_stack) std::cout << "foo_stack is greater than bar_stack" << std::endl;
		if (foo_stack <= bar_stack) std::cout << "foo_stack is less than or equal to bar_stack" << std::endl;
		if (foo_stack >= bar_stack) std::cout << "foo_stack is greater than or equal to bar_stack" << std::endl;
	}
	return (SUCCESS);
}