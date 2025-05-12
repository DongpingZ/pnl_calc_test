#include <gtest/gtest.h>
#include "pnl_calc.h"

TEST(PnlCalculatorTest, ExampleInputFIFO) {
    PnlCalculator calc(AccountingMethod::FIFO);
    EXPECT_EQ(calc.addTrade(Trade(101, "TFS", TradeSide::BUY, 11.00, 15)), std::nullopt);
    EXPECT_EQ(calc.addTrade(Trade(102, "TFS", TradeSide::BUY, 12.50, 15)), std::nullopt);
    EXPECT_EQ(calc.addTrade(Trade(103, "TFS", TradeSide::SELL, 13.00, 20)), 32.50f);
    EXPECT_EQ(calc.addTrade(Trade(104, "TFS", TradeSide::SELL, 12.75, 10)), 2.50f);
}
