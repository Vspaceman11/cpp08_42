#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
	// TEST 1
	std::cout << "=== Test 1: std::vector ===" << std::endl;
	std::vector<int> vec = {10, 20, 30, 40, 50};

	try
	{
		auto it = easyfind(vec, 30);
		std::cout << "Found element: " << *it << std::endl;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

	// TEST 2
	std::cout << "\n=== Test 2: Exception handling ===" << std::endl;
	try
	{
		easyfind(vec, 999);
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Caught standard exception: " << e.what() << std::endl;
	}

	// TEST 3
	std::cout << "\n=== Test 3: std::list ===" << std::endl;
	std::list<int> myList = {7, 14, 21, 28};

	try
	{
		auto it = easyfind(myList, 14);
		std::cout << "Found in list: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
