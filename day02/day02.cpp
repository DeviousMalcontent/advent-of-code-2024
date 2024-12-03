// day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    //std::cout << "Hello World!\n";
    //std::vector<int> firstBlockArray, secondBlockArray;
   
    std::ifstream file("input-test");
    //std::ifstream file("input");
    std::stringstream stream;
    std::string Reports, first, second;
    std::vector<std::string> Levels;
    //std::string delimiter = " ";

    if (file) {
        stream << file.rdbuf();
        //std::cout << stream.str();

        while (std::getline(stream, Reports, ' ')) {
            std::string::size_type pos = Reports.find('\n');
            if (Reports.npos != pos) {
                first = Reports.substr(pos + 1);
                second = Reports.substr(0, pos);
                if(first.empty() && !second.empty()) {
                      Levels.push_back(second);
                } else {
                    Levels.push_back(second);
                    Levels.push_back("\n");
                    Levels.push_back(first);
                }
            } else {
                Levels.push_back(Reports);
            }
        }
        file.close();
    }

    for (int i = 0; i < Levels.size(); i++) {
        std::cout << Levels[i];
    }
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
