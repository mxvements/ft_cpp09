/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:25:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/19 20:38:01 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

/**
 * ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
 */
int main(int argc, char **argv)
{	
	//argument error
	std::vector<std::string> input(argv + 1, argv + argc);
	PmergeMe pm(input);


	std::cout << "Before : vector : ";
	pm.print<std::vector<int> >(pm.getVector());
	std::cout << std::endl;
	
	std::vector<int> sortedVector = pm.mergeInsertSortVector(pm.getVector());
	
	std::cout << "After : vector : ";
	pm.print<std::vector<int> >(sortedVector);
	std::cout << std::endl;


	std::cout << "Before : deque : ";
	pm.print<std::deque<int> >(pm.getDeque());
	std::cout << std::endl;
	
	std::deque<int> sortedDeque = pm.mergeInsertSortDeque(pm.getDeque());
	
	std::cout << "After : deque : ";
	pm.print<std::deque<int> >(sortedDeque);
	std::cout << std::endl;
	
	std::cout << pm.getVectorBenchmark();
	std::cout << pm.getDequeBenchmark();
	return (0);
}
