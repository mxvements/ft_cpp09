/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Max.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:11:57 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/28 13:38:56 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_HPP
# define MAX_HPP

# include <iostream>

template<typename T>
T	const &max(T const &x, T const &y)
{
	return (x > y ? x : y);
}


#endif