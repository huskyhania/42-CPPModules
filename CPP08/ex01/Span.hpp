#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numVec;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span &original);
		Span &operator=(const Span &original);
		~Span();
		void addNumber(int n);
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end)
		{
			size_t rangeSize = std::distance(begin, end);
			if (_numVec.size() + rangeSize > _maxSize)
				throw std::runtime_error("Not enough place in Span");
			_numVec.insert(_numVec.end(), begin, end);
		}
		
		size_t size(void);
		void print(void) const; 
};
