// Joshua Nguyen
#include <iostream>
#include <filesystem>
#include <stdio.h>
#include "version.h"

using namespace std;

static double versionNum = 1.2;

int main(int argc, char* argv[])
{   
    version v; // version
    v.displayVersion();
    cout << versionNum << endl;
    const std::filesystem::path directoryPath = argv[1];
    int directoryCounter = 0; // Directory counter
    int fileCounter = 0; // File counter
    int byteTotal = 0; // Total amount of bytes
    string pathName = directoryPath.relative_path();
    // g++-8 -std=c++17 filecnt.cpp -o filecnt.out -lstdc++fs
    
    using recursive_directory_iterator = std::filesystem::recursive_directory_iterator; 

    // Iterates through the path
    for (const auto& dirEntry : recursive_directory_iterator(directoryPath))
    {
        // If it is a directory count goes up by one
        if(is_directory(dirEntry))
        {
            directoryCounter++;
        }
        // If it is a regular file and not a symbolic link, count goes up by one
        else if(is_regular_file(dirEntry))
        {
            if(is_symlink(dirEntry))
            {
                continue;
            }
            fileCounter++;

            // Number of bytes goes up
            int fileBytes = file_size(dirEntry);
            byteTotal += fileBytes;
        }
        
        
    }

    // Prints out everything
    cout << "The total number of directories in directory /" << pathName << " is: " << directoryCounter << endl;
    cout << "The total number of files in the directory /" << pathName << " is: " << fileCounter << endl;
    cout << "The total number of bytes occupied by all files in directory /" << pathName << " is: " << byteTotal << endl;
    return 0;
}
