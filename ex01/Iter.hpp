/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:11:44 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/28 14:53:36 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include "Colors.hpp"

template<typename T>
void	iter(T const a[], size_t const &len, void (f)(const T &))
{
	for (size_t i = 0; i < len; i++)
	{
		f(a[i]);
	}	
}
//need to to another template for the function ptr
template<typename T>
void print_element_red(const T &el)
{
	std::cout << FG_LIGHT_RED << el << RESET << " ";
}

#endif