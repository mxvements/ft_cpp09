/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/13 23:19:20 by lucia            ###   ########.fr       */
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
		this->_vector.push_back(atoi((*i).c_str()));
		this->_deque.push_back(atoi((*i).c_str()));
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

std::vector<int> &PmergeMe::getVector(void)
{
	return this->_vector;
}

std::deque<int> &PmergeMe::getDeque(void)
{
	return this->_deque;
}

void PmergeMe::printVector(const std::vector<int> &input)
{
	for (std::vector<int>::const_iterator i = input.begin(); i < input.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int> &input)
{
	for (std::deque<int>::const_iterator i = input.begin(); i < input.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
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
void PmergeMe::binaryInsertVector(std::vector<int> &vector, int val)
{
	std::vector<int>::iterator lower = std::lower_bound(vector.begin(), vector.end(), val);
	vector.insert(lower, val);
}

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

	// make random pairs of two and sort them in increasing order
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
		binaryInsertVector(input, *i);

	if (isOdd)
		binaryInsertVector(input, leftover);

	this->_vectorBenchmark.setEnd(std::clock());
	return (input);
}
