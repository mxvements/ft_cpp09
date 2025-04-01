/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:18:47 by luciama2          #+#    #+#             */
/*   Updated: 2025/04/01 20:08:54 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * Use of associative contianers
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		throw BitcoinExchange::BadArgumentsException();

	BitcoinExchange bc("./cpp_09/data.csv");
	bc.print();
	bc.loadInput(argv[1]);
	
	return (0);
}