/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:51:23 by lucia             #+#    #+#             */
/*   Updated: 2025/04/06 19:08:16 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <climits>
# include <utility>
# include <algorithm>
# include <stack>
# include <cctype>

enum Type {
	NBR,
	OP,
	ERROR
};

class RPN {
	private:
		std::stack<char> _stack;
		std::stack<int> _calc_stack;

		Type charCheck(const char c);
		int calculator(const int a, const int b, const char op);
		
	public:
		~RPN(void);
		RPN(std::string intpu);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		std::stack<int> getCalcStack(void);
		
		//member exceptions
		class InvalidCharException : public std::exception {
			public:
				const char *what() const throw();
		} ;
		class InvalidArgumentsException : public std::exception {
			public:
				const char *what() const throw();
		} ;

		class BadStackException : public std::exception {
			public:
				const char *what() const throw();
		} ;
		
} ;

#endif