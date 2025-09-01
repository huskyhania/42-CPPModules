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

const std::vector<int>& PmergeMe::getNumbersVec() const
{
	return numbers;
}

const std::deque<int>& PmergeMe::getNumbersDeq() const
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


// Generates insertion order as indexes of b (2 .. n+1).
// pendCount = number of pend elements (b2..b_{n+1}).
// Example: pendCount = 5 -> pend are b2,b3,b4,b5,b6
std::vector<int> PmergeMe::pendInsertionOrder(size_t pendCount) 
{
    std::vector<int> order;
    if (pendCount == 0) return order;

    // Build Jacobsthal numbers until >= (n+1), then drop the last if it's > n+1.
    std::vector<uint64_t> J = {0, 1};
    while (J.back() < static_cast<uint64_t>(pendCount + 1))
        J.push_back(J[J.size() - 1] + 2ULL * J[J.size() - 2]);
    if (J.back() > static_cast<uint64_t>(pendCount + 1))
        J.pop_back();

    // For k = 3..max_k, insert b[start] .. b[prev+1] in reverse (start..prev+1)
    for (size_t k = 3; k < J.size(); ++k) 
    {
        int start = static_cast<int>(J[k]);
        int prev  = static_cast<int>(J[k - 1]);
        if (start > static_cast<int>(pendCount + 1))
            break; 
        for (int i = start; i > prev; --i) 
        {
            // i is a b-index (2..), only include if it exists in our pend range
            if (i >= 2 && i <= static_cast<int>(pendCount + 1))
                order.push_back(i);
        }
    }
    return order;
}

// Convenience: return 0-based pend indices (0 = b2, 1 = b3, ...)
std::vector<int> PmergeMe::indexInsertionOrder(size_t pendCount) 
{
    auto bIndices = pendInsertionOrder(pendCount);
    std::vector<int> res;
    res.reserve(bIndices.size());
    for (int bi : bIndices) 
        res.push_back(bi - 2); // convert b-index -> pend 0-based
    return res;
}

//based on Jacobsthal number, calculate the upper bound for the search
size_t PmergeMe::jacobsthalSearchLimit(size_t pendIndex) 
{
    // idx = 0-based pend index in Jacobsthal insertion order
    uint64_t J0 = 0, J1 = 1;
    size_t k = 1;
    while (true) 
    {
        uint64_t J_next = J1 + 2 * J0; // next Jacobsthal
        if (J_next > pendIndex + 1) 
            break;
        J0 = J1;
        J1 = J_next;
        k++;
    }
    return (1ULL << k) - 1; // 2^k - 1
}

// void PmergeMe::insertPendIntoMain(std::vector<int>& main,
//     std::vector<int>& pend, std::vector<int>& struggler, 
//     size_t elemSize) 
// {
//     // std::cout << "Beginning of insertion logic: " << std::endl;
//     // printBlocks(main, elemSize, "main");
//     // printBlocks(pend, elemSize, "pend");
//     if (elemSize == 0 || pend.size() < elemSize) 
//         return;
    
    
//     std::vector<int> pendElems;
//     for (size_t i = 0; i + elemSize <= pend.size(); i += elemSize)
//         pendElems.push_back(i);
//     std::vector<bool> inserted(pendElems.size(), false);
    
//     std::vector<int> bOrder = pendInsertionOrder(pendElems.size());

//     // Convert to pend indices (0-based)
//     std::vector<int> jacobs_sequence;
//     for (int bIndex : bOrder) 
//     {
//         int pendIdx = bIndex - 2;
//         if (pendIdx >= 0 && static_cast<size_t>(pendIdx) < pendElems.size())
//             jacobs_sequence.push_back(pendIdx);
//     }

//     // std::cout << "pend size: " << pendElems.size() << std::endl;
//     // std::cout << "generated jacobsthal seq: ";
//     // for (int n : jacobs_sequence) std::cout << n << " ";
//     // std::cout << std::endl;

//     auto comp = [&](int a, int b) 
//     {
//         comparisons++;
//         return a < b;
//     };

