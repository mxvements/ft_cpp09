/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Benchmark.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:39:58 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/21 18:45:38 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_HPP
#define BENCHMARK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <climits>
#include <cctype>
#include <ctime>

class Benchmark
{
private:
	const std::string _type;
	int _size;
	int	_comparisonCount;
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
    void setComparisonCount(int comparisonCount);
    
	const std::clock_t &getStart(void) const;
	const std::clock_t &getEnd(void) const;
	const int &getSize(void) const;
    const int &getComparisonCount(void) const;
	const std::string &getType(void) const;
};
std::ostream &operator<<(std::ostream &os, const Benchmark &b);

#endif