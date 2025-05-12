#include "pnl_calc.h"
#include <fstream>
#include <optional>
#include <cassert>
#include <algorithm>
#include <iostream>

bool PnlCalculator::new_trade_is_same_side_with_existing_position(const Trade& trade) const {
    if (trades_.empty())
        return true;
    return trades_.back().getSide() == trade.getSide();
}

Trade PnlCalculator::pop_latest_trade() {
    assert(!trades_.empty());
    if (method_ == AccountingMethod::FIFO) {
        Trade result (trades_.front());
        trades_.pop_front();
        return result;
    }
    else {
        Trade result (trades_.back());
        trades_.pop_back();
        return result;
    }
}

void PnlCalculator::push_back_latest_trade(const Trade& trade) {
    if (method_ == AccountingMethod::FIFO)
        trades_.push_front(trade);
    else
        trades_.push_back(trade);
}

std::optional<float> PnlCalculator::addTrade(const Trade& trade) {
    if (new_trade_is_same_side_with_existing_position(trade)) {
        // always push the new trade to the back
        // deque is always in time order (from early to late)
        trades_.push_back(trade);
        return std::nullopt;
    }
    else {
        // offset the existing position, and calc PnL
        float cur_pnl = 0.0;
        uint32_t new_pos = trade.getQty();

        while (new_pos > 0 && !trades_.empty()) {
            Trade last_trade = pop_latest_trade();
            int cur_offset_pos = std::min(new_pos, last_trade.getQty());

            float cur_price_diff;
            if (trade.getSide() == TradeSide::SELL)
                cur_price_diff = trade.getPrice() - last_trade.getPrice();
            else
                cur_price_diff = last_trade.getPrice() - trade.getPrice();
            cur_pnl += cur_price_diff * cur_offset_pos;
            new_pos -= cur_offset_pos;

            if (new_pos == 0 && last_trade.getQty() > cur_offset_pos) {
                last_trade.setQty(last_trade.getQty() - cur_offset_pos);
                push_back_latest_trade(last_trade);
            }
        }

        if (new_pos > 0) {
            assert(trades_.empty());
            Trade new_trade = trade;
            new_trade.setQty(new_pos);
            trades_.push_back(new_trade);
        }
        return cur_pnl;
    }
}

void PnlCalculator::debug_print() const {
    std::cout << "=============================debug print ==================\n";
    std::cout << "PnlCalculator: " << getMethodString() << std::endl;
    for (const auto& trade : trades_) {
        std::cout << "     ";
        trade.print();
    }
    std::cout << "\n\n";
}