#pragma once
#include <sstream>
#include <vector>
#include <deque>
#include <iostream>
#include <exception>
#include <algorithm>
#include <cstdint>
#include <chrono>

class PmergeMe
{
	private:
		std::vector<int> numbersVec;
		std::deque<int> numbersDeq;
		size_t comparisons = 0;
	public:
		void mergeInsertSort(size_t elemSize);
		void printBlocks(const std::vector<int>& vec, size_t elemSize, const std::string& name);
		std::vector<int> pendInsertionOrder(size_t pendCount);
		std::vector<int> indexInsertionOrder(size_t pendCount);
		size_t jacobsthalSearchLimit(size_t pendIndex);
		void insertPendIntoMain(std::vector<int>& main,
			std::vector<int>& pend, std::vector<int>& struggler, 
    		size_t elemSize);
		PmergeMe() = default;
		~PmergeMe() = default;
			//copy
			//asignement
		void addNumber(int n);
		void printVec();
		const std::vector<int>& getNumbersVec() const;
		const std::deque<int>& getNumbersDeq() const;
		size_t getComparisons() const;
		size_t getVecSize() const;
		size_t getDeqSize() const;
		void resetComparisons();
		void sortVector();
		void sortDeque();
};

