/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:59:26 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/31 17:58:33 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"
# include <iostream>
# define MAX_VAL 750

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

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
