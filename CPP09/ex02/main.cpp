#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
//validate input (positive ints)

unsigned int jacobsthal_number(unsigned int num)
{
    if (num == 0) 
        return 0;
    if (num == 1) 
        return 1;
    return jacobsthal_number(num - 1) + 2 * jacobsthal_number(num - 2);
}

// void printPairs(const std::vector<std::vector<int>>& pairs, const std::string& msg = "") 
// {
//     if (!msg.empty()) 
//         std::cout << msg << "\n";
//     for (const auto& pair : pairs) 
//     {
//         std::cout << "(";
//         for (size_t i = 0; i < pair.size(); ++i) 
//         {
//             std::cout << pair[i];
//             if (i + 1 < pair.size()) std::cout << ", ";
//         }
//         std::cout << ") ";
//     }
//     std::cout << "\n\n";
// }

// void printGroups(const std::vector<std::vector<int>>& groups, const std::string& msg = "") 
// {
//     if (!msg.empty()) std::cout << msg << "\n";
//     for (const auto& g : groups) 
//     {
//         std::cout << "(";
//         for (size_t i = 0; i < g.size(); ++i) {
//             std::cout << g[i];
//             if (i + 1 < g.size()) std::cout << ", ";
//         }
//         std::cout << ") ";
//     }
//     std::cout << "\n\n";
// }

// void debugStep(const std::vector<int>& left, const std::vector<int>& right, 
//                int winner, int loser) 
// {
//     std::cout << "Comparing pairs (" << left[0] << "," << left[1] 
//               << ") and (" << right[0] << "," << right[1] << "): ";
//     std::cout << "Winner = " << winner << ", Loser = " << loser << "\n";
// }

void insertPendIntoMain(std::vector<int>& main, std::vector<int>& pend) 
{
    std::vector<bool> inserted(pend.size(), false);

    size_t k = 1;
    size_t J = jacobsthal_number(k);
    while (J <= pend.size()) {
        size_t index = J - 1;
        if (!inserted[index]) 
        {
            auto pos = std::lower_bound(main.begin(), main.end(), pend[index]);
            main.insert(pos, pend[index]);
            inserted[index] = true;
        }
        k++;
        J = jacobsthal_number(k);
    }

    // Insert remaining pend elements
    for (size_t i = 0; i < pend.size(); ++i) 
    {
        if (!inserted[i]) 
        {
            auto pos = std::lower_bound(main.begin(), main.end(), pend[i]);
            main.insert(pos, pend[i]);
        }
    }
}

void mainPendBuild(std::vector<int>& numbers, size_t largestBlock)
{
    size_t block = largestBlock;
    while (block >= 1) 
    {
        std::vector<int> blockEnds;
        for (size_t i = block - 1; i < numbers.size(); i += block)
            blockEnds.push_back(numbers[i]);

        std::vector<int> main, pend;
        if (blockEnds.size() >= 2) 
        {
            main.push_back(blockEnds[0]);
            main.push_back(blockEnds[1]);

            for (size_t i = 2; i + 1 < blockEnds.size(); i += 2) 
            {
                pend.push_back(blockEnds[i]);       // b_i
                main.push_back(blockEnds[i+1]);     // a_i
            }
            if (blockEnds.size() % 2 != 0)
                pend.push_back(blockEnds.back());
        } 
        else if (blockEnds.size() == 1) 
        {
            main.push_back(blockEnds[0]);
        }
        std::cout << "main before insertion: " << std::endl;
        for (auto v : main) 
            std::cout << v << " ";
        std::cout << std::endl;
        insertPendIntoMain(main, pend);
        std::cout << "main after insertion: " << std::endl;
        for (auto v : main) 
            std::cout << v << " "; 
        std::cout << std::endl;

        if (block == 1) 
            break;
        block /= 2;
    }
}

void mergeSort(std::vector<int>& numbers, size_t elemSize, size_t& largestBlock)
{
    bool isOdd = 0;
    size_t numElems = numbers.size() / elemSize;
    if (numElems % 2 != 0)
        isOdd = 1;
    if (elemSize == 1)
    {
        for (size_t i = 0; i + 1 < numbers.size(); i += 2)
        {
            if (numbers[i] > numbers[i + 1]) //count these
            {
                std::swap(numbers[i], numbers[i + 1]);
            }
        }
    } 
    else 
    {
        for (size_t i = 0; i + elemSize * 2 <= numbers.size(); i += elemSize * 2) 
        {
            size_t leftEnd  = i + elemSize - 1;
            size_t rightEnd = i + 2 * elemSize - 1;
            std::cout << "numbers compared: " << numbers[leftEnd] << " and " 
            << numbers[rightEnd] << std::endl;
            if (numbers[leftEnd] > numbers[rightEnd])//count these!!!
            {
                for (size_t j = 0; j < elemSize; ++j) {
                    std::swap(numbers[i + j], numbers[i + elemSize + j]);
                }
            }
        }
    }
    std::cout << "After elemSize " << elemSize << ": ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << "\n";
    if (elemSize * 2 * 2 <= numbers.size())
    {
        std::cout << "recursive call for elem size: " << elemSize * 2 << std::endl;
        mergeSort(numbers, elemSize * 2, largestBlock);
    }
    else
        largestBlock = elemSize;
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
        size_t largestBlock = 0;
        mergeSort(orgNumbers, 1, largestBlock);
        mainPendBuild(orgNumbers, largestBlock);
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