/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:59:24 by luciama2          #+#    #+#             */
/*   Updated: 2025/03/31 17:57:55 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <climits>
# include <stdlib.h>

template<typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_len;
	protected:
	public:
		~Array(void);
		Array(void);
		Array(unsigned int len);
		Array(const Array &src);
		Array &operator=(const Array &src);
		T &operator[](unsigned int len); //allocates memory

		class OutOfBoundsException : public std::exception {
			public:
				const char *what() const throw();
		};

		unsigned int size(void) const;
} ;

// definition of template functions
template<typename T>
Array<T>::~Array(void)
{
	if (_array)
		delete [] _array;
}
//construction with no parameter creates an empty array
template<typename T>
Array<T>::Array(void): _len(0)
{
	_array = new T[0]();
}

//unsign int param -> creates an array of unsigned int
template<typename T>
Array<T>::Array(unsigned int len): _len(len)
{
	// new[] operator to allocate memory on the array
	_array = new T[len]();
}

template<typename T>
Array<T>::Array(const Array &src): _len(src._len)
{
	this->_array = new T[src._len]();
	for (unsigned int i = 0; i < src._len; i++)
			_array[i] = src._array[i];	
}

//modifiying either the original array of its copy after copying musn't affect the other.
template<typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		if (this->_array)
			delete [] this->_array;
		_len = src._len;
		_array = new T[src._len]();
		for (unsigned int i = 0; i < src._len; i++)
			_array[i] = src._array[i];
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int size)
{
	if (size >= _len || !_array)
		throw Array<T>::OutOfBoundsException();
	return (_array[size]);	
}

template<typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Out of bounds";
}

template<typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_len);
}

#endif