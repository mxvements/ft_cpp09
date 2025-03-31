/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:09:51 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/31 19:50:27 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Max.hpp"
#include "Min.hpp"
#include "Swap.hpp"
#include "Colors.hpp"

int main(void)
{
	//int
	int x = 1;
	int y = 4;
	std::cout << FG_LIGHT_CYAN << " x : " << BOLD << x << RESET << FG_LIGHT_CYAN << ", y : " << BOLD << y << RESET << std::endl;
	swap<int>(x, y);
	std::cout << "after swap -> x : " << x << ", y : " << y << std::endl;
	std::cout << "min : " << min<int>(x, y) << ", max : " << max<int>(x, y) << std::endl;

	//float
	float a = 1.3;
	float b = 2.5;
	std::cout << FG_LIGHT_CYAN << " a : " << BOLD << a << RESET << FG_LIGHT_CYAN << ", b : " << BOLD << b << RESET << std::endl;
	swap<float>(a, b);
	std::cout << "after swap -> a : " << a << ", b : " << b << std::endl;
	std::cout << "min : " << min<float>(a, b) << ", max : " << max<float>(a, b) << std::endl;
	return (0);
}
