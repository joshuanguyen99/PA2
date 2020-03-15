// Joshua Nguyen
#include <iostream>
#include <filesystem>
#include <stdio.h>
#include <string>
#include "version.h"

using namespace std;

static double versionNum = 1.2;

int main2(int argc, char* argv[])
{ 
    version v; // version
    v.displayVersion();
    cout << versionNum << endl;
    string directories; // Directory option
    getline(cin, directories);
    string files; // File option
    getline(cin, files);
    string bytes; // Byte option
    getline(cin, bytes);

    string option = argv[1]; // The argument to determine which line to print

    // Determines which line to print based on the option
    if(option == "-d")
    {
        cout << directories << endl;
    }
    else if(option == "-f")
    {
        cout << files << endl;
    }
    else if(option == "-b")
    {
        cout << bytes << endl;
    }
    else
    {
        cout << "Invalid option" << endl;
    }
    return 0;
}
