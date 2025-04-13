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

std::vector<int> &PmergeMe::swapVector(std::vector<int> &v)
{
	int tmp;
	if (*(v.begin()) > *(v.end() - 1))
	{
		tmp = *(v.begin());
		*v.begin() = *(v.end() - 1);
		*(v.end() - 1) = tmp;
	}
	return (v);
}

std::vector<int> PmergeMe::mergeVector(const std::vector<int> &v1, const std::vector<int> &v2)
{
	std::vector<int> rslt;
	std::vector<int>::const_iterator i1 = v1.begin();
	std::vector<int>::const_iterator i2 = v2.begin();

	while (i1 != v1.end() && i2 != v2.end())
	{
		if (*i1 <= *i2)
		{
			rslt.push_back(*i1);
			++i1;
		}
		if (*i2 < *i1)
		{
			rslt.push_back(*i2);
			++i2;
		}
	}
	while (i1 != v1.end() && i2 == v2.end())
	{
		rslt.push_back(*i1);
		++i1;
	}
	while (i2 != v2.end() && i1 == v1.end())
	{
		rslt.push_back(*i2);
		++i2;
	}
	return (rslt);
}

std::vector<int> &PmergeMe::mergeInsertSortVector(std::vector<int> &input)
{
	size_t size = input.size();
	if (size > 2)
	{
		//todo: change to use of iterators/references to avoid copying the array
		//will need to change the call on this function since the recursivity is here
		std::vector<int> lhs(input.begin(), input.end() - (size / 2));
		std::vector<int> rhs(input.end() - (size / 2), input.end());
		mergeInsertSortVector(lhs);
		mergeInsertSortVector(rhs);
		input = mergeVector(lhs, rhs);
	}
	else if (size == 2)
		this->swapVector(input);
	
	return (input);
}