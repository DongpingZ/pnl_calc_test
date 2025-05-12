#include <gtest/gtest.h>
#include "trade.h"

class TradeTest : public ::testing::Test {
protected:
    const uint64_t timestamp = 1234567890;
    const std::string symbol = "AAPL";
    const TradeSide side = TradeSide::BUY;
    const double price = 150.50;
    const uint32_t qty = 100;
};

// Test regular constructor
TEST_F(TradeTest, ConstructorTest) {
    Trade trade(timestamp, symbol, side, price, qty);
    
    EXPECT_EQ(trade.getTimestamp(), timestamp);
    EXPECT_EQ(trade.getSymbol(), symbol);
    EXPECT_EQ(trade.getSide(), side);
    EXPECT_EQ(trade.getPrice(), price);
    EXPECT_EQ(trade.getQty(), qty);
}

// Test copy constructor
TEST_F(TradeTest, CopyConstructorTest) {
    Trade original(timestamp, symbol, side, price, qty);
    Trade copy(original);
    
    EXPECT_EQ(copy.getTimestamp(), original.getTimestamp());
    EXPECT_EQ(copy.getSymbol(), original.getSymbol());
    EXPECT_EQ(copy.getSide(), original.getSide());
    EXPECT_EQ(copy.getPrice(), original.getPrice());
    EXPECT_EQ(copy.getQty(), original.getQty());
}

// Test assignment operator
TEST_F(TradeTest, AssignmentOperatorTest) {
    Trade original(timestamp, symbol, side, price, qty);
    Trade assigned(1, "TEST", TradeSide::SELL, 1.0, 1);
    
    assigned = original;
    
    EXPECT_EQ(assigned.getTimestamp(), original.getTimestamp());
    EXPECT_EQ(assigned.getSymbol(), original.getSymbol());
    EXPECT_EQ(assigned.getSide(), original.getSide());
    EXPECT_EQ(assigned.getPrice(), original.getPrice());
    EXPECT_EQ(assigned.getQty(), original.getQty());
}

// Test string constructor
TEST_F(TradeTest, StringConstructorTest) {
    std::string tradeStr = "1234567890,AAPL,B,150.50,100";
    Trade trade(tradeStr);
    
    EXPECT_EQ(trade.getTimestamp(), timestamp);
    EXPECT_EQ(trade.getSymbol(), symbol);
    EXPECT_EQ(trade.getSide(), TradeSide::BUY);
    EXPECT_EQ(trade.getPrice(), price);
    EXPECT_EQ(trade.getQty(), qty);
}

// Test string constructor with SELL side
TEST_F(TradeTest, StringConstructorSellTest) {
    std::string tradeStr = "1234567890,AAPL,S,150.50,100";
    Trade trade(tradeStr);
    
    EXPECT_EQ(trade.getSide(), TradeSide::SELL);
}

// Test setter
TEST_F(TradeTest, SetQtyTest) {
    Trade trade(timestamp, symbol, side, price, qty);
    uint32_t newQty = 200;
    
    trade.setQty(newQty);
    EXPECT_EQ(trade.getQty(), newQty);
}