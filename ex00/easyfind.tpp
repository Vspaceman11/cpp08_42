#include "easyfind.hpp"

template <typename T>
auto easyfind(T& container, int toFind)
{
	auto it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::runtime_error("Error: Element not found.");
	return it;
}
