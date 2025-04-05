/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:51:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/05 19:38:25 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(void){}

RPN::RPN(const RPN &src){
	*this = src;
}

RPN &RPN::operator=(const RPN &src){
	if (this != &src){
		this->_stack = src._stack;
		this->_calc_stack = src._calc_stack;
	}
	return (*this);
}

RPN::RPN(std::string input){
	
	for (int i = input.size() - 1; i >= 0; i--){
		
		
		if ((i % 2 != 0) && (std::isspace(static_cast<unsigned char>(input[i])) == 0))
		{
			std::cout << "exception : " << input[0] << std::endl;
			std::cout << std::endl;
			throw RPN::InvalidCharException();
		}
		else if (i % 2 == 0 
			&& (std::isdigit(static_cast<int>(input[i])) || this->ismathop(input[i])))
		{
			this->_stack.push(input[i]);
			std::cout << "push : " << input[i] << std::endl;
			std::cout << std::endl;		
		}
	}
}

/* ************************************************************************** */

const char *RPN::InvalidCharException::what() const throw() {
	return "Error :  bad char";
}

const char *RPN::InvalidArguments::what() const throw() {
	return "Error :  invalid arguments";
}

/* ************************************************************************** */

bool RPN::ismathop(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/' )
		return (true);
	return (false);
}

/* ************************************************************************** */

