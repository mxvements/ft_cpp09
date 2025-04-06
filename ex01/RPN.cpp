/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:51:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/06 19:13:52 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(void) {}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN &RPN::operator=(const RPN &src)
{
	if (this != &src)
	{
		this->_stack = src._stack;
		this->_calc_stack = src._calc_stack;
	}
	return (*this);
}

RPN::RPN(std::string input)
{

	Type type;

	for (int i = input.size() - 1; i >= 0; i--)
	{
		type = charCheck(input[i]);
		if ((i % 2 != 0) && (std::isspace(static_cast<unsigned char>(input[i])) == 0))
			throw RPN::InvalidCharException();
		else if (i % 2 == 0 && type != ERROR)
			this->_stack.push(input[i]);
	}

	while (this->_stack.size() > 0)
	{
		const char element = this->_stack.top();
		type = charCheck(element);
		if (type == NBR)
			this->_calc_stack.push(element - '0');
		if (type == OP){
			const int b = this->_calc_stack.top();
			this->_calc_stack.pop();
			const int a = this->_calc_stack.top();
			this->_calc_stack.pop();
			if (this->_calc_stack.size() > 0)
				throw RPN::BadStackException();
			int rslt = calculator(a, b, element);
			this->_calc_stack.push((rslt));
		}
		this->_stack.pop();
	}
}

std::stack<int> RPN::getCalcStack(void){
	return this->_calc_stack;
}

/* ************************************************************************** */

const char *RPN::InvalidCharException::what() const throw()
{
	return "Error :  bad char";
}

const char *RPN::InvalidArgumentsException::what() const throw()
{
	return "Error :  invalid arguments";
}

const char *RPN::BadStackException::what() const throw()
{
	return "Error :  wrong stack, check order";
}

/* ************************************************************************** */

Type RPN::charCheck(const char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (OP);
	if (std::isdigit(static_cast<int>(c)))
		return (NBR);
	return (ERROR);
}
int RPN::calculator(int a, int b, char op){
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			return (a / b);
		default:
			throw RPN::InvalidCharException();
	}
	return (0);
}

