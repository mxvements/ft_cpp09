/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:19:00 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/01 20:23:40 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* Private functs ------------------------------------------------------------*/

double BitcoinExchange::convert_double(std::string input)
{
	char *end_ptr;
	std::string end_str;
	double result = std::strtod(input.c_str(), &end_ptr);
	end_str = end_ptr;
	if (end_str.length() > 0 || errno)
		return (-1);
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
		this->_db.insert(std::pair<time_t, float>(d, v));
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

const char *BitcoinExchange::BadValueException::what() const throw()
{
	return "Error : Bad value";
}
const char *BitcoinExchange::BadDateException::what() const throw()
{
	return "Error : Bad date";
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

void BitcoinExchange::print(void) const
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
	int header = 0;
	while (std::getline(inputFile, line))
	{
		if (header++ == 0)
		{
			if (line != "date | value")
				throw BitcoinExchange::BadHeaderException();
			continue;
		}
		std::string date = line.substr(0, line.find_first_of('|'));
		std::string value = line.substr(line.find_first_of('|') + 1, line.size());
		time_t d;
		float v;
		try {
			d = this->convert<time_t>(date, DB_DATE);
			v = this->convert<float>(value, DB_VALUE);
		} catch (const std::exception &e){
			std::cerr << e.what() << std::endl;
		}
		std::cout << line << " " << d << " " << v << std::endl;
	}
	
	inputFile.close();
}
