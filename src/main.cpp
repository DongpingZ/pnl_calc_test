#include "pnl_calc.h"
#include <map>
#include <optional>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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

    std::map<std::string, PnlCalculator> calculator;

    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cout << "Error: Could not open file " << inputFile << std::endl;
        return 1;
    }

    std::string line;

    // Skip header line
    std::getline(file, line);
    std::cout << "TIMESTAMP,SYMBOL,PNL" << std::endl;

    while (std::getline(file, line)) {
        Trade trade(line);
        const std::string& symbol = trade.getSymbol();
        if (calculator.find(symbol) == calculator.end())
            calculator.emplace(symbol, PnlCalculator(method));

        PnlCalculator& cur_calculator = calculator.at(symbol);

        // trade.print(); // just for check trade info is correct
        std::optional<float> pnl = cur_calculator.addTrade(trade);
        if (pnl.has_value()) {
            std::cout << trade.getTimestamp() << ',' << trade.getSymbol() << "," << std::fixed << std::setprecision(2) << *pnl << std::endl;
        }

        // debug print
        // cur_calculator.debug_print();
    }

    file.close();
    return 0;
}