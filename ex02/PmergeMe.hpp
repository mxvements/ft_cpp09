/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:23 by lucia             #+#    #+#             */
/*   Updated: 2025/04/21 20:46:59 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <utility>
#include <algorithm>
#include <deque>
#include <vector>
#include <cctype>
#include <ctime>
#include "Benchmark.hpp"

/**
 * use of STL in the project, none of the containers should be used twice
 * bitcoin exchange -> associative container: Map
 * rpn -> stacks (int and string)
 * merge insert -> vector and deque (2 containers for comparison)
 */

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		Benchmark _vectorBenchmark;
		Benchmark _dequeBenchmark;

		template <typename Container>
		void binaryInsert(Container &c, int val, Benchmark &b)
		{
			typename Container::iterator first = c.begin();
			typename Container::iterator last = c.end();
			
			while (first < last)
			{
				typename Container::iterator mid = first + (last - first) / 2;
				b.addComparisons();
				if (val < *mid)
					last = mid;
				else
					first = mid + 1;
			}
			c.insert(first, val);
		}
	
	public:
		~PmergeMe(void);
		PmergeMe(std::vector<std::string> &input);
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
	
		std::vector<int> &getVector(void);
		std::deque<int> &getDeque(void);
		const Benchmark &getVectorBenchmark(void) const;
		const Benchmark &getDequeBenchmark(void) const;
	
		// sort
		std::vector<int> &mergeInsertSortVector(std::vector<int> &input);
		std::deque<int> &mergeInsertSortDeque(std::deque<int> &input);

		std::vector<int> &fordJohnsonSortVector(std::vector<int> &input);
		std::deque<int> &fordJohnsonSortDeque(std::deque<int> &input);
	
		template <typename Container>
		void print(const Container &input) const
		{
			for (typename Container::const_iterator i = input.begin(); i < input.end(); i++)
			{
				std::cout << *i << " ";
			}
			std::cout << std::endl;
		};
};

#endif