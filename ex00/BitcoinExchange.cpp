/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:19:00 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/02 20:22:14 by luciama2         ###   ########.fr       */
/*   Updated: 2025/04/02 20:22:14 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Private functs ------------------------------------------------------------*/

double BitcoinExchange::convert_double(std::string input)
{
	char *end_ptr;
	std::string end_str;
	errno = 0;
	long double result = std::strtold(input.c_str(), &end_ptr);
	end_str = end_ptr;
	if (end_str.length() > 0 || errno)
		return (-1);
	if (result < 0)
		throw BitcoinExchange::NegativeNumberException();
	return (result);
}

void BitcoinExchange::loadDB(void)
{
	std::ifstream dbFile(this->_dbPath.c_str());
	if (!dbFile)
		throw BitcoinExchange::BadFileException();

	std::string line;
	int header = 0;
	while (std::getline(dbFile, line))
	{
		if (header++ == 0)
			continue;
		std::string date = line.substr(0, line.find_first_of(','));
		std::string value = line.substr(line.find_first_of(',') + 1, line.size());
		time_t d = this->convert<time_t>(date, DB_DATE);
		float v = this->convert<float>(value, DB_VALUE);
		
		std::pair<time_t, float> pair = std::pair<time_t, float>(d, v);
		this->_db.insert(pair);
	}
	dbFile.close();
}

/* Base functs ---------------------------------------------------------------*/

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string dbPath) : _dbPath(dbPath)
{
	this->loadDB();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _dbPath(src._dbPath) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src) { }
	return (*this);
}

/* Exceptions ----------------------------------------------------------------*/

const char *BitcoinExchange::NegativeNumberException::what() const throw()
{
	return "Error : Bad value : Not a positive number";
}
const char *BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "Error : Bad value : Too large a number";
}
const char *BitcoinExchange::BadDateException::what() const throw()
{
	return "Error : Bad  date";
}
const char *BitcoinExchange::BadArgumentsException::what() const throw()
{
	return "Error : Bad arguments";
}
const char *BitcoinExchange::BadFileException::what() const throw()
{
	return "Error : Bad file";
}
const char *BitcoinExchange::BadHeaderException::what() const throw()
{
	return "Error: Bad header";
}

/* Member functs -------------------------------------------------------------*/

void BitcoinExchange::printDB(void) const
{
	for (std::map<time_t, float>::const_iterator it = this->_db.begin(); it != this->_db.end(); it++)
		std::cout << "[ " << it->first << " : " << it->second << " ]" << std::endl;
}

void BitcoinExchange::loadInput(std::string input)
{
	std::ifstream inputFile(input.c_str());
	if (!inputFile)
		throw BitcoinExchange::BadFileException();
		
	std::string line;
	if (std::getline(inputFile, line) && line != "date | value")
		throw BitcoinExchange::BadHeaderException();
	
	while (std::getline(inputFile, line))
	{
		try {
			std::string date = line.substr(0, line.find_first_of('|'));
			std::string value = line.substr(line.find_first_of('|') + 1, line.size());
			time_t  d = this->convert<time_t>(date, DB_DATE);
			float v = this->convert<float>(value, IN_VALUE) ;

			std::pair<time_t, float> pair = std::pair<time_t, float>(d, v);
			std::map<time_t, float>::iterator db_element = this->_db.lower_bound(pair.first);

			struct tm *tm = std::gmtime(&(pair.first));
			float exchange = pair.second * db_element->second;

			std::cout 	<< tm->tm_year << "-" << tm->tm_mon << "-" << tm->tm_mday 
						<< " => " << pair.second 
						<< " => " << exchange
						<< std::endl;
		} catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
	}
	
	inputFile.close();
}
