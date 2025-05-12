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

template<AccountingMethod Method>
class PnlCalculator {
    static_assert(Method == AccountingMethod::FIFO || Method == AccountingMethod::LIFO,
                "PnlCalculator must be instantiated with either FIFO or LIFO");
public:
    PnlCalculator() = default;
    
    static constexpr AccountingMethod getMethod() { return Method; }
    
    static constexpr const char* getMethodString() {
        if constexpr (Method == AccountingMethod::FIFO)
            return "FIFO";
        else
            return "LIFO";
    }
    
private:
    std::deque<Trade> trades_;
};

#endif // PNL_CALC_H