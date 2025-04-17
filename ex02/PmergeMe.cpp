/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/17 21:02:30 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* BENCHMARK orthodox canonical form  */
Benchmark::~Benchmark(void) {}

Benchmark::Benchmark(std::string type) : _type(type), _start(0), _end(0) {}

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

void Benchmark::setStart(std::clock_t start)
{
	if (this->_start != 0)
		return;
	this->_start = start;
}

void Benchmark::setEnd(std::clock_t end) { this->_end = end; }
void Benchmark::setSize(int size) { this->_size = size; }

const std::clock_t &Benchmark::getStart(void) const { return this->_start; }
const std::clock_t &Benchmark::getEnd(void) const { return this->_end; }
const std::string &Benchmark::getType(void) const { return this->_type; }
const int &Benchmark::getSize(void) const { return this->_size; }

std::ostream &operator<<(std::ostream &os, const Benchmark &b)
{
	double microseconds = 1.0e6 * (b.getEnd() - b.getStart()) / CLOCKS_PER_SEC;
	return (os
			<< "Time to process a range of "
			<< b.getSize()
			<< " elements with std::"
			<< b.getType()
			<< " : "
			<< std::fixed << std::setprecision(2) << microseconds
			<< " us" << std::endl);
}

/* ************************************************************************** */
/* PMERGEME orthodox canonical form  */

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(std::vector<std::string> &input) : _vectorBenchmark("vector"), _dequeBenchmark("deque")
{
	for (std::vector<std::string>::const_iterator i = input.begin(); i != input.end(); i++)
	{	
		std::string value = *i;
		this->_vector.push_back(atoi(value.c_str()));
		this->_deque.push_back(atoi(value.c_str()));
	}
	this->_vectorBenchmark.setSize(this->_vector.size());
	this->_dequeBenchmark.setSize(this->_deque.size());
}

PmergeMe::PmergeMe(const PmergeMe &src) : _vectorBenchmark("vector"), _dequeBenchmark("deque")
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_deque = src._deque;
	}
	return (*this);
}

/* ************************************************************************** */
/* PMERGEME public methods  */

const std::vector<int> &PmergeMe::getVector(void) const 
{
	return this->_vector;
}

const std::deque<int> &PmergeMe::getDeque(void) const
{
	return this->_deque;
}

const Benchmark &PmergeMe::getVectorBenchmark(void) const
{
	return this->_vectorBenchmark;
}

const Benchmark &PmergeMe::getDequeBenchmark(void) const
{
	return this->_dequeBenchmark;
}

/* ************************************************************************** */

/**
 * Normal merge insert sorting method:
 * 1 - Divide recursevily until the length of the array s 2
 * 2 - sort those array of len 2
 * 3 - merge (2 sorted arrays into 2 sorted arrays, is 'two finger' function)
 */

std::vector<int> &PmergeMe::mergeInsertSortVector(std::vector<int> &input)
{
	std::vector<int> smaller;
	std::vector<int> larger;
	int leftover;

	this->_vectorBenchmark.setStart(std::clock());
	int size = input.size();
	bool isOdd = size % 2 != 0;

	if (size < 2)
		return input;

	for (std::vector<int>::iterator i = input.begin(); i < input.end() - 1; i += 2)
	{
		int lhs = *i;
		int rhs = *(i + 1);
		if (lhs <= rhs)
		{
			smaller.push_back(lhs);
			larger.push_back(rhs);
		}
		else
		{
			smaller.push_back(rhs);
			larger.push_back(lhs);
		}
	}

	if (isOdd)
		leftover = input[size - 1];

	input = mergeInsertSortVector(larger);

	for (std::vector<int>::iterator i = smaller.begin(); i < smaller.end(); i++)
		binaryInsert<std::vector<int> >(input, *i);

	if (isOdd)
		binaryInsert<std::vector<int> >(input, leftover);

	this->_vectorBenchmark.setEnd(std::clock());
	return (input);
}

std::deque<int> &PmergeMe::mergeInsertSortDeque(std::deque<int> &input)
{
	std::deque<int> smaller;
	std::deque<int> larger;
	int leftover;

	this->_dequeBenchmark.setStart(std::clock());
	int size = input.size();
	bool isOdd = size % 2 != 0;

	if (size < 2)
		return input;

	for (std::deque<int>::iterator i = input.begin(); i != input.end(); )
	{
		std::deque<int>::iterator next = i ;
		std::advance(next, 1);
		
		if (next == input.end())
			break ;
		
		int lhs = *i;
		int rhs = *next;
		if (lhs <= rhs)
		{
			smaller.push_back(lhs);
			larger.push_back(rhs);
		}
		else
		{
			smaller.push_back(rhs);
			larger.push_back(lhs);
		}
		std::advance(i, 2);
	}

	if (isOdd)
		leftover = input[size - 1];

	input = mergeInsertSortDeque(larger);

	for (std::deque<int>::iterator i = smaller.begin(); i < smaller.end(); i++)
		binaryInsert<std::deque<int> >(input, *i);

	if (isOdd)
		binaryInsert<std::deque<int> >(input, leftover);

	this->_dequeBenchmark.setEnd(std::clock());
	return (input);
}