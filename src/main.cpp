#include "stdio.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

void WriteInColor(int color, std::string text)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO cbInfo;
    GetConsoleScreenBufferInfo(hConsole, &cbInfo);
    int originalColor = cbInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, color);
    std::cout << text; 
    SetConsoleTextAttribute(hConsole, originalColor);
}

int main()
{
    WriteInColor(16, "Wocode");

    std::ifstream file("test.txt");
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    
    file.close();
    for (const auto& modifiedLine : lines)
    {
        std::cout << modifiedLine << std::endl;
    }
    return 0;
}

/*
1 - ocean blue
2 - green
3 - light blue
4 - light red
5 - magenta
6 - yellow
7 - white
8 - gray
9 - darek blue
10 - light green
11 - lighter blue
12 - dark red
16 - white on blue bg
64 - white on red bg
82 - white on magenta bg
240 - black on white bg
*/