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
		std::vector<int> numbers;
		std::deque<int> numbersDeq;
		size_t comparisons = 0;
	public:
		void printBlocks(const std::vector<int>& vec, size_t elemSize, const std::string& name);
		std::vector<size_t>jacobsthalUpToSize(size_t n);
		std::vector<int> indexInsertionOrder(size_t pendCount);
		size_t jacobsthalSearchLimit(size_t pendIndex);

		PmergeMe() = default;
		PmergeMe(const PmergeMe& org);
		~PmergeMe() = default;
		PmergeMe &operator=(const PmergeMe& org);
	
		void addNumberVec(int n);
		void addNumberDeq(int n);

		void printVec();
		void printDeq();

		std::vector<int>& getNumbersVec();
		std::deque<int>& getNumbersDeq();
		size_t getComparisons() const;
		size_t getVecSize() const;
		size_t getDeqSize() const;
		void resetComparisons();
		void sortVector();
		void sortDeque();

		template <typename Container>
		void insertPendIntoMain(Container& sth, Container& main,
			Container& pend, Container& struggler, 
    		size_t elemSize)
		{
			if (elemSize == 0 || pend.size() < elemSize) 
				return;
		
			std::vector<int> pendBlocks;
			for (size_t i = 0; i + elemSize <= pend.size(); i += elemSize)
				pendBlocks.push_back(i);
			std::vector<bool> inserted(pendBlocks.size(), false);
			
			std::vector<int> jacobs_sequence = indexInsertionOrder(pendBlocks.size());


			auto comp = [&](int a, int b) 
			{
				comparisons++;
				return a < b;
			};

			auto insertOne = [&](size_t index, int jacobs_flag) 
			{
				size_t startPos = pendBlocks[index];
				auto elemBegin = pend.begin() + startPos;
				auto elemEnd   = elemBegin + elemSize;
				int val = *(elemEnd - 1);

				// find insertion position in main (block based)
				std::vector<int> mainEnds;
				for (size_t i = 0; i + elemSize <= main.size(); i += elemSize)
					mainEnds.push_back(main[i + elemSize - 1]);

				// calculate limit for the search
				size_t search_end = std::min(mainEnds.size(), jacobsthalSearchLimit(index));
			
				std::vector<int>::iterator it;
				if (jacobs_flag)
					it = std::upper_bound(mainEnds.begin(), mainEnds.begin() + search_end, val, comp);
				else
					it = std::upper_bound(mainEnds.begin(), mainEnds.end(), val, comp);
				
				// translate main blocks into position in actual main chain
				size_t insertionPoint = it - mainEnds.begin();
				auto pos = main.begin() + insertionPoint * elemSize;
				main.insert(pos, elemBegin, elemEnd);
				inserted[index] = true;
			};
			for (int idx : jacobs_sequence) 
			{
				insertOne(idx, 1);;
			}
			for (size_t i = 0; i < pendBlocks.size(); ++i)
			{
				if (!inserted[i])
					insertOne(i, 0);
			}
			main.insert(main.end(), struggler.begin(), struggler.end());
			sth = main;
		}
		
		template <typename Container>
		void mergeInsertSort(Container& container, size_t elemSize)
		{
			if (elemSize == 0 || container.size() / elemSize < 2) 
				return;
		
			for (size_t i = 0; i + elemSize * 2 <= container.size(); i += elemSize * 2) 
			{
				size_t leftEnd  = i + elemSize - 1;
				size_t rightEnd = i + 2 * elemSize - 1;
				comparisons++;
				if (container[leftEnd] > container[rightEnd])
				{
					for (size_t j = 0; j < elemSize; ++j)
						std::swap(container[i + j], container[i + elemSize + j]);
				}
			}

			mergeInsertSort(container, elemSize * 2);

			size_t blocks = container.size() / elemSize;
			Container main, pend;
			
			//adding b1 and a1 to main
			main.insert(main.end(), container.begin(), container.begin() + elemSize);
			main.insert(main.end(), container.begin() + elemSize, container.begin() + 2 * elemSize);
			for (size_t i = 2; i < blocks; ++i)
			{
				size_t index = i * elemSize;
				if (i % 2 == 1)
					main.insert(main.end(), container.begin() + index, container.begin() + index + elemSize);
				else
					pend.insert(pend.end(), container.begin() + index, container.begin() + index + elemSize);
			}

			Container struggler(container.begin() + blocks * elemSize, container.end());

			insertPendIntoMain(container, main, pend, struggler, elemSize);

		}

		template <typename Container>
		void printContainer(Container& container)
		{
			for (const auto& n : container)
				std::cout << n << " ";
			std::cout << std::endl;
		}
};

template <typename Container>
void addNumber(Container& container, int n)
{
	container.push_back(n);
}

template <typename Container, typename SortFunction>
long long populateAndSort(Container& container, int argc, char** argv, SortFunction sortFunc, bool printBefore = false)
{
	auto start = std::chrono::steady_clock::now();

	for (int i = 1; i < argc; ++i) 
	{
		try 
		{
			if (argv[i][0] == '\0') 
            	throw std::runtime_error("Empty argument");
			std::istringstream iss(argv[i]);
    		std::string token;
			while (iss >> token)
			{
				if (!std::all_of(token.begin(), token.end(), ::isdigit))
            		throw std::runtime_error("Invalid token: " + token);

				int num = std::stoi(token);
				addNumber(container, num);
			}
		}
		catch (std::invalid_argument&) 
		{
        	throw std::runtime_error(std::string("Invalid number: ") + argv[i]);
    	} 
    	catch (std::out_of_range&) 
		{
        	throw std::runtime_error(std::string("Number out of range: ") + argv[i]);
    	}
	}
	if (container.size() > 10000)
		throw std::runtime_error(std::string("Please don't try to break my program (max size 10k)"));
	if (std::is_sorted(container.begin(), container.end()))
		throw std::runtime_error(std::string("Why would you wanna sort a sorted container?"));
	if (printBefore)
	{
		std::cout << "Before : ";
		for (const auto& n : container)
			std::cout << n << " ";
		std::cout << std::endl;
	}
	sortFunc();

	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}
