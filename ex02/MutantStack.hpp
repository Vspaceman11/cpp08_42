#pragma once
#include <stack>
#include <iterator>

template <typename t>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		using iterator = typename std::stack<T>::container_type::iterator;
		using const_iterator = typename std::stack<T>::container_type::const_iterator;
		using reverse_iterator = typename std::stack<T>::container_type::reverse_iterator;
		using const_reverse_iterator = typename std::stack<T>::container_type::const_reverse_iterator;

		iterator begin() noexcept;
		iterator end() noexcept;

		const_iterator begin() const noexcept;
		const_iterator end() const noexcept;

		reverse_iterator rbegin() const noexcept;
		reverse_iterator rend() const noexcept;

		const_reverse_iterator rbegin() const noexcept;
		const_reverse_iterator rend() const noexcept;
};

#include "MutantStack.tpp"
