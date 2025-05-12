#include "pnl_calc.h"
#include <iostream>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    AccountingMethod method = AccountingMethod::FIFO;
    PnlCalculator calculator(method);

    std::cout << "Hello, World!" << std::endl;

    return 0;
}