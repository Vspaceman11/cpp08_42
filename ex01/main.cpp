#include "Span.hpp"
#include <iostream>
#include <numeric>

int main() {
	// TEST 1 Main
	std::cout << "=== Test 1: Subject Main ===" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << " (Expected: 14)" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// TEST 2 Adding 15000 elements
	std::cout << "\n=== Test 2: Mass add (C++17 Range) ===" << std::endl;
	try {
		Span bigSpan(20000);
		std::vector<int> generateData(15000);

		// Fill vector with numbers from 0 to 14999
		std::iota(generateData.begin(), generateData.end(), 0);

		// Add all range
		bigSpan.addRange(generateData.begin(), generateData.end());

		std::cout << "Successfully added 15000 elements!" << std::endl;
		std::cout << "Shortest span in consecutive range: " << bigSpan.shortestSpan() << " (Expected: 1)" << std::endl;
		std::cout << "Longest span in consecutive range: " << bigSpan.longestSpan() << " (Expected: 14999)" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	// TEST 3 Error handling
	std::cout << "\n=== Test 3: Error handling ===" << std::endl;
	try {
		Span small(1);
		small.addNumber(42);
		small.shortestSpan(); // Throw an exception while there is only one element
	} catch (const std::exception& e) {
		std::cerr << "Caught expected error: " << e.what() << std::endl;
	}

	return 0;
}
