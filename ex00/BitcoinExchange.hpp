/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:18:16 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/01 20:16:04 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <map>
# include <string>
# include <utility>

enum	Type
{
	DB_DATE,
	DB_VALUE
};

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
 *
	- std::pair is a container in the C++ Standard Library that holds two values of potentially different types.
 *
	- std::map is an ordered associative container that stores key-value pairs. It is implemented as a balanced binary
 * search tree (usually a Red-Black Tree),
	making operations logarithmic in complexity (O(log n)).
 */
class BitcoinExchange
{
	private:
		const std::string _dbPath;
		std::map<time_t, float> _db; // csvc++ formatter
		
		void loadDB(void);
	
		template <typename T> T convert(std::string input, Type t);
		double convert_double(std::string input);

	public:
		~BitcoinExchange(void);
		BitcoinExchange(std::string dbPath); // parses db upon construction
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);
	
		// member functions:
		void print(void) const;
		void loadInput(std::string input);
		// extractPair
	
		// member exceptions:
		class BadValueException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class BadDateException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class BadArgumentsException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class BadFileException : public std::exception
		{
			public:
				const char *what() const throw(); //validate db and input files
		};
		class BadHeaderException : public std::exception 
		{
			public:
				const char *what() const throw(); //validate header on input file only
		} ;
} ;

/* Template functs -----------------------------------------------------------*/

template <typename T>
T BitcoinExchange::convert(std::string input, Type t)
{
	switch (t)
	{
		case DB_DATE:
		{
			struct tm tm;
			tm.tm_year = convert_double(input.substr(0, 4));
			if (tm.tm_year < 0)
				throw BitcoinExchange::BadDateException();
			tm.tm_mon = convert_double(input.substr(5, 2));
			if (tm.tm_mon < 0)
				throw BitcoinExchange::BadDateException();
			tm.tm_mday = convert_double(input.substr(8, 2));
			if (tm.tm_mday < 0)
				throw BitcoinExchange::BadDateException();
			return (std::mktime(&tm));
		}
		case DB_VALUE:
		{
			float val = static_cast<float>(convert_double(input));
			if (val < 0.0f) 
				throw BitcoinExchange::BadValueException();
			return (val);
		}
	}
}

#endif