#include "pnl_calc.h"
#include <optional>
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

    PnlCalculator calculator(method);

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
        std::cout << line << std::endl;
        Trade trade(line);
        trade.print();
        auto pnl = calculator.addTrade(trade);
        if (pnl)
            std::cout << "PnL: " << *pnl << std::endl;
    }

    file.close();
    return 0;
}