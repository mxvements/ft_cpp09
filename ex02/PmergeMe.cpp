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
/* orthodox canonical form  */

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(std::vector<std::string> &input)
{
	for (std::vector<std::string>::const_iterator i = input.end() - 1; i >= input.begin(); i--)
	{
		this->_vector.push_back(atoi((*i).c_str()));
		this->_deque.push_back(atoi((*i).c_str()));
	}
}

PmergeMe::PmergeMe(const PmergeMe &src)
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
		std::cout << "vector : " << *i << std::endl;
	}
}

void PmergeMe::printDeque(const std::deque<int> &input)
{
	for (std::deque<int>::const_iterator i = input.begin(); i < input.end(); i++)
	{
		std::cout << "deque : " << *i << std::endl;
	}
}

/* ************************************************************************** */

/**
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

	int leftover;
	if (isOdd)
		leftover = input[size - 1];

	// this->printVector(larger);
	// std::cout << std::endl;

	// sort the pairs considering the first element (so the pairs are sorted)
	std::vector<int> sorted = mergeInsertSortVector(larger);

	for (std::vector<int>::iterator i = smaller.begin(); i < smaller.end(); i++)
		binaryInsertVector(sorted, *i);

	if (isOdd)
		binaryInsertVector(sorted, leftover);

	std::cout << "rslt : " << std::endl;
	this->printVector(sorted); //larger is on the stack!
	return (input);
}