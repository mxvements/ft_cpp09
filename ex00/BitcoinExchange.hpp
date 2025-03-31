/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:18:16 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/31 20:30:24 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <algorithm>
# include <ctime>
# include <iomanip>
# include <utility>

/**
 * program:
 * 	- take a file as an argument -> second database
 *  - first database -> csv file
 *  - each line follows the format -> date | value (output)
 *  - valid date -> Year-Month-Day
 *  - valid value -> float or a positive int, [0..1000]
 * 
 * - must use at least one container in your code
 * - handle possible errors with an appropiate error message
 * 
 * - std::pair is a container in the C++ Standard Library that holds two values of potentially different types.
 * - std::map is an ordered associative container that stores key-value pairs. It is implemented as a balanced binary 
 * search tree (usually a Red-Black Tree), making operations logarithmic in complexity (O(log n)).
 */
template <typename T>
class BitcoinExchange {
	private:
		//file
		std::set<struct tm, float>	_db; //csv
		//convert
		
	public:
		~BitcoinExchange(void);
		BitcoinExchange(); //parses db upon construction
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);
		
		//member functions:
		//loadCsv + utility functions
		//loadInput
		//printExchange
		//extractPair
		
		//member exceptions:
		class BadValueException : public std::exception {
			public:
				const char *what() const throw();
		} ;
		class BadDateException : public std::exception {
			public:
				const char *what() const throw();
		} ;
		class BadArgumentsException : public std::exception {
			public:
				const char *what() const throw();
		} ;
		class BadDatabaseException : public std::exception {
			public:
				const char *what() const throw();
		} ;
} ;

/* Exceptions ----------------------------------------------------------------*/

template<typename T>
const char *BitcoinExchange<T>::BadValueException::what() const throw(){
	return "Bad value";
}
template<typename T>
const char *BitcoinExchange<T>::BadDateException::what() const throw(){
	return "Bad date";
}
template<typename T>
const char *BitcoinExchange<T>::BadArgumentsException::what() const throw(){
	return "Bad arguments";
}
template<typename T>
const char *BitcoinExchange<T>::BadDatabaseException::what() const throw(){
	return "Bad database";
}

/* Exceptions ----------------------------------------------------------------*/


#endif