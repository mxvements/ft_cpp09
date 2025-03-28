/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:59:26 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/28 17:39:09 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

/**
 * notes
 * 
 * operator[] overload
 * allows us to acess array elements -> array[index]
 *  new int[size] -> dynamically allocates an array of size * int 
 * 	we usually overload the operator for const objects (read-only array)
 */


int main(void)
{
	Array<int> a;
	std::cout << "a: empty array of int : " << a.size() << std::endl;
	
	Array<float> b(10);
	std::cout << "b : array of floats : " << b.size() << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
	{
		std::cout << "b : intilized as: " << i << " : " << b[i] << std::endl;
		b[i] = i;
		std::cout << "b : value: " << i << " : " << b[i] << std::endl;
	}

	Array<float> c;
	c = b;
	std::cout << "c : array of floats : " << c.size() << std::endl;
	for (unsigned int i = 0; i < c.size(); i++)
	{
		std::cout << "c : value: " << i << " : " << c[i] << std::endl;
	}
	return (0);
}
