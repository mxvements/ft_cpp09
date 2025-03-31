/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:36:53 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/31 19:49:07 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
# define SWAP_HPP

# include <iostream>

template<typename T>
void	swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}


#endif