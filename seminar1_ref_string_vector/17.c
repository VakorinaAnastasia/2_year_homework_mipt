#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::vector<std::size_t>> calculate_word_lengths(const std::string& filename)
{
    std::vector<std::vector<std::size_t>> result;
    std::ifstream file(filename);
    
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::size_t> lineLengths;
        std::istringstream iss(line);
        std::string word;
        
        while (iss >> word)
        {
            lineLengths.push_back(word.length());
        }
        
        if (!lineLengths.empty())
        {
            result.push_back(lineLengths);
        }
    }
    
    file.close();
    return result;
}

void test_calculate_word_lengths()
{
    std::ofstream testFile("test.txt");
    testFile << "one two three\n";
    testFile << "hello\n";
    testFile << "axolotl bison cat dog eagle\n";
    testFile.close();
    
    auto result = calculate_word_lengths("test.txt");
    
    for (const auto& line : result)
    {
        std::cout << "{";
        for (std::size_t i = 0; i < line.size(); i++)
        {
            std::cout << line[i];
            if (i < line.size() - 1)
                std::cout << ", ";
        }
        std::cout << "}" << std::endl;
    }
}

int main()
{
    test_calculate_word_lengths();
}