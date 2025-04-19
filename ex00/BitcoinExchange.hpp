/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:18:16 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/19 18:56:04 by luciama2         ###   ########.fr       */
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
# include <cmath>
# include <climits>
# include "Colors.hpp"

/* Structs -------------------------------------------------------------------*/

enum	Type
{
	DB_DATE,
	DB_VALUE,
	IN_VALUE
};

class BitcoinExchange
{
	private:
		const std::string 		_dbPath;
		std::map<time_t, float> _db;

		void loadDB(void);
	
		template <typename T> T convert(std::string input, Type t);
		double convert_double(std::string input);

	public:
		~BitcoinExchange(void);
		BitcoinExchange(std::string dbPath); // parses db upon construction
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);
	
		// member functions:
		void loadInput(std::string input);
		void printDB(void) const;
	
		// member exceptions:
		class NegativeNumberException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class TooLargeNumberException : public std::exception
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
				const char *what() const throw();
		};
		class BadHeaderException : public std::exception 
		{
			public:
				const char *what() const throw();
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
			tm.tm_year = convert_double(input.substr(0, 4)) - 1900;
			if (tm.tm_year < 0)
				throw BitcoinExchange::BadDateException();
			tm.tm_mon = convert_double(input.substr(5, 2)) - 1;
			if (tm.tm_mon < 0 || tm.tm_mon > 12)
				throw BitcoinExchange::BadDateException();
			tm.tm_mday = convert_double(input.substr(8, 2));
			if (tm.tm_mday < 0 || tm.tm_mday > 31)
				throw BitcoinExchange::BadDateException();
			tm.tm_hour = 0;
			tm.tm_min = 0;
			tm.tm_sec = 0;
			tm.tm_isdst = -1;
			time_t t = std::mktime(&tm);
			return (t);
		}
		case DB_VALUE:
		{
			double val = convert_double(input);
			if (val > INT_MAX)
				throw BitcoinExchange::TooLargeNumberException();
			if (static_cast<int>(val) < 0)
				throw BitcoinExchange::NegativeNumberException();
			return (static_cast<float>(val));
		}
		case IN_VALUE:
		{
			double val = convert_double(input);
			if (val > 1000)
				throw BitcoinExchange::TooLargeNumberException();
			if (static_cast<int>(val) < 0)
				throw BitcoinExchange::NegativeNumberException();
			return (static_cast<float>(val));
		}
	}
}

#endif