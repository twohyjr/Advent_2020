#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<std::vector<char>> readInput(std::string filepath, int columnCount) {
    std::ifstream inputFile;
    try {
        inputFile.open(filepath);
    } catch(std::ifstream::failure e) {
        std::cout << "ERROR::INPUT_FILE::FILE_NOT_SUCCESFULLY_READ::" << e.what() << std::endl;
    }
    
    std::vector<std::vector<char>> rowValues;
    
    std::string line;
    // Read the line of the file
    while(getline(inputFile, line)) {
        std::vector<char> columnValues;
        // Read over however many colums we want into the array n times
        for(int i = 0; i < columnCount; i++) {
            for(char character : line) {
                columnValues.push_back(character);
            }
        }
        rowValues.push_back(columnValues);
    }

    return rowValues;
}

int processTreeHitCount(std::vector<std::vector<char>> values, int rise, int run) {
    int x = 0;
    int y = 0;
    
    int height = (int)values.size();
    int currentLevel = 0;
    
    int treeHitCount = 0;
    while(y < height) {
        if(values[y][x] == '#') {
            treeHitCount++;
        }
        
        y += rise;
        x += run;
        currentLevel++;
    }
    return treeHitCount;
}

int part1(std::vector<std::vector<char>> values) {
    int treeHitCount = processTreeHitCount(values, 1, 3);
    return treeHitCount;
}

unsigned long part2(std::vector<std::vector<char>> values) {
    unsigned long result = 0;

    unsigned long treeCount1 = processTreeHitCount(values, 1, 1);
    unsigned long treeCount2 = processTreeHitCount(values, 1, 3);
    unsigned long treeCount3 = processTreeHitCount(values, 1, 5);
    unsigned long treeCount4 = processTreeHitCount(values, 1, 7);
    unsigned long treeCount5 = processTreeHitCount(values, 2, 1);
    
    result = treeCount1 * treeCount2 * treeCount3 * treeCount4 * treeCount5;

    return result;
}

int main(int argc, const char * argv[]) {
    auto inputValues = readInput("input.txt", 100);
    
    int part1Result = part1(inputValues);
    std::cout << "Part 1: " << part1Result << std::endl;
    
    unsigned long part2Result = part2(inputValues);
    std::cout << "Part 2: " << part2Result << std::endl;

    return 0;
}
