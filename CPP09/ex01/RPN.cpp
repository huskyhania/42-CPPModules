/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:13:48 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/07/27 17:13:58 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isOperator(char elem)
{
	if (elem != '+' && elem != '-' && elem != '*' && elem != '/')
		return false;
	return true;
}

void	doMath(std::stack<int>& numStack, char opElem)
{
	if (numStack.size() < 2)
		throw std::runtime_error("Error: To few numbers on stack");
	else
	{
		long long tempResult;
		int second = numStack.top();
		numStack.pop();
		int first = numStack.top();
		numStack.pop();
		if (opElem == '+')
		{
			tempResult = (long long)first + (long long)second;
			if (tempResult > INT_MAX || tempResult < INT_MIN)
				throw std::overflow_error("Int overflow in addition");
			numStack.push(first + second);
		}
		else if (opElem == '-')
		{
			tempResult = (long long)first - (long long)second;
			if (tempResult > INT_MAX || tempResult < INT_MIN)
				throw std::overflow_error("Int overflow in subtraction");
			numStack.push(first - second);
		}
		else if (opElem == '*')
		{
			tempResult = (long long)first * (long long)second;
			if (tempResult > INT_MAX || tempResult < INT_MIN)
				throw std::overflow_error("Int overflow in multiplication");
			numStack.push(first * second);
		}
		else
		{
			if (second == 0)
				throw std::runtime_error("Error: division by 0");
			tempResult = (long long)first / (long long)second;
			if (tempResult > INT_MAX || tempResult < INT_MIN)
				throw std::overflow_error("Int overflow in division");
			numStack.push(first / second);
		}
		//std::cout << "Top of the stack after one operation: " << numStack.top() << std::endl;
	}
}

void	reverseMe(std::string input)
{
	std::istringstream iss(input);
	std::stack<int> stack;
	char elem;
	try
	{
		while (iss >> elem)
		{
			if (std::isdigit(elem))
			{
				stack.push(elem - '0');
			}
			else if (isOperator(elem))
			{
				doMath(stack, elem);
			}
			else
			{
				throw std::runtime_error("Error");
			}
		}
		if (stack.size() != 1)
			throw std::runtime_error("Error: leftover operands on stack");
		std::cout << stack.top() << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Sth went wrong..." << std::endl;
	}
}