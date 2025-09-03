#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("too few arguments to sort");
        PmergeMe misort;
        
        long long timeVec = populateAndSort(misort.getNumbersVec(), argc, argv, [&]{ misort.sortVector();}, true);
        //std::cout << "Total comparisons: " << misort.getComparisons() << std::endl;
        if (!std::is_sorted(misort.getNumbersVec().begin(), misort.getNumbersVec().end()))
            std::cout << "SORTING ERROR IN VECTOR!!!!!!\n\n";
        //misort.printVec(); 
		misort.resetComparisons();
        long long timeDeq = populateAndSort(misort.getNumbersDeq(), argc, argv, [&]{ misort.sortDeque();}, false);
        std::cout << "After  : ";
        misort.printDeq();
        std::cout << "Time to process a range of " << misort.getVecSize() << " with std::vector : " << timeVec << " µs (microseconds)" << std::endl;
        std::cout << "Time to process a range of " << misort.getDeqSize() << " with std::deque  : " << timeDeq << " µs (microseconds)" << std::endl; 
        // std::cout << "Total comparisons: " << misort.getComparisons() << std::endl;
        if (!std::is_sorted(misort.getNumbersDeq().begin(), misort.getNumbersDeq().end()))
            std::cout << "SORTING ERROR IN DEQUE!!!!!!\n\n";
    }
    catch(std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error: something else went wrong...";
    }
    return 0;
}