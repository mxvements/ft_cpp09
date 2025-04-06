/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:46:37 by lucia             #+#    #+#             */
/*   Updated: 2025/04/06 19:13:27 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
		throw RPN::InvalidArgumentsException();
	
	try {
		RPN rpn(argv[1]);
		std::cout << "Result : " << rpn.getCalcStack().top() << std::endl;
	} catch (const std::exception &e){
		std::cerr << e.what() << std::endl;;
		std::cerr << 0 << std::endl;
	}
	
	return (0);
}
