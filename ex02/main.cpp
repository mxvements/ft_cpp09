/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:25:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/06 20:32:50 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int main(int argc, char **argv)
{	
	std::vector<std::string> input(argv + 1, argv + argc);
	PmergeMe pm(input);
	pm.printVector();
	std::cout << std::endl;
	pm.printDeque();
	return (0);
}
