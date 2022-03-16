/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 15:10:48 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/16 16:18:01 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <deque>
#include <list>
#include "vector.hpp"

namespace ft
{

/*
** ----------------------------------------------------------------------- STACK
*/
template <class T, class Container = std::deque<T> >
class stack
{
	public :
	
		typedef T											value_type;
		typedef Container									container_type;
		typedef typename Container::size_type				size_type;
	
		explicit stack (const container_type& ctnr = container_type())
			: _ctnr(ctnr) {}
	
	/*
	** -------------------------------------------------------- MEMBER FUNCTIONS
	*/
		bool empty() const {return _ctnr.empty();}
		size_type size() const {return _ctnr.size();}
		value_type& top() {return _ctnr.back();}
		const value_type& top() const {return _ctnr.back();}
		void push (const value_type& val) {_ctnr.push_back(val);}
		void pop () {_ctnr.pop_back();}


	/*
	** ---------------------------------------------------- RELATIONAL OPERATORS
	*/
		friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return lhs._ctnr == rhs._ctnr;}
	
		friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return lhs._ctnr != rhs._ctnr;}
	
		friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return lhs._ctnr < rhs._ctnr;}
	
		friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return lhs._ctnr <= rhs._ctnr;}
	
		friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return lhs._ctnr > rhs._ctnr;}
	
		friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
		{return lhs._ctnr >= rhs._ctnr;}
	
	private :

		container_type		_ctnr;

};

}

#endif