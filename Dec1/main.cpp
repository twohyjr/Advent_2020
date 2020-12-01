#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<int> readInputValues(std::string filepath) {
    std::vector<int> values;
    std::ifstream inputFile;
    
    try {
        inputFile.open(filepath);
        
        int a;
        while(inputFile >> a) {
            values.push_back(a);
        }
    } catch(std::ifstream::failure e) {
        std::cout  << "Error reading input file.  " << e.what();
    }
    
    return values;
}

int part1(const std::vector<int> values) {
    int result = 0;
    for(int i = 0; i < values.size(); i++) {
        int val1 = values[i];
        for(int j = i + 1; j < values.size(); j++) {
            int val2 = values[j];
            if(val1 + val2 == 2020) {
                return val1 * val2;
            }
        }
    }
    return result;
}

int part2(const std::vector<int> values) {
    int result = 0;
    for(int i = 0; i < values.size(); i++) {
        int val1 = values[i];
        for(int j = i + 1; j < values.size(); j++) {
            int val2 = values[j];
            for(int k = i + 1; k < values.size(); k++) {
                int val3 = values[k];
                if(val1 + val2 + val3 == 2020) {
                    return val1 * val2 * val3;
                }
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    auto inputValues = readInputValues("input_final");
    
    int part1Result = part1(inputValues);
    std::cout << "Part 1: " << part1Result << std::endl;
    
    int part2Result = part2(inputValues);
    std::cout << "Part 2: " << part2Result << std::endl;
    
    return 0;
}
