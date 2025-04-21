/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Benchmark.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:41:11 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/21 18:55:07 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Benchmark.hpp"

/* ************************************************************************** */
/* BENCHMARK orthodox canonical form  */
Benchmark::~Benchmark(void) {}

Benchmark::Benchmark(std::string type) : _type(type), _comparisonCount(0), _start(0), _end(0) {}

Benchmark::Benchmark(const Benchmark &src)
{
	*this = src;
}

Benchmark &Benchmark::operator=(const Benchmark &src)
{
	if (this != &src)
	{
		this->_start = src._start;
		this->_end = src._end;
	}
	return (*this);
}

/* ************************************************************************** */
/* BENCHMARK public methods  */

// setters
void Benchmark::setStart(std::clock_t start)
{
	if (this->_start != 0)
		return;
	this->_start = start;
}
void Benchmark::setEnd(std::clock_t end) { this->_end = end; }
void Benchmark::setSize(int size) { this->_size = size; }
void Benchmark::setComparisonCount(int comparisonCount) { this->_comparisonCount = comparisonCount; }

// getters
const std::clock_t &Benchmark::getStart(void) const { return this->_start; }
const std::clock_t &Benchmark::getEnd(void) const { return this->_end; }
const int &Benchmark::getSize(void) const { return this->_size; }
const int &Benchmark::getComparisonCount(void) const {return this->_comparisonCount; }
const std::string &Benchmark::getType(void) const { return this->_type; }

void Benchmark::addComparisonCount(void) { this->_comparisonCount++;}

// os overload
std::ostream &operator<<(std::ostream &os, const Benchmark &b)
{
	double microseconds = 1.0e6 * (b.getEnd() - b.getStart()) / CLOCKS_PER_SEC;
	return (os
			<< "Time to process a range of "
			<< b.getSize()
            << " elements with " 
            << b.getComparisonCount() 
            << " comparisons with std::"
			<< b.getType()
			<< " : "
			<< std::fixed << std::setprecision(2) << microseconds
			<< " us" << std::endl);
}
