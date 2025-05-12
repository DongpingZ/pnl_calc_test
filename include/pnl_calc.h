#ifndef PNL_CALC_H
#define PNL_CALC_H

#include "trade.h"
#include <deque>
#include <string>
#include <optional>
#include <vector>
#include <utility>
#include <stdexcept>

enum class AccountingMethod {
    FIFO,
    LIFO
};

class PnlCalculator {
public:
    explicit PnlCalculator(AccountingMethod method) : method_(method) {
        if (method != AccountingMethod::FIFO && method != AccountingMethod::LIFO)
            throw std::invalid_argument("PnlCalculator must be initialized with either FIFO or LIFO");
    }
    
    AccountingMethod getMethod() const { return method_; }
    
    const char* getMethodString() const {
        return method_ == AccountingMethod::FIFO ? "FIFO" : "LIFO";
    }

    std::optional<float> addTrade(const Trade& trade);
    Trade pop_latest_trade();
    void push_back_latest_trade(const Trade& trade);
    bool new_trade_is_same_side_with_existing_position(const Trade& trade) const;

    void debug_print() const;
    
private:
    AccountingMethod method_;
    std::deque<Trade> trades_;
    int net_position_ = 0;
};

#endif // PNL_CALC_H