/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/21 19:01:35 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



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

std::vector<int> &PmergeMe::getVector(void)
{
	return this->_vector;
}

std::deque<int> &PmergeMe::getDeque(void)
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

/**
 * Ford Johnson optimization:
 * - Uses a Tournament Tree or Pairing tree structure to help determine the optimal
 * insertion path for each smaller element
 * - Optimal insertion order: it calculates the optimal order in which to insert elements
 * to minimize comparisons.
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
		this->_vectorBenchmark.addComparisonCount();
	}

	if (isOdd)
		leftover = input[size - 1];

	input = mergeInsertSortVector(larger);

	for (std::vector<int>::iterator i = smaller.begin(); i < smaller.end(); i++)
		binaryInsert<std::vector<int> >(input, *i, this->_vectorBenchmark);

	if (isOdd)
		binaryInsert<std::vector<int> >(input, leftover, this->_vectorBenchmark);

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
		this->_dequeBenchmark.addComparisonCount();
		std::advance(i, 2);
	}

	if (isOdd)
		leftover = input[size - 1];

	input = mergeInsertSortDeque(larger);

	for (std::deque<int>::iterator i = smaller.begin(); i < smaller.end(); i++)
		binaryInsert<std::deque<int> >(input, *i, this->_dequeBenchmark);

	if (isOdd)
		binaryInsert<std::deque<int> >(input, leftover, this->_dequeBenchmark);

	this->_dequeBenchmark.setEnd(std::clock());
	return (input);
}