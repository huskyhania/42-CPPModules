#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("too few arguments to sort");
        PmergeMe misort;
        auto timer_start = std::chrono::high_resolution_clock::now();
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
                misort.addNumber(numInt);
            }
        }
        std::cout << "Before: ";
		misort.printVec();
        misort.sortVector();
        std::cout << "After:  ";
        misort.printVec();
        auto timer_end = std::chrono::high_resolution_clock::now();
        auto runtime = timer_end - timer_start;
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(runtime).count();
        std::cout << "Time to process a range of " << misort.getVecSize() << " with std::vector : " << us << " µs (microseconds)" << std::endl; 
        std::cout << "\033[31mTotal comparisons: " << misort.getComparisons() << std::endl;
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