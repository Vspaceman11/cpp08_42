#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	auto distance = std::distance(begin, end);
	if (_storage.size() + distance > _maxSize)
	{
		throw std::runtime_error("Error: Not enough space in Span!");
	}
	_storage.insert(_storage.end(), begin, end);
}
