/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:14:47 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/14 14:28:42 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &original) : _maxSize(original._maxSize), _numVec(original._numVec) {}

Span &Span::operator=(const Span &original)
{
	if (this != &original)
	{
		_maxSize = original._maxSize;
		_numVec = original._numVec;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_numVec.size() >= _maxSize)
		throw std::runtime_error("Not enough place in Span");
	_numVec.push_back(n);

}

unsigned int Span::shortestSpan(void)
{
	if (_numVec.size() <= 1)
		throw std::runtime_error("Size too small to check the shortest span");
	std::vector<int> temp = _numVec;
	std::sort(temp.begin(), temp.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < temp.size(); ++i)
	{
		minSpan = std::min(minSpan, temp[i] - temp[i - 1]);
	}
	return minSpan;
}
unsigned int Span::longestSpan(void)
{
	if (_numVec.size() <= 1)
		throw std::runtime_error("Size too small to check the longest span");
	
	auto [minIt, maxIt] = std::minmax_element(_numVec.begin(), _numVec.end());
	return static_cast<unsigned int>(*maxIt - *minIt);
}

//iterators

// std::vector<int>::iterator Span::begin()
// {
// 	return _numVec.begin();
// }

// std::vector<int>::iterator Span::end()
// {
// 	return _numVec.end();
// }

// std::vector<int>::const_iterator Span::begin() const
// {
// 	return _numVec.begin();
// }

// std::vector<int>::const_iterator Span::end() const 
// {
// 	return _numVec.end();
// }

size_t Span::size(void) 
{
	return _numVec.size();
}

void Span::print(void) const 
{
    for (size_t i = 0; i < _numVec.size(); ++i)
        std::cout << _numVec[i] << " ";
    std::cout << std::endl;
}