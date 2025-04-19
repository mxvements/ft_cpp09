/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:23 by lucia             #+#    #+#             */
/*   Updated: 2025/04/19 20:26:29 by luciama2         ###   ########.fr       */
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

/**
 * use of STL in the project, none of the containers should be used twice
 * bitcoin exchange -> associative container: Map
 * rpn -> stacks (int and string)
 * merge insert -> vector and deque (2 containers for comparison)
 */

class Benchmark
{
private:
	const std::string _type;
	int _size;
	std::clock_t _start;
	std::clock_t _end;

public:
	~Benchmark(void);
	Benchmark(std::string type);
	Benchmark(const Benchmark &src);
	Benchmark &operator=(const Benchmark &src);

	void setStart(std::clock_t start);
	void setEnd(std::clock_t end);
	void setSize(int size);
	const std::clock_t &getStart(void) const;
	const std::clock_t &getEnd(void) const;
	const int &getSize(void) const;
	const std::string &getType(void) const;
};
std::ostream &operator<<(std::ostream &os, const Benchmark &b);

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		Benchmark _vectorBenchmark;
		Benchmark _dequeBenchmark;

		template <typename Container>
		void binaryInsert(Container &c, int val)
		{
			typename Container::iterator lower = std::lower_bound(c.begin(), c.end(), val);
			c.insert(lower, val);
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