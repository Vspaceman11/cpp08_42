#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iterator>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _storage;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;


		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);
};

#include "Span.tpp"
