#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("too few arguments to sort");
        PmergeMe misort;
        auto timer_start = std::chrono::steady_clock::now();
        for (int i = 1; i < argc; ++i) 
        {
            std::istringstream iss(argv[i]);
            std::string num;
            int numInt;
            while (iss >> num) 
            {
                numInt = stoi(num);
                if (numInt < 0)
                    throw std::runtime_error("negative numbers in input");
                misort.addNumberVec(numInt);
            }
        }
        std::cout << "Before: ";
		misort.printVec();
        misort.sortVector();
        auto timer_end = std::chrono::steady_clock::now();
        auto runtime = timer_end - timer_start;
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(runtime).count();
         
        //std::cout << "Total comparisons: " << misort.getComparisons() << std::endl;
        if (!std::is_sorted(misort.getNumbersVec().begin(), misort.getNumbersVec().end()))
            std::cout << "SORTING ERROR IN VECTOR!!!!!!\n\n";
		misort.resetComparisons();
		auto timer_start2 = std::chrono::steady_clock::now();
        for (int i = 1; i < argc; ++i) 
        {
            std::istringstream iss(argv[i]);
            std::string num;
            int numInt;
            while (iss >> num) 
            {
                numInt = stoi(num);
                if (numInt < 0)
                    throw std::runtime_error("negative numbers in input");
                misort.addNumberDeq(numInt);
            }
        }
        misort.sortDeque();
        std::cout << "After:  ";
        misort.printDeq();
        auto timer_end2 = std::chrono::steady_clock::now();
        auto runtime2 = timer_end2 - timer_start2;
        auto us2 = std::chrono::duration_cast<std::chrono::microseconds>(runtime2).count();
        std::cout << "Time to process a range of " << misort.getVecSize() << " with std::vector : " << us << " µs (microseconds)" << std::endl;
        std::cout << "Time to process a range of " << misort.getDeqSize() << " with std::deque  : " << us2 << " µs (microseconds)" << std::endl; 
        std::cout << "Total comparisons: " << misort.getComparisons() << std::endl;
        if (!std::is_sorted(misort.getNumbersDeq().begin(), misort.getNumbersDeq().end()))
            std::cout << "SORTING ERROR IN DEQUE!!!!!!\n\n";

    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "something went wrong...";
    }
    return 0;
}