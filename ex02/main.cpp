/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:25:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/13 23:13:05 by lucia            ###   ########.fr       */
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

	std::vector<int> sorted = pm.mergeInsertSortVector(pm.getVector());

	std::cout << "Before: ";
	pm.printVector(pm.getVector());
	std::cout << std::endl;
	std::cout << "After: ";
	pm.printVector(sorted);
	std::cout << std::endl;
	std::cout << pm.getVectorBenchmark() << std::endl;
	return (0);
}
