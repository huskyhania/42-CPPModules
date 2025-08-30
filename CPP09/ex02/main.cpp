#include <sstream>
#include <vector>
#include <iostream>
#include <exception>
#include <algorithm>
//validate input (positive ints)
static size_t comparisons = 0;

unsigned int jacobsthal_number(unsigned int num)
{
    if (num == 0) 
        return 0;
    if (num == 1) 
        return 1;
    return jacobsthal_number(num - 1) + 2 * jacobsthal_number(num - 2);
}

std::vector<int> jacobsthalSequence(size_t n) 
{
    std::vector<int> seq;
    if (n == 0) 
        return seq;

    std::vector<int> j = {0, 1};
    while (j.back() < static_cast<int>(n))
        j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);
    j.pop_back();

    for (size_t k = 3; k < j.size(); ++k) 
    {
        for (int i = j[k]; i > j[k - 1]; --i) 
        {
            if (i - 1 < static_cast<int>(n))
                seq.push_back(i - 1);
        }
    }
    return seq;
}

void insertPendIntoMain(std::vector<int>& main,
    std::vector<int>& pend, std::vector<int>& struggler, 
    size_t elemSize, std::vector<int>& numbers) 
{
    if (elemSize == 0 || pend.size() < elemSize) 
        return;
    
    
    std::vector<int> pendElems;
    for (size_t i = 0; i + elemSize <= pend.size(); i += elemSize)
        pendElems.push_back(i);
    std::vector<bool> inserted(pendElems.size(), false);
    std::vector<int> jacobs_sequence = jacobsthalSequence(pendElems.size());
    std::cout << "generated jacobsthal seq: ";
    for (int n : jacobs_sequence) std::cout << n << " ";
    std::cout << std::endl;

    auto comp = [&](int a, int b) 
    {
        comparisons++;
        return a < b;
    };

    auto insertOne = [&](size_t idx) 
    {
        size_t startIndex = pendElems[idx];
        auto unitStart = pend.begin() + startIndex;
        auto unitEnd   = unitStart + elemSize;
        int value = *(unitEnd - 1);

        // find insertion position in main
        std::vector<int> mainEnds;
        for (size_t i = 0; i + elemSize <= main.size(); i += elemSize)
            mainEnds.push_back(main[i + elemSize - 1]);

        auto it = std::upper_bound(mainEnds.begin(), mainEnds.end(), value, comp);
        size_t insertIdx = it - mainEnds.begin();
        auto pos = main.begin() + insertIdx * elemSize;

        main.insert(pos, unitStart, unitEnd);
        inserted[idx] = true;
    };


    for (int idx : jacobs_sequence) 
    {
        if (idx >= 2 && static_cast<size_t>(idx) < pendElems.size())
            insertOne(idx);
    }
    for (size_t i = 0; i < pendElems.size(); ++i)
        if (!inserted[i]) insertOne(i);
    main.insert(main.end(), struggler.begin(), struggler.end());
    numbers = main; 
}

void mergeInsertSort(std::vector<int>& numbers, size_t elemSize)
{
    if (elemSize == 0 || numbers.size() / elemSize < 2) 
        return;
    bool isOdd = 0;
    size_t numElems = numbers.size() / elemSize;
    if (numElems % 2 != 0)
        isOdd = 1;
 
    for (size_t i = 0; i + elemSize * 2 <= numbers.size(); i += elemSize * 2) 
    {
        size_t leftEnd  = i + elemSize - 1;
        size_t rightEnd = i + 2 * elemSize - 1;
        comparisons++;
        if (numbers[leftEnd] > numbers[rightEnd])
        {
            for (size_t j = 0; j < elemSize; ++j)
                std::swap(numbers[i + j], numbers[i + elemSize + j]);
        }
    }
    // std::cout << "After elemSize " << elemSize << ": ";
    // for (int n : numbers) std::cout << n << " ";
    // std::cout << "\n";
    mergeInsertSort(numbers, elemSize * 2);
    //initial block swapping done (size of elems increased from 1 to biggest possible)

    size_t blocks = numbers.size() / elemSize;
    std::vector<int> main, pend;
    
    //adding b1 and a1 to main
    main.insert(main.end(), numbers.begin(), numbers.begin() + elemSize);
    main.insert(main.end(), numbers.begin() + elemSize, numbers.begin() + 2 * elemSize);
    for (size_t i = 2; i < blocks; ++i)
    {
        size_t index = i * elemSize;
        if (i % 2 == 1)
            main.insert(main.end(), numbers.begin() + index, numbers.begin() + index + elemSize);
        else
            pend.insert(pend.end(), numbers.begin() + index, numbers.begin() + index + elemSize);
    }
    //remaining numbers
    std::vector<int>struggler(numbers.begin() + blocks * elemSize, numbers.end());

    //insertion part
    insertPendIntoMain(main, pend, struggler, elemSize, numbers);

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
        mergeInsertSort(orgNumbers, 1);
        std::cout << "Sorting done: ";
        for (const auto& item : orgNumbers)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;
        std::cout << "\033[31mTotal comparisons: " << comparisons << std::endl;
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