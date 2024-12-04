// day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

/*
The first block of this code reads in our input file and stores it in a buffer then casts it to a string stream, 
using a while loop we iterate over the strings stream and split each number up using a space as the delimiter, 
we then must check every string, if we find the carriage return line, we use this to determine that the report has finished.

We then load each element into the array, there's a little bit of fuckery here with some of the logic because the carriage returned technically goes over two number spaces, 
so we need to split them up and separate them, I have purposefully put them in reverse order just to fuck with you.

If we hit the end of the line for the file, we will also need to stick a carriage return into the array.

We close off the file handler and then we have an array that we can process.

In our do calculation part, we have a few variables we need to set, report status, and a direction flag which is just a string, 
we are only checking for three conditions, unknown, descending and increasing, and we use a Boolean as the actual flag once set to determine if the report is safe or unsafe.

Now we iterate over each member of the array, the first block of code checks for adjacent levels if they differ by at least one, 
and more than three, again we use the absolute value function, and we find the report as unsafe if this condition is true.

The next logic block determines the state of the report, if it is descending or increasing and the final block tags the report as unsafe if the direction changed at all.

Since we're using an array of strings, rather than use an array of integers, 
we need to determine if we are parsing a number or if we have hit a line break flag, to do this we use a try catch, and process some of the logic in the catch block, 
if we don't hit a number we assume it's a line break or end of report flag.

There are more elegant ways to do this, but I don't care.

So, if we hit our end of line flag, we will update our end of line flag string in the array to match the report status, 
if the report says it is marked as unsafe the report will be marked as unsafe if the report status flag is not touched at all during this process, it will be skipped.

Now we've hit the process result section, if a report is unsafe it will be flagged as unsafe and if not it'll be left alone, 
with this knowledge we can iterate over the array one final time and count the number of safe reports by counting the number of carriage returns, 
and not the ones that are marked with the unsafe lag, once we summarize this we have our answer.
*/

int main()
{
    //std::ifstream file("input-test");
    std::ifstream file("input");
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

            if (stream.eof()) {
                Levels.push_back("\n");
            }
        }
        file.close();
    }

    std::cout << "--- Do Calc ---" << std::endl;
    ReportsStatus = "\n";
    ReportsDirection = "unkown";

    for (int i = 0; i < Levels.size(); i++) {
        int j = i + 1;
        
        try {
            int thisNumber = std::stoi(Levels[i]);

            if (j != Levels.size()) {
                int theNumberNextToIt = std::stoi(Levels[j]);

                // Check for any two adjacent levels differ by at least one and at most three.
                if (std::abs(thisNumber - theNumberNextToIt) > 3 || std::abs(thisNumber - theNumberNextToIt) < 1) {
                    std::cout << " " << thisNumber << " with " << theNumberNextToIt << " has a delta of " << std::abs(thisNumber - theNumberNextToIt) << " is unsafe!" << std::endl;
                    ReportsStatus = " - unsafe!\n";
                }

                // Check for the levels are either all increasing or all decreasing. - This section sets the flag.
                if (i > 0 && i < Levels.size() && ReportsDirection == "unkown") {
                    if (thisNumber > theNumberNextToIt) {
                        ReportsDirection = "decreasing";
                    } else if (thisNumber < theNumberNextToIt) {
                        ReportsDirection = "increasing";
                    } 
                } else if (i > 0 && i < Levels.size() && ReportsDirection == "decreasing") {
                    if (thisNumber > theNumberNextToIt) {
                        ReportsDirection = "decreasing";
                    }
                    else if (thisNumber < theNumberNextToIt) {
                        ReportsDirection = "increasing";
                        DirectionChangedFlag = true;
                    }
                } else if (i > 0 && i < Levels.size() && ReportsDirection == "increasing") {
                    if (thisNumber > theNumberNextToIt) {
                        ReportsDirection = "decreasing";
                        DirectionChangedFlag = true;
                    }
                    else if (thisNumber < theNumberNextToIt) {
                        ReportsDirection = "increasing";
                    }
                }

                // Check for the levels are either all increasing or all decreasing. - This section triggers when the flag is set.
                if (DirectionChangedFlag == true)
                {
                    ReportsStatus = " - unsafe!\n";
                }

            }
        }
        catch (const std::invalid_argument& e) {
            //std::cout << e.what() << std::endl;
            //std::cout << "That is not a number, so we must be at the end of the report..." << std::endl;

            if (Levels[i] == "\n") {
                Levels[i] = ReportsStatus;
                ReportsStatus = "\n";
                DirectionChangedFlag = false;
                ReportsDirection = "unkown";
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
