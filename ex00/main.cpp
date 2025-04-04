/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:18:47 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/02 20:08:51 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * program:
 * 	- take a file as an argument -> second database
 *  - first database -> csv file
 *  - each line follows the format -> date | value (output)
 *  - valid date -> Year-Month-Day
 *  - valid value -> float or a positive int, [0..1000]
 *
 * - must use at least one container in your code
 * - handle possible errors with an appropiate error message
 *
 *
	- std::pair is a container in the C++ Standard Library that holds two values of potentially different types.
 *
	- std::map is an ordered associative container that stores key-value pairs. It is implemented as a balanced binary
 * search tree (usually a Red-Black Tree),
	making operations logarithmic in complexity (O(log n)).
 */
int main(int argc, char **argv)
{
	try {
		if (argc != 2)
			throw BitcoinExchange::BadArgumentsException();

		BitcoinExchange bc("./cpp_09/data.csv");
		// bc.printDB();
		bc.loadInput(argv[1]);
	} catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}