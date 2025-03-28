/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Min.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:28:41 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/28 13:38:49 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIN_HPP
# define MIN_HPP

# include <iostream>

template<typename T>
T	const &min(T const &x, T const &y)
{
	return (x < y ? x : y);
}


#endif