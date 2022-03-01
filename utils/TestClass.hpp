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

class TestClass
{
   public:

    	static int objectCount;
      
    	TestClass()
		{
			_name = new std::string("default");
    		_number = objectCount++;
    		std::cout << _number << " - Default Constructor called." << std::endl;
      	}

		TestClass(const TestClass &src)
	  	{
			_name = new std::string("copy");
			_number = src.objectCount++;
      		std::cout << _number << " - Copy Constructor called." << std::endl;
	  	}

		TestClass( std::string name ) : _name(new std::string(name))
		{
			_number = objectCount++;
    		std::cout << _number << " - String Constructor called." << std::endl;
		}

		~TestClass()
		{
      		std::cout << _number << " - Destructor called ------- DEAD" << std::endl;
			delete _name;
		}

		std::string	getName() const
		{
			return (*_name);
		}
      
   private:
      
		std::string	*_name;
		int			_number;
};

#endif /* ****************************************************** TestClass_H */