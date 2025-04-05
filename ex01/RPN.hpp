/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:51:23 by lucia             #+#    #+#             */
/*   Updated: 2025/04/05 19:28:17 by lucia            ###   ########.fr       */
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

class RPN {
	private:
		std::stack<char> _stack;
		std::stack<char> _calc_stack;

		bool ismathop(char c);
		
	public:
		~RPN(void);
		RPN(std::string intpu);
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);

		//member exceptions
		class InvalidCharException : public std::exception {
			public:
				const char *what() const throw();
		} ;
		class InvalidArguments : public std::exception {
			public:
				const char *what() const throw();
		} ;
		
} ;

#endif