/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:11:40 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/28 14:53:52 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

//function to test

int main(void)
{
	int a[] = {1, 3, 8, 5, 6, 2, 5};
	float b[] = {1.2, 6.2, 3.5, 0.1, 654.5};

	iter<int>(a, static_cast<size_t>(sizeof(a) / sizeof(a[0])), print_element_red<int>);
	std::cout << std::endl;
	iter<float>(b, static_cast<size_t>(sizeof(b) / sizeof(b[0])), print_element_red<float>);
	std::cout << std::endl;
	return (0);
}
