/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestClass.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:57:36 by llecoq            #+#    #+#             */
/*   Updated: 2022/01/18 13:35:50 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTCLASS_HPP
# define TESTCLASS_HPP

# include <iostream>
# include <string>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

class TestClass
{
   public:

    	static int objectCount;
      
    	TestClass()
		{
			_name = new std::string("Default");
    		_number = objectCount++;
    		std::cout << CYAN << _number << " - Default Constructor called." << RESET << std::endl;
      	}

		TestClass(const TestClass &src)
	  	{
			_name = new std::string("Copy");
			_number = src.objectCount++;
			_i = src._i;
      		std::cout << GREEN << _number << " - Copy Constructor called." << RESET << std::endl;
	  	}

		TestClass( std::string name ) : _name(new std::string(name))
		{
			_number = objectCount++;
    		std::cout << _number << " - String Constructor called." << std::endl;
		}

		TestClass(int i) : _i(i)
		{
			_name = new std::string("I");
			_number = objectCount++;
    		std::cout << _number << " - I Constructor called." << std::endl;
		}

		~TestClass()
		{
			if (*_name == "Default")
      			std::cout << CYAN << _number << " - " << *_name << RED 
				<< " Destructor " << CYAN << "called" << RESET << std::endl;
			else
      			std::cout << GREEN << _number << " - " << *_name << RED 
				<< " Destructor " << GREEN << "called" << RESET << std::endl;
			delete _name;
		}

		std::string	getName() const
		{
			return (*_name);
		}
		
		int	getNumber() const
		{
			return (_number);
		}

		int	getI() const
		{
			return (_i);
		}
      
   private:
      
		std::string	*_name;
		int			_number;
		int			_i;
};

#endif /* ****************************************************** TestClass_H */