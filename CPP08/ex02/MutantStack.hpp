/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:35:10 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/15 17:38:16 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() = default;
		MutantStack(const MutantStack &original) = default;
		MutantStack &operator=(const MutantStack &original) = default;
		~MutantStack() = default;

		//exposing containers of underlying container - deque, which has iterators
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		//const_iterator const (begin, end, rbegin, rend) will work on a const instance
		//const_iterator const (cbegin, cend, crbergin, crend) will work on normal instance but return const iterator
		//they are clearer with the intention and more modern c++ practices
		//(both are like a read only view)

		iterator begin() { return this->c.begin(); }
		const_iterator begin() const { return this->c.begin(); }
		const_iterator cbegin() const { return this->c.cbegin(); }

		iterator end() { return this->c.end(); }
		const_iterator end() const { return this->c.end(); }
		const_iterator cend() const { return this->c.cend(); }
		
		reverse_iterator rbegin() { return this->c.rbegin(); }
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator crbegin() const { return this->c.crbegin(); }
		
		reverse_iterator rend() { return this->c.rend(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
		const_reverse_iterator crend() const { return this->c.crend(); }
};
