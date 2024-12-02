// day01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>


int main()
{
    //std::cout << "Hello World!\n";
    std::vector<int> firstBlockArray;
    std::vector<int> secondBlockArray;

    std::ifstream file("input-test");
    std::string str;
    while (std::getline(file, str))
    {
        //std::cout << str << std::endl;

        std::string delimiter = "   ";
        std::string firstBlock = str.substr(0, str.find(delimiter));
        std::string secondBlock = str.substr(delimiter.length()+1, str.find(delimiter));

        firstBlockArray.push_back(std::stoi(firstBlock));
        secondBlockArray.push_back(std::stoi(secondBlock));

        //std::cout << "First Block:" << firstBlock << std::endl;
        //std::cout << "---" << std::endl;

        //std::cout << "Second Block:" << secondBlock << std::endl;
        //std::cout << "---" << std::endl;
    }

    //std::cout << "--- Do Sort First Block ---" << std::endl;
    //std::sort(firstBlockArray.begin(), firstBlockArray.end(), std::greater<int>());
    std::sort(firstBlockArray.begin(), firstBlockArray.end(), std::less<int>());
    std::sort(secondBlockArray.begin(), secondBlockArray.end(), std::less<int>());

    for (auto i = 0; i < firstBlockArray.size(); ++i)
    {
        std::cout << (secondBlockArray[i] - firstBlockArray[i]);
    }

    /*
    for (auto const& value : firstBlockArray)
    {
        std::cout << value << ",";
    }

    std::cout << std::endl;

    //std::cout << "--- Do Sort Second Block ---" << std::endl;
    //std::sort(secondBlockArray.begin(), secondBlockArray.end(), std::greater<int>());
    //std::sort(secondBlockArray.begin(), secondBlockArray.end(), std::less<int>());
    for (auto const& value : secondBlockArray)
    {
        std::cout << value << ",";
    }
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

