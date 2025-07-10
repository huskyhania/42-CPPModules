#pragma once
#include <vector>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:
		Span(unsigned int n);
		Span(const &Span original);
		Span &operator=(const &Span original);
		~Span();
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);//template implement here
};
