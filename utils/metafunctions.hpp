/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metafunctions.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llecoq <llecoq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:04:14 by llecoq            #+#    #+#             */
/*   Updated: 2022/03/14 18:29:44 by llecoq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	METAFUNCTIONS_HPP
#define	METAFUNCTIONS_HPP

// #include "../iterators/iterator.hpp"

namespace	ft
{
	/*
	** --------------------------------------------------------------- ENABLE_IF
	*/

	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	/*
	** -------------------------------------------------------------- TRUE FALSE
	*/

	struct	true_type
	{
		static const bool value = true;
	};

	struct	false_type
	{
		static const bool value = false;
	};

	/*
	** ----------------------------------------------------------------- IS_SAME
	*/

	template < typename T, typename U >
	struct	is_same : false_type {};

	template < typename T >
	struct	is_same<T, T> : true_type {};

	/*
	** ------------------------------------------------------- IS_INPUT_ITERATOR
	*/

	// template< typename T, typename U >
	// struct	is_input_iterator : false_type {};

	// template< typename T >
	// struct	is_input_iterator<T, typename enable_if<is_same<typename ft::iterator_traits<T>::value_type, void>::value>::type> : true_type {};

	// template < typename InputIterator, typename U >
	// struct	is_input_iterator : false_type {};

	// template < typename InputIterator >
	// struct	is_input_iterator< enable_if< is_same< typename InputIterator::iterator_category, random_access_iterator_tag>::value >, InputIterator >: true_type {};

	// template <typename Iter>
	// using require_input_iterator = enable_if_t<std::is_base_of_v<
	// std::input_iterator_tag, typename std::iterator_traits<Iter>::iterator_category>>;

// typename ft::enable_if<(ft::is_same<InputIterator, reverse_iterator>::value) 
		// || (ft::is_same<InputIterator, random_access_iterator>::value) 
		// || (ft::is_same<InputIterator, pointer>::value), InputIterator>::type first,

		// typename ft::enable_if< ft::is_same<InputIterator, pointer>::value, InputIterator>::type first,

	/*
	** ------------------------------------------------------------- IS_INTEGRAL
	*/

	template <typename>
	struct	is_integral_base : false_type {};
	
	//	bool
	template<> struct is_integral_base<bool> : true_type {};
	template<> struct is_integral_base<volatile bool> : true_type {};
	template<> struct is_integral_base<const bool> : true_type {};
	//	char
	template<> struct is_integral_base<char> : true_type {};
	template<> struct is_integral_base<const char> : true_type {};
	template<> struct is_integral_base<volatile char> : true_type {};
	template<> struct is_integral_base<unsigned char> : true_type {};
	template<> struct is_integral_base<const unsigned char> : true_type {};
	template<> struct is_integral_base<volatile unsigned char> : true_type {};
	//	char16_t
	template<> struct is_integral_base<char16_t> : true_type {};
	template<> struct is_integral_base<const char16_t> : true_type {};
	template<> struct is_integral_base<volatile char16_t> : true_type {};
	//	char32_t
	template<> struct is_integral_base<char32_t> : true_type {};
	template<> struct is_integral_base<const char32_t> : true_type {};
	template<> struct is_integral_base<volatile char32_t> : true_type {};
	//	wchar_t
	template<> struct is_integral_base<wchar_t> : true_type {};
	template<> struct is_integral_base<const wchar_t> : true_type {};
	template<> struct is_integral_base<volatile wchar_t> : true_type {};
	//	short
	template<> struct is_integral_base<short> : true_type {};
	template<> struct is_integral_base<const short> : true_type {};
	template<> struct is_integral_base<volatile short> : true_type {};
	template<> struct is_integral_base<unsigned short> : true_type {};
	template<> struct is_integral_base<const unsigned short> : true_type {};
	template<> struct is_integral_base<volatile unsigned short> : true_type {};
	//	int
	template<> struct is_integral_base<int> : true_type {};
	template<> struct is_integral_base<const int> : true_type {};
	template<> struct is_integral_base<volatile int> : true_type {};
	template<> struct is_integral_base<unsigned int> : true_type {};
	template<> struct is_integral_base<const unsigned int> : true_type {};
	template<> struct is_integral_base<volatile unsigned int> : true_type {};
	//	long
	template<> struct is_integral_base<long> : true_type {};
	template<> struct is_integral_base<const long> : true_type {};
	template<> struct is_integral_base<volatile long> : true_type {};
	template<> struct is_integral_base<unsigned long> : true_type {};
	template<> struct is_integral_base<const unsigned long> : true_type {};
	template<> struct is_integral_base<volatile unsigned long> : true_type {};
	//	long long
	template<> struct is_integral_base<long long> : true_type {};
	template<> struct is_integral_base<const long long> : true_type {};
	template<> struct is_integral_base<volatile long long> : true_type {};
	template<> struct is_integral_base<unsigned long long> : true_type {};
	template<> struct is_integral_base<const unsigned long long> : true_type {};
	template<> struct is_integral_base<volatile unsigned long long> : true_type {};

	template <class T>
	struct is_integral : is_integral_base<T> {};

}

#endif