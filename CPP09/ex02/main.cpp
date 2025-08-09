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

//make pairs returns a vector of vectors
std::vector<std::vector<int>> makePairs(std::vector<int>& nums, int& orphan)
{
        std::vector<std::vector<int>> pairs;
    
        if (nums.size() % 2 == 1) 
        {
            orphan = nums.back();
            nums.pop_back();
        }
        else
            orphan = -1;
        for (size_t i = 0; i < nums.size(); i += 2) 
        {
            if (nums[i] > nums[i+1])
                pairs.push_back({nums[i], nums[i+1]});
            else
                pairs.push_back({nums[i+1], nums[i]});
        }
        std::cout << "Pairs:\n";
        for (const auto& pair : pairs) 
        {
            std::cout << "(";
            for (size_t j = 0; j < pair.size(); ++j) 
            {
                std::cout << pair[j];
                if (j + 1 < pair.size()) std::cout << ", ";
            }
            std::cout << ")\n";
        }  
        return pairs;
}

// Recursively sort pairs based on the first (max) element
void sortFirstElements(std::vector<std::vector<int>>& pairs) 
{
    if (pairs.size() <= 1)
        return;

    std::vector<std::vector<int>> newPairs;

    for (size_t i = 0; i < pairs.size(); i += 2) 
    {
        if (i + 1 < pairs.size())
        {
            if (pairs[i][0] > pairs[i+1][0])
            {
                pairs[i].insert(pairs[i].end(), pairs[i+1].begin(), pairs[i+1].end());
                newPairs.push_back(pairs[i]);
            } 
            else 
            {
                pairs[i+1].insert(pairs[i+1].end(), pairs[i].begin(), pairs[i].end());
                newPairs.push_back(pairs[i+1]);
            }
        }
        else
            newPairs.push_back(pairs[i]);
    }
    pairs = newPairs;
    printPairs(pairs, "After sorting step:");
    sortFirstElements(pairs);
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
        int orphan;
        auto pairs = makePairs(orgNumbers, orphan);
        sortFirstElements(pairs);
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