//     auto insertOne = [&](size_t idx, int jacobs_flag) 
//     {
//         size_t startIndex = pendElems[idx];
//         auto unitStart = pend.begin() + startIndex;
//         auto unitEnd   = unitStart + elemSize;
//         int value = *(unitEnd - 1);

//         // find insertion position in main
//         std::vector<int> mainEnds;
//         for (size_t i = 0; i + elemSize <= main.size(); i += elemSize)
//             mainEnds.push_back(main[i + elemSize - 1]);

//         size_t search_end = std::min(mainEnds.size(), jacobsthalSearchLimit(idx));
//         //size_t search_end = jacobsthalSearchLimit(idx);
//         // std::cout << "Index: " << idx << std::endl;
//         // std::cout << "Search end: " << search_end << std::endl;
//         // std::cout << "Jacobsthal search limit: " << jacobsthalSearchLimit(idx) << std::endl;
//         std::vector<int>::iterator it;
//         if (jacobs_flag)
//             it = std::upper_bound(mainEnds.begin(), mainEnds.begin() + search_end, value, comp);
//         else
//             it = std::upper_bound(mainEnds.begin(), mainEnds.end(), value, comp);
        
//         size_t insertIdx = it - mainEnds.begin();
//         auto pos = main.begin() + insertIdx * elemSize;
//         // if (search_end < mainEnds.size())
//         //     std::cout << "inserting: " << value << " of index " << idx 
//         //             << " before block ending " << mainEnds[search_end] << std::endl;
//         // else
//         //     std::cout << "inserting: " << value << " of index " << idx 
//         //             << " at end of main" << std::endl;
//         main.insert(pos, unitStart, unitEnd);
//         inserted[idx] = true;
//     };
//     //std::cout << "Before insertion:" << std::endl;
//     //printBlocks(main, elemSize, "main");
//     //printBlocks(pend, elemSize, "pend");
//     for (int idx : jacobs_sequence) 
//     {
//         //std::cout << "insertion happens from jacobs call\n";
//         insertOne(idx, 1);;
//     }
//     for (size_t i = 0; i < pendElems.size(); ++i)
//     {
//         if (!inserted[i])
//         {
//             //std::cout << "insertion outside of jacobs\n"; 
//             insertOne(i, 0);
//         }
//     }
//     main.insert(main.end(), struggler.begin(), struggler.end());
//     numbers = main; 
// }

// void PmergeMe::mergeInsertSort(size_t elemSize)
// {
//     if (elemSize == 0 || numbers.size() / elemSize < 2) 
//         return;
 
//     for (size_t i = 0; i + elemSize * 2 <= numbers.size(); i += elemSize * 2) 
//     {
//         size_t leftEnd  = i + elemSize - 1;
//         size_t rightEnd = i + 2 * elemSize - 1;
//         comparisons++;
//         if (numbers[leftEnd] > numbers[rightEnd])
//         {
//             for (size_t j = 0; j < elemSize; ++j)
//                 std::swap(numbers[i + j], numbers[i + elemSize + j]);
//         }
//     }

//     mergeInsertSort(elemSize * 2);

//     size_t blocks = numbers.size() / elemSize;
//     std::vector<int> main, pend;
    
//     //adding b1 and a1 to main
//     main.insert(main.end(), numbers.begin(), numbers.begin() + elemSize);
//     main.insert(main.end(), numbers.begin() + elemSize, numbers.begin() + 2 * elemSize);
//     for (size_t i = 2; i < blocks; ++i)
//     {
//         size_t index = i * elemSize;
//         if (i % 2 == 1)
//             main.insert(main.end(), numbers.begin() + index, numbers.begin() + index + elemSize);
//         else
//             pend.insert(pend.end(), numbers.begin() + index, numbers.begin() + index + elemSize);
//     }

//     std::vector<int>struggler(numbers.begin() + blocks * elemSize, numbers.end());

//     insertPendIntoMain(main, pend, struggler, elemSize);

// }

void PmergeMe::sortVector()
{
	mergeInsertSort<std::vector<int>>(numbers, 1);
}

void PmergeMe::sortDeque()
{
	mergeInsertSort<std::deque<int>>(numbersDeq, 1);
}