#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span& other)
{
	*this = other;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_maxSize = other._maxSize;
		this->_storage = other._storage;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_storage.size() >= _maxSize)
	{
		throw std::runtime_error("Error: Span is already full!");
	}
	_storage.push_back(number);
}

int Span::longestSpan() const
{
	if (_storage.size() < 2)
	{
		throw std::runtime_error("Error: Not enough elements to find a span!");
	}
	auto [min_it, max_it] = std::minmax_element(_storage.begin(), _storage.end());
	return *max_it - *min_it;
}

int Span::shortestSpan() const
{
	if (_storage.size() < 2)
	{
		throw std::runtime_error("Error: Not enough elements to find a span!");
	}

	auto copy = _storage;
	std::sort(copy.begin(), copy.end());

	int min_span = copy[1] - copy[0];
	for (size_t i = 1; i < copy.size() - 1; ++i)
	{
		int current_span = copy[i + 1] - copy[i];
		if (current_span < min_span)
		{
			min_span = current_span;
		}
	}
	return min_span;
}
