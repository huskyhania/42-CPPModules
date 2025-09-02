/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hskrzypi <hskrzypi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:00:51 by hskrzypi          #+#    #+#             */
/*   Updated: 2025/09/01 18:06:53 by hskrzypi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t	PmergeMe::getComparisons() const
{
	return comparisons;
}

void	PmergeMe::resetComparisons()
{
	comparisons = 0;
}

size_t PmergeMe::getVecSize() const
{
	return numbers.size();
}

size_t PmergeMe::getDeqSize() const
{
	return numbersDeq.size();
}

std::vector<int>& PmergeMe::getNumbersVec() 
{
	return numbers;
}

std::deque<int>& PmergeMe::getNumbersDeq()
{
	return numbersDeq;
}

void PmergeMe::printVec() 
{
	printContainer(numbers); 
}

void PmergeMe::printDeq()
{
	printContainer(numbersDeq);
}
void PmergeMe::addNumberVec(int n)
{
    addNumber(numbers, n);
}

void PmergeMe::addNumberDeq(int n)
{
	addNumber(numbersDeq, n);
}

void printBlocks(const std::vector<int>& vec, size_t elemSize, const std::string& name) 
{
    std::cout << name << ": ";
    for (size_t i = 0; i < vec.size(); i += elemSize) 
    {
        std::cout << "[";
        for (size_t j = 0; j < elemSize && i + j < vec.size(); ++j) 
        {
            std::cout << vec[i + j];
            if (j + 1 < elemSize) std::cout << ",";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::jacobsthalUpToSize(size_t n)
{
    std::vector<size_t> J = {0, 1};
    while (J.back() < n) 
        J.push_back(J[J.size() - 1] + 2 * J[J.size() - 2]);
    if (J.back() > n) 
        J.pop_back();
    return J;
}


// Generates insertion order as indexes of b (b2 has index 0, b3 - 1, b4 - 2 etc.)
// pendCount = number of pend elements (b2..b_{n+1}).
// Example: pendCount = 5 -> pend are b2,b3,b4,b5,b6
std::vector<int> PmergeMe::indexInsertionOrder(size_t pendCount) 
{
    std::vector<int> order;
    if (pendCount == 0) 
        return order;

    auto J = jacobsthalUpToSize(pendCount + 1);

    for (size_t k = 3; k < J.size(); ++k) 
    {
        int start = static_cast<int>(J[k]) - 2;
        int prev  = static_cast<int>(J[k - 1]) - 2;

        if (start >= static_cast<int>(pendCount))
            break;

        for (int i = start; i > prev; --i) 
        {
            if (i >= 0 && i < static_cast<int>(pendCount))
                order.push_back(i);
        }
    }
    return order;
}

// // Convenience: return 0-based pend indices (0 = b2, 1 = b3, ...)
// std::vector<int> PmergeMe::indexInsertionOrder(size_t pendCount) 
// {
//     auto bIndices = pendInsertionOrder(pendCount);
//     std::vector<int> res;
//     res.reserve(bIndices.size());
//     for (int bi : bIndices) 
//         res.push_back(bi - 2);
//     return res;
// }

//based on Jacobsthal number, calculate the upper bound for the search
size_t PmergeMe::jacobsthalSearchLimit(size_t pendIndex) 
{
    if (pendIndex < 2)
        return 3;
    auto J = jacobsthalUpToSize(pendIndex + 1);
    size_t k = J.size() - 1;
    return (1ULL << k) - 1;   // 2^k - 1
}

void PmergeMe::sortVector()
{
	mergeInsertSort(numbers, 1);
}

void PmergeMe::sortDeque()
{
	mergeInsertSort(numbersDeq, 1);
}

PmergeMe::PmergeMe(const PmergeMe& org)
    : numbers(org.numbers), 
    numbersDeq(org.numbersDeq), 
    comparisons(org.comparisons) {}

PmergeMe &PmergeMe::operator=(const PmergeMe& org)
{
    if (this != &org)
    {
        numbers = org.numbers;
        numbersDeq = org.numbersDeq;
        comparisons = org.comparisons;
    }
    return *this;
}

