#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<std::string> parseInputValues(std::string filepath) {
    std::vector<std::string> values;
    std::ifstream inputFile;

    try {
        inputFile.open(filepath);
        
        std::string line;
        while (std::getline(inputFile, line)) {
            values.push_back(line);
        }
    } catch(std::ifstream::failure e) {
        std::cout  << "Error reading input file.  " << e.what();
    }

    return values;
}

int part1(const std::vector<std::string> values) {
    int result = 0;

    for (auto passwordLine : values) {
        std::stringstream passwordStream(passwordLine);
        std::string segment;
        std::vector<std::string> seglist;
        while(passwordStream >> segment) { seglist.push_back(segment); }
        std::stringstream countStream(seglist[0]);
        std::string segmentCount;
        std::vector<std::string> segCountlist;
        while(std::getline(countStream, segment, '-')) { segCountlist.push_back(segment); }
        std::stringstream low(segCountlist[0]);
        std::stringstream high(segCountlist[1]);
        int lowCount = 0;
        int highCount = 0;
        low >> lowCount;
        high >> highCount;
        
        std::string letter(seglist[1].substr(0,1));
        std::string password = seglist[2].substr(0,1000);
    
        std::string s = passwordLine;
        size_t charCount = std::count(s.begin(), s.end(), *letter.c_str()) - 1;

        if(charCount >= lowCount && charCount <= highCount) {
            result++;
        }
    }

    return result;
}

int part2(const std::vector<std::string> values) {
    int result = 0;
    
    for (auto passwordLine : values) {
        std::stringstream passwordStream(passwordLine);
        std::string segment;
        std::vector<std::string> seglist;
        while(passwordStream >> segment) { seglist.push_back(segment); }
        std::stringstream countStream(seglist[0]);
        std::string segmentCount;
        std::vector<std::string> segCountlist;
        while(std::getline(countStream, segment, '-')) { segCountlist.push_back(segment); }
        std::stringstream low(segCountlist[0]);
        std::stringstream high(segCountlist[1]);
        int lowCount = 0;
        int highCount = 0;
        low >> lowCount;
        high >> highCount;
        
        std::string letter(seglist[1].substr(0,1));
        std::string password = seglist[2].substr(0,1000);

        bool same = password[lowCount - 1] == password[highCount - 1];
        
        if(!same && (password[lowCount - 1] == *letter.c_str() || password[highCount - 1] == *letter.c_str())) {
            result++;
        }
    }

    return result;
}

int main(int argc, const char * argv[]) {
    auto inputValues = parseInputValues("input.txt");
    
    int part1Result = part1(inputValues);
    std::cout << "Part 1: " << part1Result << std::endl;

    int part2Result = part2(inputValues);
    std::cout << "Part 2: " << part2Result << std::endl;

    return 0;
}

