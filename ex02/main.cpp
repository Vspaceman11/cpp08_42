#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	// --- TEST 1 Subject tests
	std::cout << "=== Test 1: Subject Main ===" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << " (Expected: 17)" << std::endl;

	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << " (Expected: 1)" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "Stack elements: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n(Expected: 5 3 5 737 0)" << std::endl;

	// Basic stack copy check
	std::stack<int> s(mstack);

	// TEST 2 Compare with list
	std::cout << "\n=== Test 2: Same logic with std::list ===" << std::endl;
	std::list<int> myList;
	myList.push_back(5);
	myList.push_back(17);
	myList.pop_back();
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);

	std::list<int>::iterator lit = myList.begin();
	std::list<int>::iterator lite = myList.end();
	std::cout << "List elements:  ";
	while (lit != lite) {
		std::cout << *lit << " ";
		++lit;
	}


	it = mstack.begin();
	std::cout << "\nMy Stack elements: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	return 0;
}
