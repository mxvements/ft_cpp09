/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucia <lucia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:32:23 by lucia             #+#    #+#             */
/*   Updated: 2025/04/06 20:32:24 by lucia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <climits>
# include <utility>
# include <algorithm>
# include <deque>
# include <vector>
# include <cctype>

/**
 * use of STL in the project, none of the containers should be used twice
 * bitcoin exchange -> associative container: Map
 * rpn -> stacks (int and string)
 * merge insert -> vector and deque (2 containers for comparison)
 */
class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        ~PmergeMe(void);
        PmergeMe(std::vector<std::string> &input);
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        void printVector(void);
        void printDeque(void);
        //sort

        //templated functions to do the merge sort -> not possible, since they dont share methods
        

} ;

#endif