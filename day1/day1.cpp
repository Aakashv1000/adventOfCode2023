#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype> // For isdigit function

using namespace std;

long part1()
{
    ifstream inputFile("input.txt"); 

    long sum = 0;

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        // Iterate through the line to find the first and last digits
        char firstDigit = '\0';
        char lastDigit = '\0';

        for (char ch : line) {
            if (isdigit(ch)) {
                if (firstDigit == '\0') {
                    firstDigit = ch;
                }
                lastDigit = ch;
            }
        }

        // Check if both digits were found
        if (firstDigit != '\0' && lastDigit != '\0') {
            // Combine digits to form a two-digit number
            long result = (firstDigit - '0') * 10 + (lastDigit - '0');
            sum += result;
        } else {
            cerr << "Unable to find digits in line: " << line << endl;
        }

    }

    return sum;

    inputFile.close();
}

long part2(){
    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    stringstream buffer;
    buffer << fin.rdbuf();
    string data = buffer.str();

    int ans = 0;
    vector<string> nums = {"one", "two", "three", "four", "five",
                                     "six", "seven", "eight", "nine"};

    std::istringstream iss(data);
    std::string line;
    while (std::getline(iss, line)) {
        int first = 0;
        int last = 0;

        for (size_t i = 0; i < line.length(); ++i) {
            int cur = 0;

            char c = line[i];
            if (isdigit(c)) {
                cur = c - '0';
            }

            for (size_t j = 0; j < nums.size(); ++j) {
                if (line.compare(i, nums[j].length(), nums[j]) == 0) {
                    cur = j + 1;
                    break;
                }
            }

            if (cur != 0) {
                if (first == 0) {
                    first = cur;
                }
                last = cur;
            }
        }

        ans += first * 10 + last;
    }

    return ans;
}

int main() {
    

    cout<<"the final sum for part 1 is " << part1();
    cout<<"the final sum for part 2 is " << part2();
    return 0;
}




