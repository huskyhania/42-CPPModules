#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
//validate input (positive ints, no duplicates)
//populate a container

void printPairs(const std::vector<std::vector<int>>& pairs, const std::string& msg = "") 
{
    if (!msg.empty()) 
        std::cout << msg << "\n";
    for (const auto& pair : pairs) 
    {
        std::cout << "(";
        for (size_t i = 0; i < pair.size(); ++i) 
        {
            std::cout << pair[i];
            if (i + 1 < pair.size()) std::cout << ", ";
        }
        std::cout << ") ";
    }
    std::cout << "\n\n";
}

void printGroups(const std::vector<std::vector<int>>& groups, const std::string& msg = "") 
{
    if (!msg.empty()) std::cout << msg << "\n";
    for (const auto& g : groups) 
    {
        std::cout << "(";
        for (size_t i = 0; i < g.size(); ++i) {
            std::cout << g[i];
            if (i + 1 < g.size()) std::cout << ", ";
        }
        std::cout << ") ";
    }
    std::cout << "\n\n";
}

void debugStep(const std::vector<int>& left, const std::vector<int>& right, 
               int winner, int loser) 
{
    std::cout << "Comparing pairs (" << left[0] << "," << left[1] 
              << ") and (" << right[0] << "," << right[1] << "): ";
    std::cout << "Winner = " << winner << ", Loser = " << loser << "\n";
}

void mergeSort(std::vector<int>& numbers, size_t elemSize) 
{
    if (elemSize >= numbers.size()) 
        return;
    else 
    {
        size_t half = elemSize / 2;

        for (size_t i = 0; i + elemSize <= numbers.size(); i += elemSize) 
        {
            size_t leftEnd  = i + half - 1;
            size_t rightEnd = i + elemSize - 1;
            std::cout << "numbers compared: " << numbers[leftEnd] << " and " 
            << numbers[rightEnd] << std::endl;
            if (numbers[leftEnd] > numbers[rightEnd]) 
            {
                for (size_t j = 0; j < half; ++j) 
                {
                    std::swap(numbers[i + j], numbers[i + half + j]); // COUNT
                }
            }
        }
    }
    std::cout << "recursion for elem size: " << elemSize << std::endl;
    for (auto it = numbers.begin(); it != numbers.end(); it++)
    {
        std::cout << *it;
        std::cout << " ";
    }
    std::cout << std::endl;
    if (elemSize * 2 <= numbers.size())
        mergeSort(numbers, elemSize * 2);
}

int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
            throw std::runtime_error("too few arguments to sort");
        std::vector<int> orgNumbers;
        for (int i = 1; i < argc; ++i) 
        {
            std::istringstream iss(argv[i]);
            std::string num;
            int numInt;
            while (iss >> num) 
            {
                numInt = stoi(num);
                orgNumbers.push_back(numInt);
            }
        }
        std::cout << "Before: ";
        for (const auto& item : orgNumbers)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
        mergeSort(orgNumbers, 2);
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