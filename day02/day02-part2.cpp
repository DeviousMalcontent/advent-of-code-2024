// day02-part2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

int main()
{
    std::ifstream file("input-test");
    //std::ifstream file("input");
    std::stringstream stream;
    std::string Reports, first, second, ReportsStatus, ReportsDirection;
    std::vector<std::string> Levels;
    bool DirectionChangedFlag = false;

    if (file) {
        stream << file.rdbuf();
        //std::cout << stream.str();

        while (std::getline(stream, Reports, ' ')) {
            std::string::size_type pos = Reports.find('\n');
            if (Reports.npos != pos) {
                first = Reports.substr(pos + 1);
                second = Reports.substr(0, pos);
                if (first.empty() && !second.empty()) {
                    Levels.push_back(second);
                }
                else {
                    Levels.push_back(second);
                    Levels.push_back("\n");
                    Levels.push_back(first);
                }
            }
            else {
                Levels.push_back(Reports);
            }

            if (stream.eof()) {
                Levels.push_back("\n");
            }
        }
        file.close();
    }

    std::cout << "--- Do Calc ---" << std::endl;
    ReportsStatus = "\n";
    ReportsDirection = "unkown";
    int NumberOfBadLevelsPerReport = 0;
    int thisNumber = 0;
    int j = 0;
    int theNumberNextToIt = 0;

    for (int i = 0; i < Levels.size(); i++) {
        j = i + 1;

        try {
            thisNumber = std::stoi(Levels[i]);

            if (j != Levels.size()) {
                theNumberNextToIt = std::stoi(Levels[j]);

                // Check for any two adjacent levels differ by at least one and at most three.
                if (std::abs(thisNumber - theNumberNextToIt) > 3 || std::abs(thisNumber - theNumberNextToIt) < 1) {
                    std::cout << " " << thisNumber << " with " << theNumberNextToIt << " has a delta of " << std::abs(thisNumber - theNumberNextToIt) << " is unsafe!" << std::endl;
                    ReportsStatus = NumberOfBadLevelsPerReport + "- unsafe!\n";
                    NumberOfBadLevelsPerReport++;
                }

                // Check for the levels are either all increasing or all decreasing. - This section sets the flag.
                if (i > 0 && i < Levels.size() && ReportsDirection == "unkown") {
                    if (thisNumber > theNumberNextToIt) {
                        ReportsDirection = "decreasing";
                    }
                    else if (thisNumber < theNumberNextToIt) {
                        ReportsDirection = "increasing";
                    }
                }
                else if (i > 0 && i < Levels.size() && ReportsDirection == "decreasing") {
                    if (thisNumber > theNumberNextToIt) {
                        ReportsDirection = "decreasing";
                    }
                    else if (thisNumber < theNumberNextToIt) {
                        ReportsDirection = "increasing";
                        DirectionChangedFlag = true;
                        NumberOfBadLevelsPerReport++;
                    }
                }
                else if (i > 0 && i < Levels.size() && ReportsDirection == "increasing") {
                    if (thisNumber > theNumberNextToIt) {
                        ReportsDirection = "decreasing";
                        DirectionChangedFlag = true;
                        NumberOfBadLevelsPerReport++;
                    }
                    else if (thisNumber < theNumberNextToIt) {
                        ReportsDirection = "increasing";
                    }
                }

                // Check for the levels are either all increasing or all decreasing. - This section triggers when the flag is set.
                if (DirectionChangedFlag == true)
                {
                    ReportsStatus = " - unsafe!\n";
                    NumberOfBadLevelsPerReport++;
                }

            }
        }
        catch (const std::invalid_argument& e) {
            //std::cout << e.what() << std::endl;
            //std::cout << "That is not a number, so we must be at the end of the report..." << std::endl;

            if (Levels[i] == "\n") {
                /*if (NumberOfBadLevelsPerReport <= 1)
                {
                    ReportsStatus = "\n";
                    std::cout << "NumberOfBadLevelsPerReport: " << NumberOfBadLevelsPerReport << std::endl;
                } */
                
                Levels[i] = ReportsStatus;
                ReportsStatus = "\n";
                DirectionChangedFlag = false;
                ReportsDirection = "unkown";
                NumberOfBadLevelsPerReport = 0;
            }

        }
        catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        }

        std::cout << Levels[i];
    }

    std::cout << std::endl << "--- Processed Results ---" << std::endl;
    int sum = 0;
    for (int i = 0; i < Levels.size(); i++) {
        std::cout << Levels[i];

        if (Levels[i] == "\n") {
            sum++;
        }
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
