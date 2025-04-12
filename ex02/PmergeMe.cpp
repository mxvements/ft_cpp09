/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:26 by lucia             #+#    #+#             */
/*   Updated: 2025/04/06 20:32:32 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* ************************************************************************** */
/* orthodox canonical form  */

PmergeMe::~PmergeMe(void){}

PmergeMe::PmergeMe(std::vector<std::string> &input){
    for (std::vector<std::string>::const_iterator i = input.end() - 1; i >= input.begin(); i--)
    {
        this->_vector.push_back(atoi((*i).c_str()));
        this->_deque.push_back(atoi((*i).c_str()));
    }

}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    if (this != &src){
        this->_vector = src._vector;
        this->_deque = src._deque;
    }
    return (*this);
}

/* ************************************************************************** */

void  PmergeMe::printVector(void){
    for (std::vector<int>::iterator i = this->_vector.begin(); i < this->_vector.end(); i++)
    {
        std::cout << "vector : " << *i << std::endl;
    }
}

void PmergeMe::printDeque(void){
 for (std::deque<int>::iterator i = this->_deque.begin(); i < this->_deque.end(); i++)
    {
        std::cout << "deque : " << *i << std::endl;
    }
}
