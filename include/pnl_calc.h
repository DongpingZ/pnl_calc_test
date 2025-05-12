#ifndef PNL_CALC_H
#define PNL_CALC_H

#include "trade.h"
#include <deque>
#include <string>
#include <vector>
#include <utility>

enum class AccountingMethod {
    FIFO,
    LIFO
};

class PnlCalculator {
public:
    explicit PnlCalculator(AccountingMethod method = AccountingMethod::FIFO);
    
private:
    AccountingMethod method_;
    std::deque<Trade> trades_;
};

#endif // PNL_CALC_H