// day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>


// d for distance (https://en.wikipedia.org/wiki/Euclidean_distance)
int d(int x, int y) {
    int d = (y - x) & 7;
    return d > 4 ? d - 8 : d;
}

int main()
{
    //std::cout << "Hello World!\n";
    //std::vector<int> firstBlockArray, secondBlockArray;
   
    std::ifstream file("input-test");
    //std::ifstream file("input");
    std::stringstream stream;
    std::string Reports, first, second, ReportsStatus;
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
                    //Levels.push_back("\n");
                    Levels.push_back("\n");
                    Levels.push_back(first);
                }
            } else {
                Levels.push_back(Reports);
            }
        }
        file.close();
    }

    std::cout << "--- Do Calc ---" << std::endl;
    int sum = 0;
    ReportsStatus = "\n";

    for (int i = 0; i < Levels.size(); i++) {
        int j = i + 1;
        
        try {
            int thisNumber = std::stoi(Levels[i]);

            if (j != Levels.size()) {
                int theNumberNextToIt = std::stoi(Levels[j]);

                if (d(thisNumber, theNumberNextToIt) > 3) {
                    std::cout << thisNumber << " plus " << theNumberNextToIt << " is unsafe!" << std::endl;
                    ReportsStatus = " - unsafe!\n";
                }
            }
        }
        catch (const std::invalid_argument& e) {
            //std::cout << e.what() << std::endl;
            //std::cout << "That is not a number, so we must be at the end of the report..." << std::endl;

            //if (Levels[i] == "\n") {
            if (Levels[i] == "\n") {
                Levels[i] = ReportsStatus;
                ReportsStatus = "\n";
                //ReportsStatus.clear();
            }

        }
        catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
            
            /* std::cout << "That is not a number, so we must be at the end of the report..." << std::endl;

            //if (Levels[i] == "\n") {
            if (Levels[i] == "B") {
                Levels[i] = ReportsStatus;
                ReportsStatus.clear();
            } */
        }

        
        /*if (Levels[i] == "\n") {
            Levels[i] = ReportsStatus;
            ReportsStatus.clear();
        }
        else if (!std::nan(std::stoi(Levels[i])) && d(std::stoi(Levels[i]), std::stoi(Levels[i + 1])) > 3) {
            std::cout << Levels[i] << " plus " << Levels[i + 1] << "is unsafe!";
            ReportsStatus = "unsafe";
        } (*/
        //} else if(Levels[i] == "\n") {
        //    Levels[i] = ReportsStatus;
        //}

        //ReportsStatus.clear();

        std::cout << Levels[i];
    }
    std::cout << std::endl << "--- Processed Results ---" << std::endl;
    for (int i = 0; i < Levels.size(); i++) {
        std::cout << Levels[i];
    }

    std::cout << std::endl << "--- Answer ---" << std::endl;
    std::cout << sum;
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
