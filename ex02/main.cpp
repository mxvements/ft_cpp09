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

int main(int argc, char **argv)
{	
	//argument error
	std::vector<std::string> input(argv + 1, argv + argc);
	PmergeMe pm(input);
	
	// pm.printVector(pm.getVector());
	// std::cout << std::endl;
	// pm.printDeque(pm.getDeque());
	// std::cout << std::endl;

	std::vector<int> sorted = pm.mergeInsertSortVector(pm.getVector());
	// pm.printVector(sorted);
	return (0);
}
