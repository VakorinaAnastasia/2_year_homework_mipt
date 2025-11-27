#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>

int sumFromString(const std::string& input)
{
    if (input.empty() || input.front() != '[' || input.back() != ']') {
        throw std::invalid_argument("Invalid string format");
    }
    
    std::string content = input.substr(1, input.length() - 2);
    
    if (content.empty()) {
        return 0;
    }
    
    std::stringstream ss(content);
    std::string token;
    int sum = 0;
    
    while (std::getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(' '));
        token.erase(token.find_last_not_of(' ') + 1);
        
        if (!token.empty()) {
            sum += std::stoi(token);
        }
    }
    
    return sum;
}

int main()
{
    std::string testCases[] = {
        "[10, 20, 30, 40, 50]",
        "[4, 8, 15, 16, 23, 42]",
        "[20]",
        "[]"
    };
    
    for (const auto& testCase : testCases) {
        int result = sumFromString(testCase);
        std::cout << result << std::endl;
    }
}