// day01-part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <map>
#include <iterator>

template<typename C, typename T>
bool contains(C&& c, T e) {
    return std::find(std::begin(c), std::end(c), e) != std::end(c);
};

int main()
{
    std::vector<int> firstBlockArray, secondBlockArray;

    //std::ifstream file("input-test");
    std::ifstream file("input");
    std::string str;
    while (std::getline(file, str))
    {
        std::string delimiter = "   ";
        std::string firstBlock = str.substr(0, str.find(delimiter));
        std::string secondBlock = str.substr(firstBlock.length() + delimiter.length(), str.find(delimiter));

        firstBlockArray.push_back(std::stoi(firstBlock));
        secondBlockArray.push_back(std::stoi(secondBlock));
    }

    std::sort(firstBlockArray.begin(), firstBlockArray.end(), std::less<int>());
    std::sort(secondBlockArray.begin(), secondBlockArray.end(), std::less<int>());

    /*std::map<int, int> counts;
    for (int i = 0; i < firstBlockArray.size(); i++) {
        counts[firstBlockArray[i]]++;
    } */

    std::map<int, int> counts;
    for (int i = 0; i < secondBlockArray.size(); i++) {
        counts[secondBlockArray[i]]++;
    }

    std::cout << "--- Print Map ---" << std::endl;
    for (auto const& value : counts)
    {
        //std::cout << "[" << value.first << "," << value.second << "]";
        std::cout << "The number " << value.first << " appears " << value.second << " times in the Second Block Array." << std::endl;
    }

    int sum = 0;

    std::cout << "--- Match and do Calc ---" << std::endl;
    for (size_t i = 0; i < firstBlockArray.size(); ++i)
    {
        if(contains(secondBlockArray, firstBlockArray[i])) {
            std::cout << "The number " << firstBlockArray[i] << " was found in the Second Block Array, and appears " << counts.find(firstBlockArray[i])->second << " times." << std::endl;
            //counts.find(firstBlockArray[i])->second;

            sum = sum + (firstBlockArray[i] * counts.find(firstBlockArray[i])->second);
        }
        else {
            std::cout << "The number " << firstBlockArray[i] << " was NOT found in the Second Block Array." << std::endl;

            //sum = sum + firstBlockArray[i];
        }
    }

    std::cout << "--- Answer ---" << std::endl;
    std::cout << sum;

    /*
    int sum = 0;

    for (size_t i = 0; i < firstBlockArray.size(); ++i)
    {
        sum = sum + std::abs(secondBlockArray[i] - firstBlockArray[i]);
    }

    std::cout << "--- Answer ---" << std::endl;
    std::cout << sum; */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
