/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:51:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/19 20:19:48 by luciama2         ###   ########.fr       */
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
	const int input_size = input.size() - 1;

	if (charCheck(input[input_size]) != OP)
		throw RPN::InvalidCharException();
	for (int i = input_size; i >= 0; i--)
	{
		type = charCheck(input[i]);
		if ((i % 2 != 0) && type == SP)
			continue;
		else if (i % 2 == 0 && (type == OP || type == NBR))
			this->_stack.push(input[i]);
		else
			throw RPN::InvalidCharException();
	}

	while (this->_stack.size() > 0)
	{
		const char element = this->_stack.top();
		type = charCheck(element);
		if (type == NBR)
			this->_calc_stack.push(element - '0');
		else if (type == OP)
		{
			if (this->_calc_stack.size() != 2)
				throw RPN::BadStackException();
			const int b = this->_calc_stack.top();
			this->_calc_stack.pop();
			const int a = this->_calc_stack.top();
			this->_calc_stack.pop();
			int rslt = calculator(a, b, element);
			this->_calc_stack.push((rslt));
		}
		this->_stack.pop();
	}
}

std::stack<int> RPN::getCalcStack(void)
{
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
	return "Error :  wrong stack, check nbr/op order";
}

/* ************************************************************************** */

Type RPN::charCheck(const char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (OP);
	if (std::isdigit(static_cast<int>(c)))
		return (NBR);
	if (std::isspace(c))
		return (SP);
	return (ERROR);
}
int RPN::calculator(int a, int b, char op)
{
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
