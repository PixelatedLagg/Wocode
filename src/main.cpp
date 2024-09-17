#include "stdio.h"
#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    std::ifstream file("test.txt");
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    
    file.close();
    for (const auto& modifiedLine : lines) {
    std::cout << modifiedLine << std::endl;
    }
    return 0;
}