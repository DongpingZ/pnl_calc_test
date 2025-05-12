#include "pnl_calc.h"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc != 3){
        std::cout << "Error! Usage: " << argv[0] << " <input_file> <method>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    std::string methodStr = argv[2];
    
    AccountingMethod method;
    if (methodStr == "fifo")
        method = AccountingMethod::FIFO;
    else if (methodStr == "lifo")
        method = AccountingMethod::LIFO;
    else {
        std::cout << "Error: Accounting method must be either 'fifo' or 'lifo'" << std::endl;
        return 1;
    }

    // std::map<std::string, PnlCalculator<method>> calculator;

    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << inputFile << std::endl;
        return 1;
    }

    std::string line;

    // Skip header line
    std::getline(file, line);

    // Read and print each line
    while (std::getline(file, line)) {
        std::cout << line << std::endl;  // For now, just print each line
    }

    file.close();
    return 0;
}