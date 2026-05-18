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

};
